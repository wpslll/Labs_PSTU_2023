#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	/*
	* 3x - 4lnx - 5 = 0
	* [2;4]
	*/
	double a = 2, b = 4, c, Fa, Fb, Fc;
	double eps = 0.000001;
	while (b - a >= eps)
	{
		c = (a + b) / 2;
		Fa = 3 * a - 4 * log(a) - 5;
		Fb = 3 * b - 4 * log(b) - 5;
		Fc = 3 * c - 4 * log(c) - 5;
		if (Fa * Fc > 0)
		{
			a = c;
		}
		else if (Fa * Fc < 0)
		{
			b = c;
		}
	}
	cout << (a + b) / 2;
	return 0;
}