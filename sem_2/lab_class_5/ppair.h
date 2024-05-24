#pragma once
#include "oobject.h"
#include <iostream>
#include <istream>
using namespace std;
class ppair:
	public oobject
{
public:
	ppair(void);
	virtual ~ppair(void);
	ppair(int, int);
	ppair(const ppair&);
	void show();
	int get_first() { return first; }
	int get_second() { return second; }
	void set_first(int);
	void set_second(int);
	ppair& operator=(const ppair&);
	friend istream& operator>>(istream& in, ppair& p);
	friend ostream& operator<<(ostream& out, const ppair& p);
	void first_times_second();
protected:
	int first;
	int second;
};

