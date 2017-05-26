#ifndef HUGEINTEGER_H_
#define HUGEINTEGER_H_

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class HugeInteger {
private:
	bool negative;
	vector<short> num;
	void clearLeadingZeroes();
	void setNum(string str);
	void setNum(long long str);
public:
	HugeInteger(string str = "");
	HugeInteger(long long num);
	int size() const;
	bool isNegative() const;
	void append(const short& digit);
	void setDigit(const short& digit, const unsigned& index);
	short getDigit(const unsigned& index) const;
	static HugeInteger abs(const HugeInteger& a);
	HugeInteger operator+(const HugeInteger& a);
	HugeInteger& operator+=(const HugeInteger& a);
	HugeInteger& operator++(int a);
	HugeInteger& operator++();
	HugeInteger operator-(const HugeInteger& a);
	HugeInteger& operator-=(const HugeInteger& a);
	HugeInteger& operator--(int a);
	HugeInteger& operator--();
	HugeInteger operator*(const HugeInteger& a);
	HugeInteger operator/(const HugeInteger& a);
	HugeInteger operator%(const HugeInteger& a);
	bool operator==(const HugeInteger& a) const;
	bool operator!=(const HugeInteger& a) const;
	bool operator>(const HugeInteger& a) const;
	bool operator>=(const HugeInteger& a) const;
	bool operator<(const HugeInteger& a) const;
	bool operator<=(const HugeInteger& a) const;
	friend ostream& operator<<(ostream& os, const HugeInteger& obj);
	friend istream& operator>>(istream& is, HugeInteger& obj);
	virtual ~HugeInteger();
};

typedef HugeInteger hInt;

#endif
