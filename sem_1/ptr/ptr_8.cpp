﻿#include <iostream>
#include <string>
using namespace std;
int main() 
{
	string a, b, c;
	cin >> a >> b >> c;
	int x = 0, y = 0, z = 0;
	int l = a.length();
	for (int i = 0; i < l; i++)
	{
		string sum = a.substr(i, 1);
		if (sum == a)
		{
			x++;
		}
		else if (sum == b)
		{
			y++;
		}
		else
		{
			z++;
		}
	}
	cout << x << "  " << y << "  " << z << "  " << a.length();
	return 0;
}