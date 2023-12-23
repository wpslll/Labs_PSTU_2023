#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int sum = 0;
	int k = 0;
	while (n != 0)
	{
		k = n % 10;
		sum = sum + k;
		n = n / 10;
	}
	cout << sum;
	return 0;
}