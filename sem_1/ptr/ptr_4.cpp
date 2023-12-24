#include <iostream>
using namespace std;
int main()
{
	int n, max, min; 
	cin >> n;
	max = INT_MIN;
	min = INT_MAX;
	int* maxptr = &max;
	int* minptr = &min;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a > *maxptr)
		{
			*maxptr = a;
		}
		if (a < *minptr)
		{
			*minptr = a;
		}
	}
	cout << min << "  " << max;
	return 0;
}