## SHA-1 [![Build Status](https://travis-ci.org/da-an/SHA-1.svg?branch=master)](https://travis-ci.org/da-an/SHA-1)
Secure hash algorithm 1 class written in C++ programming language.
 - requires compiler support for C++11

#### Usage example
```cpp
#include <iostream>
#include "source\SHA1.hpp"

int main()
{
	std::string hash = SHA1("example string").generate();
	std::cout << hash << std::endl;
	std::cin.get();
}
```
#### License
```
Copyright (c) 2015, Damian Barczyński <daan.net@wp.eu>

Permission to use, copy, modify, and/or distribute this software for any purpose
with or without fee is hereby granted, provided that the above copyright notice
and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD
TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN
NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
```
