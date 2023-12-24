#include <iostream>
using namespace std;
int main()
{
	bool a = true;
	int n;
	int b = INT_MIN;
	do
	{
		cin >> n;
		if (n == 0)
		{
			b = 0;
		}
		if (b > n)
		{
			a = false;
		}
		b = n;
	} while (n != 0);
	if (a)
	{
		cout << "ordered";
	}
	else
	{
		cout << "not ordered";
	}
	return 0;
}