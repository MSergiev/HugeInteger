#include <iostream>
#include <sstream>
#include "HugeInteger.h"
using namespace std;

int main() {

	hInt a("300123423");
	hInt b = 243;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "\na>b = " << (a>b) << endl;
	cout << "a<b = " << (a<b) << endl;
	cout << "a>=b = " << (a>=b) << endl;
	cout << "a<=b = " << (a<=b) << endl;
	cout << "a==b = " << (a==b) << endl;
	cout << "\na+b = " << a+b << endl;
	cout << "a-b = " << a-b << endl;
	cout << "a*b = " << a*b << endl;
	cout << "a/b = " << a/b << endl;
	cout << "a%b = " << a%b << endl;
	cout << "a+=b = " << (a+=b) << endl;
	cout << "a++ = " << (a++) << endl;
	cout << "++a = " << (++a) << endl;
	cout << "a-=b = " << (a-=b) << endl;
	cout << "a-- = " << (a--) << endl;
	cout << "--a = " << (--a) << endl;

	return 0;
}
