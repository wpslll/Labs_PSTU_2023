#include <iostream>
using namespace std;
int main()
{
	int n, sum;
	cin >> n;
	sum = 0;
	if (n <= 0)
	{
		cout << "так нельзя" << endl;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			int object = 1;
			for (int j = i; j <= 2 * i; j++)
			{
				object *= j;
			}
			sum += object;
		}
		cout << sum << endl;
	}
	return 0;
}