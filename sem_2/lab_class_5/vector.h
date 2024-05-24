#pragma once
#include "oobject.h"
#include <iostream>
using namespace std;
class vector
{
	oobject** beg;
	int size;
	int cur;
public:
	vector(void) { beg = 0; size = 0; cur = 0; }
	vector(int n) { beg = new oobject * [n]; cur = 0; size = n; }
	~vector()
	{
		if (beg != 0)
		{
			delete[] beg;
			beg = 0;
		}
	}
	void add(oobject*);
	friend ostream& operator<<(ostream& out, const vector&);
};