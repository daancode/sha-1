/*
	Copyright (c) 2015, Damian Barczynski <daan.net@wp.eu> All rights reserved.

	Permission to use, copy, modify, and/or distribute this software for any purpose
	with or without fee is hereby granted, provided that the above copyright notice
	and this permission notice appear in all copies.

	THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD
	TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN
	NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
	DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
	IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
	CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
#ifndef __SHA1_HPP__
#define __SHA1_HPP__

#include <array>
#include <vector>

class SHA1
{
	typedef unsigned int uint;
	typedef unsigned char byte;
	typedef const std::string cstr;

	std::vector<std::vector<byte>> blocks;

public:
	/*
		\brief Convert message into const char* and transfer it to second ctor.
		\param message_ string which will be hashed
	*/
	SHA1(cstr& message_);

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
	cstr generate();

	/*
		\brief Perform left circular shift.
		\param value_ 32 bits which will be shifted
		\param shift_ number of cycles
	*/
	inline uint rotl(const uint& value_, const uint& shift_)
	{
		return ((value_ << shift_) | (value_ >> (32 - shift_)));
	}
};

#endif // __SHA1_HPP__