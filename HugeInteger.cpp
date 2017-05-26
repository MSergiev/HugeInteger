#include "HugeInteger.h"

hInt::HugeInteger(string str) {
	negative = false;
	setNum(str);
}

hInt::HugeInteger(long long num) {
	negative = false;
	setNum(num);
}

void hInt::setNum(string str) {
	if(str.size()<1) return;
	str.at(0)=='-'?negative=true:negative=false;
	while(str.size()>0)	{
		char c = str.at(str.size()-1);
		if(c >= '0' && c <= '9') num.push_back(c-'0');
			str.erase(str.end()-1);
	}
}

void hInt::setNum(long long num) {
	if(num == 0) { this->num.push_back(0); return; }
	if(num == 1) { this->num.push_back(1); return; }
	num<0?negative=true:negative=false;
	while(num!=0){ this->num.push_back(num%10); num/=10; }
}

bool hInt::isNegative() const{
	return negative;
}

int hInt::size() const{
	return num.size();
}

void hInt::append(const short& digit){
	num.push_back(digit%10);
}

void hInt::setDigit(const short& digit, const unsigned& index){
	num.at(index) = digit%10;
}

short hInt::getDigit(const unsigned& index) const{
	if(index < num.size())	return num.at(index);
	else return 0;
}

hInt hInt::abs(const hInt& a){
	hInt a1 = a;
	a1.negative = false;
	return a1;
}

void hInt::clearLeadingZeroes(){
	while(num.at(num.size()-1)==0) num.erase(num.end()-1);
}

hInt hInt::operator+(const hInt& a){
	if(a==0) return *this;
	if(*this==0) return a;

	hInt sum;

	if(isNegative()!=a.isNegative()) {
		isNegative()?sum = abs(a)-abs(*this):sum = abs(*this)-abs(a);
		if(isNegative()) sum.negative = true;
		return sum;
	}

	if(isNegative() && a.isNegative()) sum.negative = 1;

	bool carry = 0;

	for(int i = 0; i < (size()>a.size()?size():a.size()); i++){
		short tmp = carry;
		tmp+=getDigit(i);
		tmp+=a.getDigit(i);
		sum.append(tmp%10);
		carry = (tmp/10);
	}
	if(carry) sum.append(carry);
	return sum;
}

hInt& hInt::operator+=(const hInt& a){
	if(a==0) return *this;
	*this = *this + a;
	return *this;
}

hInt& hInt::operator++(int a){
	a=0;
	*this+=1;
	return *this;
}

hInt& hInt::operator++(){
	return (*this)++;
}

hInt hInt::operator-(const hInt& a){
	if(a==0) return *this;
	if(*this==0) return a;

	hInt sub;


	if(isNegative() && a.isNegative()){
		sub = abs(a)-abs(*this);
		if(abs(a)<abs(*this)) sub.negative = true;
		return sub;
	}

	if(isNegative()!=a.isNegative()) {
		sub = abs(*this)+abs(a);
		if(isNegative()) sub.negative = true;
		return sub;
	}

	const hInt* aPtr = this;
	const hInt* bPtr = &a;

	if(abs(*this)<abs(a)){
		sub.negative = 1;
		aPtr = &a;
		bPtr = this;
	}

	bool carry = aPtr->getDigit(0)<bPtr->getDigit(0);
	bool oldCarry = 0;

	for(int i = 0; i < (size()>a.size()?size():a.size()); i++){
		carry = ((aPtr->getDigit(i)-carry)<bPtr->getDigit(i));
		short tmp = 10*carry + aPtr->getDigit(i)-oldCarry - bPtr->getDigit(i);
		sub.append(tmp);
		oldCarry = carry;
	}

	sub.clearLeadingZeroes();

	return sub;
}

hInt& hInt::operator-=(const hInt& a){
	if(a==0) return *this;
	*this = *this - a;
	return *this;
}

hInt& hInt::operator--(int a){
	a = 0;
	*this-=1;
	return *this;
}

hInt& hInt::operator--(){
	return (*this)++;
}

hInt hInt::operator*(const hInt& a){
	if(a==0 || *this==0) return 0;
	if(a==1) return *this;
	if(*this==1) return a;
	hInt product = 0;
	for(hInt i = 0; i < abs(a); i++) product+=abs(*this);
	(isNegative()==a.isNegative()||product==0)?product.negative=false:product.negative=true;
	return product;
}

hInt hInt::operator/(const hInt& a){
	if(*this==0 || *this==1) return 0;
	if(a==0) return hInt("-");
	if(a==1) return *this;
	hInt quotient = 0;
	hInt remainder = abs(*this);
	hInt modulus = abs(a);
	while(remainder>=modulus) {remainder-=modulus; quotient++;}
	return quotient;
}

hInt hInt::operator%(const hInt& a){
	if(a==0 || *this==0) return 0;
	hInt remainder = abs(*this);
	hInt modulus = abs(a);
	while(remainder>=modulus) remainder-=modulus;
	return remainder;
}

bool hInt::operator>(const hInt& a) const{
	if(!isNegative()){
		if(a.isNegative()) return true;
		if(size()>a.size()) return true;
		if(size()==a.size()){
			for(int i = size()-1; i >= 0 ; i--){
				if(getDigit(i)<a.getDigit(i)) return false;
				if(getDigit(i)>a.getDigit(i)) return true;
			}
		}
	} else {
		if(!a.isNegative()) return false;
		if(size()<a.size()) return true;
		if(size()==a.size()){
			for(int i = size()-1; i >= 0 ; i--){
				if(getDigit(i)>a.getDigit(i)) return false;
				if(getDigit(i)<a.getDigit(i)) return true;
			}
		}
	}
	return false;
}

bool hInt::operator<(const hInt& a) const{
	return a>*this;
}

bool hInt::operator>=(const hInt& a) const{
	if(*this>a || *this==a) return true;
	return false;
}

bool hInt::operator<=(const hInt& a) const{
	if(*this<a || *this==a) return true;
	return false;
}

bool hInt::operator==(const hInt& a) const{
	if(this->num == a.num) return true;
	if(isNegative()!=a.isNegative()) return false;
	if(size()!=a.size() || isNegative()!=a.isNegative()) return false;
	bool equal = true;
	for(int i = 0; i < size(); i++)
		if(getDigit(i)!=a.getDigit(i)) equal = false;
	return equal;
}

bool hInt::operator!=(const hInt& a) const{
	if(*this == a) return false;
	return true;
}

ostream& operator<<(ostream& os, const hInt& obj){
	if(obj.isNegative()) os << '-';
	if(obj.size() > 0) for(int i = obj.size()-1; i >= 0 ; i--) os << obj.getDigit(i);
	return os;
}

istream& operator>>(istream& is, hInt& obj){
	string str = "";
	if(is.peek()=='-') {str+=is.get(); }
	while(is.peek() >= '0' && is.peek() <= '9') str+=is.get();
	obj.setNum(str);
	return is;
}

hInt::~HugeInteger() {
}

