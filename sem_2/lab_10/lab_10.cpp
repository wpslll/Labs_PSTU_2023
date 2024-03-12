#include <iostream>
using namespace std;
int** make_matr(int n)
{
	int** matr;
	matr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			matr[i][j] = rand() % 10;
		}
	}
	return matr;
}
int main()
{
	int n, max = INT_MIN, x = 0, y;
	cin >> n;
	int** matr = make_matr(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matr[i][j] > max)
			{
				max = matr[i][j];
				x = i;
				y = j;
			}
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	int matr1[4][4] = { 0 };
	for (int i = x; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			matr1[i][j] = matr[i + 1][j];
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = y; j < n - 1; j++)
		{
			matr1[i][j] = matr[i][j + 1];
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			cout << matr1[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}