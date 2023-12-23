#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a;
	int max = 0;
	int min = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a >= max)
		{
			max = a;
		}
		else if (a <= min)
		{
			min = a;
		}
		if (max < min)
		{
			min = max;
		}
		else if (min > max)
		{
			max = min;
		}

	}
	cout << max << endl << min;
	return 0;
}