#include "pair.h"
#include <iostream>
Pair::Pair(void)
{
	first = 0;
	second = 0;
}
Pair::~Pair(void)
{
}
Pair::Pair(int F, int S)
{
	first = F;
	second = S;
}
Pair::Pair(const Pair& pair)
{
	first = pair.first;
	second = pair.second;
}
void Pair::set_first(int F)
{
	first = F;
}
void Pair::set_second(int S)
{
	second = S;
}
Pair& Pair::operator=(const Pair& p)
{
	if (&p == this) return *this;
	first = p.first;
	second = p.second;
	return *this;
}
istream& operator>>(istream& in, Pair& p)
{
	cout << "first: ";
	in >> p.first;
	cout << "second: ";
	in >> p.second;
	return in;
}
ostream& operator<<(ostream& out, const Pair& p)
{
	out << "first: " << p.first << endl;
	out << "second: " << p.second << endl;
	return out;
}
void Pair::first_times_second()
{
	cout << first * second;
}