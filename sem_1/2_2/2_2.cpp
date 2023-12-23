#include <iostream>
using namespace std;
int main()
{
	int n;
	int b = 1;
	cin >> n;
	if (n <= 0)
	{
		cout << "так нельзя" << endl;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			b = b * i;
		}
		cout << b << endl;
	}
	return 0;
}