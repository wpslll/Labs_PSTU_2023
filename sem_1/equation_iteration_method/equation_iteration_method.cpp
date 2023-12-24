#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	/*
	* f(x) = 3x - 4lnx - 5
	* f'(x) = 3 - 4/x
	*  [2;4]
	*  ф(x) = x + l(3x - 4lnx - 5)
	* r = max(|3 - 4/2|; |3 - 4/4|) = 2
	* f'(x) > 0 => -1/r <l < 0
	* l = -0,25
	*/
	double x = 4, x1 = 0;
	double l = -0.25;
	double eps = 0.000001;
	while (abs(x - x1) > eps)
	{
		x1 = x;
		x = x1 + l * (3 * x1 - 4 * log(x1) - 5);
	}
	cout << x;
	return 0;
}