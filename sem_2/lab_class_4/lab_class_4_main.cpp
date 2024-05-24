#include <iostream>
#include "pair.h"
#include "rightangle.h"
using namespace std;
void f1(Pair& d)
{
	d.set_first(5);
	cout << d;
}
Pair f2()
{
	rightangle l(1, 2, 3);
	return l;
}
void main()
{
	Pair a;
	cin >> a;
	cout << a;
	Pair b(2, 3);
	cout << b;
	a = b;
	cout << a;
	a.first_times_second();
	cout << endl;
	rightangle c;
	cin >> c;
	cout << c;
	f1(c);
	cout << endl;
	a = f2();
	cout << a;
	c.finding_the_hypotenuse();
	cout << c;
}