#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int s = 1;
	for (int i = 2; i <= n; i++)
	{
		if (i % 3 != 0)
		{
			s += i;
		}
		else if (i % 3 == 0)
		{
			s -= i;
		}
	}
	cout << s;
	return 0;
}