#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n / 2; i++)
	{
		cout << "  ";
	}
	for (int i = 0; i <= n; i++)
	{
		cout << "* ";
	}
	cout << endl;
	int o;
	int k = 0;
	o = n / 2;
	for (int i = 0; i < n / 2 - 2; i++)
	{
		o--;
		for (int j = 0; j < o; j++)
		{
			cout << "  ";
		}
		cout << "* ";
		for (int j = 0; j < n; j++)
		{
			cout << "  ";
		}
		cout << "* ";
		for (int j = 0; j < k; j++)
		{
			cout << "  ";
		}
		cout << "* ";
		k++;
		cout << endl;
	}
	cout << "  ";
	for (int i = 0; i < n; i++)
	{
		cout << "* ";
	}
	cout << "* * ";
	for (int i = 0; i < n / 2 - 2; i++)
	{
		cout << "  ";
	}
	cout << "*";
	cout << endl;
	for (int i = 0; i < n / 2 - 2; i++)
	{
		cout << "  ";
		cout << "* ";
		for (int j = 0; j < n; j++)
		{
			cout << "  ";
		}
		cout << "* ";
		for (int j = 0; j < n / 2 - 2; j++)
		{
			cout << "  ";
		}
		cout << "* ";
		cout << endl;
	}
	int l = n / 2 - 1;
	for (int i = 0; i < n / 2 - 1; i++)
	{
		l--;
		cout << "  ";
		cout << "* ";
		for (int j = 0; j < n; j++)
		{
			cout << "  ";
		}
		cout << "*";
		for (int j = 0; j < l; j++)
		{
			cout << "  ";
		}
		cout << "*";
		cout << endl;
	}
	cout << " ";
	for (int i = 0; i < n; i++)
	{
		cout << "* ";
	}
	cout << "* * ";
	return 0;
}