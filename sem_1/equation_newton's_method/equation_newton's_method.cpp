#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	/*
	* 3x - 4lnx - 5 = 0
	* [2, 4]
	* f'(x) = 3 - 4 / x
	* f"(x) = 4 / pow(x, 2)
	* f(b) * f"(b) = 1,45... > 0
	*/
	double x = 4, x1 = 0;
	double eps = 0.000001;
	while (abs(x - x1) > eps)
	{
		x1 = x;
		x = x1 - (3 * x1 - 4 * log(x1) - 5) / (3 - 4 / x1);
	}
	cout << x;
	return 0;
}