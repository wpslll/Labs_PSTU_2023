#include "vector.h"
void vector::add(oobject* p)
{
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
}
ostream& operator<<(ostream& out, const vector& v)
{
	if (v.size == 0) out << "empty" << endl;
	oobject** p = v.beg;
	for (int i = 0; i < v.cur; i++)
	{
		(*p)->show();
		p++;
	}
	return out;
}