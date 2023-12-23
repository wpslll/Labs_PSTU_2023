#include <iostream>
using namespace std;
int main()
{
	int n;
	int d;
	cin >> n;
	d = n % 2;
	if (n < 3)
	{
		cout << "число должно быть больше 3" << endl;
	}
	else if (d == 1)
	{
		cout << "число должно быть четным" << endl;
	}
	else
	{
		int spaces = n / 2;
		int stars = 1;

		for (int i = 0; i < (n + 1) / 2; i++)
		{
			for (int j = 0; j < spaces; j++)
			{
				cout << " ";
			}
			spaces--;
			for (int j = 0; j < stars; j++)
			{
				cout << "*";
			}
			stars += 2;
			cout << endl;
		}
	}
	return 0;
}