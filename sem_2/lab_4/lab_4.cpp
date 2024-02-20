#include <iostream>
using namespace std;
int main()
{
	int r, k, b, n = 10;
	int a[10];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 101 - 50;
		cout << a[i] << " ";
	}
	cout << endl << "enter k" << endl;
	cin >> k;
	cout << "1. move array k times to the left" << endl << "2. move array k times to the right" << endl;
	cin >> b;
	if (b == 2)
	{
		for (int i = 0; i < k; i++)
		{
			r = a[n - 1];
			for (int j = n - 1; j > 0; j--)
			{
				a[j] = a[j - 1];
			}
			a[0] = r;
		}
	}
	if (b == 1)
	{
		for (int i = 0; i < k; i++)
		{
			r = a[0];
			for (int j = 0; j < n - 1; j++)
			{
				a[j] = a[j + 1];
			}
			a[n - 1] = r;
		}
	}
	for (int i = n - 1; i > n - k - 1; i--)
	{
		cout << a[i] << " ";
	}
	for (int i = 0; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}