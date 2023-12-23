#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a;
	bool minus = false;
	bool plus = false;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (!minus && !plus)
		{
			if (a < 0) { minus = true; }
			else if (a > 0) { plus = true; }
		}
	}
	if (minus)
	{
		cout << "first number is negative";
	}
	else if (plus)
	{
		cout << "first number is positive";
	}
	else
	{
		cout << "every number is 0";
	}
	return 0;
}