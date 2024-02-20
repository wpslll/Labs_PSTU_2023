#include <iostream>
using namespace std;
int main()
{
	int a[4][4], n = 4, s, l = 3, max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 101 - 50;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	for (int j = 0; j < n - 1; j++)
	{
		s = 0;
		for (int i = 0; i < l; i++)
		{
			s += a[i][j];
		}
		cout << s << endl;
		if (s > max)
		{
			max = s;
		}
		l--;
	}
	cout << "max sum is " << max;
	return 0;
}