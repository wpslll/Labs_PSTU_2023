#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int o = 0;
	int k = n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= o; j++)
		{
			cout << " ";
		}
		for (int j = 1; j <= k; j++)
		{
			cout << "*";
		}
		o++;
		k--;
		cout << endl;
	}
	return 0;
}