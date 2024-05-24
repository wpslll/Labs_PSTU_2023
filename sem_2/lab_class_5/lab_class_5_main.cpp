#include "ppair.h"
#include "oobject.h"
#include "rrightangle.h"
#include "vector.h"
#include <iostream>
using namespace std;
void main()
{
	vector v(5);
	ppair a;
	cin >> a;
	rightangle b;
	cin >> b;
	oobject* p = &a;
	v.add(p);
	p = &b;
	v.add(p);
	cout << v;
}