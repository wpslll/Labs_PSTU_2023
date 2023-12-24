#include <iostream>
using namespace std;
int main()
{
	float a, max;
	int n;
	int b = 0;
	cin >> n;
	int i = 1;
	max = sin(n + i / n);
	while (i <= n)
	{
		i++;
		float a = sin(n + i / n);
		if (a == max)
		{
			b++;
		}
	}
	cout << b;
	return 0;
}