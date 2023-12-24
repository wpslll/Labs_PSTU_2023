#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* ptr = &n;
	cin >> *ptr;
	cout << n;
	return 0;
}