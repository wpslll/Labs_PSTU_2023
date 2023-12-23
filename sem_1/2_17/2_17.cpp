#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	float x;
	float y = 1;
	int a;
	cin >> n;
	cin >> x;
	for (int i = 1; i < n; i++)
	{
		a = 1;
		for (int j = 1; j < i; j++)
		{
			a = a * (a + 1);
		}
		y = y + pow(x, i) / (a);
	}
	cout << y;
	return 0;
}