#pragma once
#include <iostream>
#include <string>
using namespace std;
class Pair
{
public:
	Pair(void);
	virtual ~Pair(void);
	Pair(int, int);
	Pair(const Pair&);
	int get_first() { return first; }
	int get_second() { return second; }
	void set_first(int);
	void set_second(int);
	Pair& operator=(const Pair&);
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
	void first_times_second();
protected:
	int first;
	int second;
};
