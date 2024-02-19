#include <iostream>
using namespace std;
int main()
{
	int n = 5;
	int a[5][5];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i + j + 2) % 2 == 0)
			{
				a[i][j] = 1;
			}
		}
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