#include <iostream>
#include <string>
#include "way.h"
using namespace std;
trip make_trip()
{
	string st;
	string en;
	float ti;
	cout << "enter start: ";
	cin >> st;
	cout << "enter end: ";
	cin >> en;
	cout << "enter time: ";
	cin >> ti;
	trip t(st, en, ti);
	return t;
}
void print_trip(trip t)
{
	t.show();
}
void main()
{
	trip t1;
	t1.show();
	trip t2("Toronto", "Tokyo", 13.40);
	t2.show();
	trip t3 = t2;
	t3.set_start("Milan");
	t3.set_end("Paris");
	t3.set_time(1.3);
	print_trip(t3);
	t1 = make_trip();
	t1.show();
}