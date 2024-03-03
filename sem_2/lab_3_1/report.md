# 1) Задание
Посчитать сумму ряда при помощи рекурсии (15 вариант)
# 2) Код программы
```cpp
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
    int n;                                              
    double x;                                           
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "The sum is: " << sum(n, x) << endl;
    return 0;
}
```
# 3) Блок-схема
![lab_3_1_main drawio](https://github.com/wpslll/Labs_PSTU_2023/assets/151571121/fc581edd-9b3a-47a4-ab81-1fa0b65556a8)
![lab_3_1_sum drawio](https://github.com/wpslll/Labs_PSTU_2023/assets/151571121/67309606-981b-4a0d-97f2-8fc4acf86a42)
# 4) Тесты
```cpp
Enter the value of n: 5
Enter the value of x: 2
The sum is: 14.0837

Enter the value of n: 10
Enter the value of x: 3
The sum is: -2.30606e+07

Enter the value of n: 7
Enter the value of x: 1
The sum is: -0.045732
```
