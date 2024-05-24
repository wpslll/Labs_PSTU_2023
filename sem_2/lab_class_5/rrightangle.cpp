#include "rrightangle.h"
#include <iostream>
#include <cmath>
using namespace std;
rightangle::rightangle(void)
{
	first = 0;
	second = 0;
	third = 0;
}
rightangle::~rightangle(void)
{
}
rightangle::rightangle(int F, int S, int T)
{
	first = F;
	second = S;
	third = T;
}
rightangle::rightangle(const rightangle& r)
{
	first = r.first;
	second = r.second;
	third = r.third;
}
void rightangle::set_first(int F)
{
	first = F;
}
void rightangle::set_second(int S)
{
	second = S;
}
void rightangle::set_third(int T)
{
	third = T;
}
rightangle& rightangle::operator=(const rightangle& r)
{
	if (&r == this) return *this;
	first = r.first;
	second = r.second;
	third = r.third;
	return *this;
}
istream& operator>>(istream& in, rightangle& r)
{
	cout << "first: ";
	in >> r.first;
	cout << "second: ";
	in >> r.second;
	cout << "third: ";
	in >> r.third;
	return in;
}
ostream& operator<<(ostream& out, const rightangle& r)
{
	out << "first: " << r.first << endl;
	out << "second: " << r.second << endl;
	out << "third: " << r.third << endl;
	return out;
}
int rightangle::finding_the_hypotenuse()
{
	third = sqrt(pow(first, 2) + pow(second, 2));
	return third;
}
void rightangle::show()
{
	cout << "first: " << first;
	cout << "second: " << second;
	cout << "third: " << third;
}