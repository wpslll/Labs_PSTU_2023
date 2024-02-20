#include <iostream>
using namespace std;
int f(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	if (n == 0)
	{
		return 0;
	}
	return f(n - 1) + f(n - 2);
}
int main()
{
	int t;
	cin >> t;
	cout << f(t) << " ";
	return 0;
}