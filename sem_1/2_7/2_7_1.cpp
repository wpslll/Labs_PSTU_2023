#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= sqrt(n); i++)
	{
		for (int j = 1; j <= sqrt(n); j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	return 0;
}