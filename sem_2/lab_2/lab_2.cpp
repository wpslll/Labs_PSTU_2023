#include <iostream>
using namespace std;
int main()
{
	int a[5][5];
	int n = 5, k = 1, r = 4, c;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		c = i + 1;
		for (int j = 0; j < k; j++)
		{
			a[i][j] = c;
			c--;
		}
		k++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}