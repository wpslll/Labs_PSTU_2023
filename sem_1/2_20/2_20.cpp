#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float n, s;
	cin >> n >> s;
	int i = 1;
	float a;
	bool f = false;
	while (i <= n && !f)
	{
		a = sin(n + i / n);
		a = round(a * 10) / 10;
		cout << n + i / n << "|" << a << endl;
		if (a == s)
		{
			f = true;
		}
		else
		{
			i++;
		}
	}
	if (f == true)
	{
		cout << "s exists";
	}
	else
	{
		cout << "no s";
	}
	return 0;
}