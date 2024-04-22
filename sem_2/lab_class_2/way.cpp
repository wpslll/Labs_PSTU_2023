#include <iostream>
#include "way.h"
using namespace std;
trip::trip()
{
	start = " ";
	end = " ";
	time = 0;
	cout << "parameterless constructor for object " << this << endl;
}
trip::trip(string s, string e, float t)
{
	start = s;
	end = e;
	time = t;
	cout << "constructor with parameter for object " << this << endl;
}
trip::trip(const trip &tr)
{
	start = tr.start;
	end = tr.end;
	time = tr.time;
	cout << "copy costructor for object " << this << endl;
}
trip::~trip()
{
	cout << "destructor for object " << this << endl;
}
string trip::get_start()
{
	return start;
}
string trip::get_end()
{
	return end;
}
float trip::get_time()
{
	return time;
}
void trip::set_start(string s)
{
	start = s;
}
void trip::set_end(string e)
{
	end = e;
}
void trip::set_time(float t)
{
	time = t;
}
void trip::show()
{
	cout << "start: " << start << endl;
	cout << "end: " << end << endl;
	cout << "time: " << time << endl;
}