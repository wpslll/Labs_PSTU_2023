#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a;
	int b;
	int c;
	float x;
	float xa;
	float xb;
	cin >> a;
	cin >> b;
	cin >> c;
	int d = b * b + (-4 * a * c);
	if (d > 0)
	{
		x = (-b + sqrt(d)) / (2 * a);
		xa = (-b - sqrt(d)) / (2 * a);
		cout << x << endl <<  xa;
	}
	if (d < 0)
	{
		cout << "discriminant < 0";
	}
	if ( d == 0 )
	{
		xb = -b / (2 * a);
		cout << xb;
	}
	return 0;
}