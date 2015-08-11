#include "../source/SHA1.hpp"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void test(const string& text_, const string& output_)
{
	static int id_ = 0;
	cout << "[Test " << std::setw(2) << ++id_ << "] status : " <<
		(SHA1(text_).generate() == output_ ? "passed" : "failed") << endl;
}

int main()
{
	test("", "da39a3ee5e6b4b0d3255bfef95601890afd80709");
	test("abc", "a9993e364706816aba3e25717850c26c9cd0d89d");
	test("j._%;.*/L5T=Qu9S", "7848bff1b02578fb2e8d76d16f4a4ca20dbaf0bb");
	test(".N%y'5gA)Za5%rm]", "573e06468d5c6812036c613c225dfe83c17a5516");
	test("y?wiN*,e8A69H!2", "b312188d8cc320318551fd85d9cfe85321c0516f");
	test("X/;ht+0EcUis4i1a~'1:<l'0``A9Ty", "755dbe3933c7ad409e3225158bf49ee62442f4c8");
	test("9s7l3I_QUGtFE3h9r8Rv{toKW61~lH", "9f7bea78c87ac8fd3a21e754aa76988033e94a69");
	test("12JW42yxM4", "770e664689231dccc1601732079572d1ae4f4af3");
	test("&|WC){Cc;q91(&exE8y.SP[7uZ0nZ)", "b03a57599efce5a004396c7fccb0b9d11c4bb5ac");
	test("#1BtyDG(bkoQBd9p:5.y]b.V-D'+>5", "e9d0fb640509c415546a4a2cad96357d353a921a");

	cin.get();
}
