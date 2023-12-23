#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int sum;
	int max = INT_MIN;
	int min = INT_MAX;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		if (a >= max)
		{
			max = a;
		}
		if (a < min)
		{
			min = a;
		}
	}
	sum = min + max;
	cout << sum;
	return 0;
}