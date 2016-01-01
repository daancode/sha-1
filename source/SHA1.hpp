/*
    Copyright (c) 2015, Damian Barczynski <daan.net@wp.eu>
    Following tool is licensed under the terms and conditions of the MIT license.
    For more information see https://opensource.org/licenses/MIT.
*/
#ifndef __SHA1_HPP__
#define __SHA1_HPP__

#include <array>
#include <vector>

class SHA1
{
    typedef unsigned int uint;
    typedef unsigned char byte;
    typedef std::string string;

    std::vector<std::vector<byte>> blocks;

public:
    /*
        \brief Convert message into const char* and transfer it to second ctor.
        \param message_ string which will be hashed
    */
    SHA1(const string& message_);

    /*
        \brief Prepare data block and cut it for 512-bit length chunks.
        \param data_ pointer to data which are located in memory
        \param size_ size of given data in bytes
    */
    SHA1(const char* data_, uint size_);

    /*
        \brief Generate hash values from a single 512-bit block.
        \param block_ pointer to first byte of 512-bit block
        \param hash_ hash table with current hash values
    */
    void transform(byte* block_, std::array<uint, 5>& hash_);

    /*
        \brief Transform all of blocks which are created by ctor.
        \return hash value converted to string
    */
    const string generate();

    /*
        \brief Perform left circular shift.
        \param value_ 32 bits which will be shifted
        \param shift_ number of cycles
    */
    uint rotl(const uint& value_, const uint& shift_)
    {
        return ((value_ << shift_) | (value_ >> (32 - shift_)));
    }
};

#endif // __SHA1_HPP__
