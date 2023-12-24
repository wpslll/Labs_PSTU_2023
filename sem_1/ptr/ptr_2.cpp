#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int* aptr = &a;
	int* bptr = &b;
	cout << *aptr + *bptr;
	return 0;
}