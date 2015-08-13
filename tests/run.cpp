#include "../source/SHA1.hpp"
#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

void checkout(const string& text_, const string& output_)
{
	static int id_ = 0;
	cout << "[Test " << setw(2) << ++id_ << "] status : " <<
		(SHA1(text_).generate() == output_ ? "passed" : "failed") << endl;
}

int main()
{
	map<string, string> tests;

	tests.insert(make_pair("",		   "da39a3ee5e6b4b0d3255bfef95601890afd80709"));
	tests.insert(make_pair("abc",	   "a9993e364706816aba3e25717850c26c9cd0d89d"));
	tests.insert(make_pair("coarsely", "5fc6ddfb7ce1e7eed490f49bc1bdc68a951c3976"));
	tests.insert(make_pair("flaggier", "a722cdbd38f915a87d424e10d8cb4b787bd2f08d"));
	tests.insert(make_pair("morganic", "eebbebe01bdc3828e5cc33e5705a14d392adcbaa"));
	tests.insert(make_pair("kankakee", "c6e57e838b2a7e3f20d2c48349e7716a683911f9"));
	tests.insert(make_pair("crosslet", "04fcd808841718df3ff51c7d097900fb1d2281fa"));
	tests.insert(make_pair("basilisk", "4bde28c14f8ae37923d08be77447927d186a33f4"));
	tests.insert(make_pair("jeweller", "770db9155a39b00af1ecc75ee8eb5f72937059b2"));
	tests.insert(make_pair("hawaiian", "b992de40bd2138b56212f208b1af60b329615780"));

	for (auto& test : tests)
		checkout(test.first, test.second);
}