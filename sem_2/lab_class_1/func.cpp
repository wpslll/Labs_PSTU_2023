#include <iostream>
#include "fraction.h"
using namespace std;
void ccost::read()
{
	cout << "first: ";
	cin >> first;
	cout << "second: ";
	cin >> second;
}
void ccost::show()
{
	cout << "first: " << first << endl << "second: " << second << endl;
}
void ccost::cost()
{
	cout << "cost: " << second * first;
}