#include <iostream>
#include <cmath>
using namespace std;
void s(float n, int a)
{
	a = pow(a, n);
	cout << a;
}
void s (float n, double a)
{
	a = pow(a, 1 / n);
	cout << a;
}
int main()
{
	int n;
	cin >> n;
	s(n, 0.36);
	return 0;
}