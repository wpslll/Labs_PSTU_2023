#include <iostream>
using namespace std;
void f(int n, int i, int j)
{
	if (n == 1)
	{
		cout << "moving circle " << n << " from pin " << i << " to pin " << j << endl;
	}
	else
	{
		int tmp = 6 - i - j;
		f(n - 1, i, tmp);
		cout << "moving circle " << n << " from pin " << i << " to pin " << j << endl;
		f(n - 1, tmp, i);
	}
}
int main()
{
	f(3, 1, 2);
	return 0;
}