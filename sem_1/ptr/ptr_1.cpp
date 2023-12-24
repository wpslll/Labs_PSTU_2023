#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int* aptr = &a;
	int* bptr = &b;
	int c = *aptr;
	*aptr = *bptr;
	*bptr = c;
	cout << a << b;
	return 0;
}