#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a = 1;
	int* aptr = &a;
	for (int i = 1; i <= n; i++)
	{
		*aptr *= i;
	}
	cout << a;
	return 0;
}