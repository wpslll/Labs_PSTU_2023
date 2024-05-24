#pragma once
#include <iostream>
#include "ppair.h"
class rightangle :
	public ppair
{
public:
	rightangle(void);
	~rightangle(void);
	rightangle(int, int, int);
	rightangle(const rightangle&);
	void show();
	int get_first() { return first; }
	int get_second() { return second; }
	int get_third() { return third; }
	void set_first(int);
	void set_second(int);
	void set_third(int);
	rightangle& operator=(const rightangle&);
	friend istream& operator>>(istream& in, rightangle& r);
	friend ostream& operator<<(ostream& out, const rightangle& r);
	int finding_the_hypotenuse();
protected:
	int third;
};