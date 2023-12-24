#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	float a;
	cin >> n;
	int i = 2;
	int num = 2;
	float max = sin(n + i / n);
	cout << max<< endl;
	while (i <= n)
	{
		a = sin(n + i / n);
		cout << a << endl;
		if (a > max)
		{
			num = i;
			max = a;
		}
		i++;
	}
	cout << "the biggest number is" << num << "  " << max;
	return 0;
}