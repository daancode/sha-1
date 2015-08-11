#include "source\SHA1.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string text = "test message";
	cout << "SHA-1('" << text << "') : " << SHA1(text).generate() << endl;
}
