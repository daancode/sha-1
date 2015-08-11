### SHA-1 [![Build Status](https://travis-ci.org/da-an/SHA-1.svg?branch=master)](https://travis-ci.org/da-an/SHA-1)
SHA-1 hash generator class written in c++ programming language. Licensed under the terms and conditions of the [ISC](https://en.wikipedia.org/wiki/ISC_license).
#### Usage example
```cpp
#include <iostream>
#include "source\SHA1.hpp"

// SHA1(string).generate() - return hash value as string

int main()
{
	std::cout << SHA1("example string").generate() << std::endl;
	std::cin.get();
}
```
