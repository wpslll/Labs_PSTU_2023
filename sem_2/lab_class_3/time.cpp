#include "time.h"
#include <iostream>
using namespace std;
Time& Time::operator=(const Time& t)
{
	if (&t == this) return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}
Time& Time::operator++()
{
	int tmp = min * 60 + sec;
	tmp++;
	min = tmp / 60;
	sec = tmp % 60;
	return *this;
}
Time Time::operator++(int)
{
	int tmp = min * 60 + sec;
	tmp++;
	Time t(min, sec);
	min = tmp / 60;
	sec = tmp % 60;
	return t;
}
Time Time::operator+(const Time& t)
{
	int tmp_1 = min * 60 + sec;
	int tmp_2 = t.min * 60 + t.sec;
	Time p;
	p.min = (tmp_1 + tmp_2) / 60;
	p.sec = (tmp_1 + tmp_2) % 60;
	return p;
}
istream& operator>>(istream& in, Time& t)
{
	cout << "min: ";
	in >> t.min;
	cout << "sec: ";
	in >> t.sec;
	return in;
}
ostream& operator<<(ostream& out, const Time& t)
{
	return (out << t.min << " : " << t.sec);
}