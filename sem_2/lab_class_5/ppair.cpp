#include "ppair.h"
#include "oobject.h"
#include <iostream>
using namespace std;
ppair::ppair(void)
{
	first = 0;
	second = 0;
}
ppair::~ppair(void)
{
}
ppair::ppair(int F, int S)
{
	first = F;
	second = S;
}
ppair::ppair(const ppair& pair)
{
	first = pair.first;
	second = pair.second;
}
void ppair::set_first(int F)
{
	first = F;
}
void ppair::set_second(int S)
{
	second = S;
}
ppair& ppair::operator=(const ppair& p)
{
	if (&p == this) return *this;
	first = p.first;
	second = p.second;
	return *this;
}
istream& operator>>(istream& in, ppair& p)
{
	cout << "first: ";
	in >> p.first;
	cout << "second: ";
	in >> p.second;
	return in;
}
ostream& operator<<(ostream& out, const ppair& p)
{
	out << "first: " << p.first << endl;
	out << "second: " << p.second << endl;
	return out;
}
void ppair::first_times_second()
{
	cout << first * second;
}
void ppair::show()
{
	cout << "first: " << first;
	cout << "second: " << second;
}