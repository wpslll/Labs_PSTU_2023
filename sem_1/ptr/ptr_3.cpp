#include <iostream>
using namespace std;
int main()
{
	float a, b;
	cin >> a >> b;
	float* aptr = &a;
	float* bptr = &b;
	cout << *aptr + *bptr;
	return 0;
}