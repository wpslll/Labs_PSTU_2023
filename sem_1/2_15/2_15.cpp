#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int s;
	cin >> s;
	while (n != 0)
	{
		if (n % 10 == s)
		{
			cout << "there is number " << s;
		}
		n = n / 10;
	}
	return 0;
}