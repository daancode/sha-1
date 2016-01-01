#include "SHA1.hpp"
#include <sstream>
#include <iomanip>

SHA1::SHA1(const string& message_) 
    : SHA1(message_.data(), message_.size()) {}

SHA1::SHA1(const char* data_, uint size_)
{
    std::vector<byte> data;

    for (uint i = 0; i < size_; ++i) {
        data.push_back(data_[i]);
    }

    data.push_back(0x80);
    while ((data.size() * 8) % 512 != 448) data.push_back(0);

    long long size = size_ * 8;
    for (int i = 0, offset = 56; i < 8; ++i, offset -= 8) {
        data.push_back((size >> offset) & 0xff);
    }

    blocks.resize(data.size() / 64);

    for (auto& block : blocks) {
        block.resize(64);
        std::move(data.begin(), data.begin() + 64, block.begin());
        data.erase(data.begin(), data.begin() + 64);
    }
}

void SHA1::transform(byte* block_, std::array<uint, 5>& hash_)
{
    uint f;
    std::array<uint, 5> h = hash_;
    std::array<uint, 80> word;

    for (int i = 0; i < 16; ++i) {
        word[i] = 
            (block_[i * 4 + 0] << 24) | (block_[i * 4 + 1] << 16) |
            (block_[i * 4 + 2] << 8) | (block_[i * 4 + 3] << 0);
    }

    for (int i = 16; i < 80; ++i) {
        word[i] = rotl((word[i - 3] ^ word[i - 8] ^ word[i - 14] ^ word[i - 16]), 1);
    }

    for (int run = 0; run < 80; ++run) {
        if (run <= 19)
            f = ((h[1] & h[2]) | ((~h[1]) & h[3])) + 0x5a827999;
        else if (run <= 39)
            f = (h[1] ^ h[2] ^ h[3]) + 0x6ed9eba1;
        else if (run <= 59)
            f = ((h[1] & h[2]) | (h[1] & h[3]) | (h[2] & h[3])) + 0x8f1bbcdc;
        else
            f = (h[1] ^ h[2] ^ h[3]) + 0xca62c1d6;

        f += rotl(h[0], 5) + h[4] + word[run];
        h[4] = h[3];
        h[3] = h[2];
        h[2] = rotl(h[1], 30);
        h[1] = h[0];
        h[0] = f;
    }

    for (uint i = 0; i < hash_.size(); ++i) {
        hash_[i] += h[i];
    }
}

const std::string SHA1::generate()
{
    std::array<uint, 5 > hashTable =
        { 0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476, 0xc3d2e1f0 };

    for (auto& block : blocks) {
        transform(block.data(), hashTable);
    }

    std::ostringstream string;
    for (auto& hash : hashTable) {
        string << std::hex << std::setfill('0') << std::setw(8) << hash;
    }

    return string.str();
}