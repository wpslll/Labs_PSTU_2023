#include <iostream>
#include <cmath>
using namespace std;
double sum(int n, double x) 
{
    if (n == 1)
    {
        return pow(-1, 1 + 1) * (pow(x, 3)) / 3;
    }
    if (n == 2) 
    {
        return pow(-1, 2 + 1) * (pow(x, 5)) / 15;
    }
    else 
    {
        return pow(-1, n + 1) * (pow(x, 2 * n + 1)) / (4 * n * n - 1) + sum(n - 1, x);
    }
}
int main() 
{
    int n;                                              //n = 4, x = 2, sum = -6.60317
    double x;                                           //n = 5, x = 2, sum = 14.0837
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "The sum is: " << sum(n, x) << endl;
    return 0;
}