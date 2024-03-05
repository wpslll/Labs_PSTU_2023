# 1) Задание
а) целые числа возводит в степень n;
б) из десятичных чисел извлекает корень степени n.
# 2) Код программы
```cpp
#include <iostream>
#include <cmath>
using namespace std;
void s(float n, int a)
{
	a = pow(a, n);
	cout << a;
}
void s (float n, double a)
{
	a = pow(a, 1 / n);
	cout << a;
}
int main()
{
	int n;
	cin >> n;
	s(n, 0.36);
	return 0;
}
```
# 3) Блок-схема
![lab_7 drawio](https://github.com/wpslll/Labs_PSTU_2023/assets/151571121/2248d31c-5788-4107-9cf3-94127fc73bbd)
# 4) Тесты
s(n, 0.36);
n = 2;
0.6;

s(n, 4);
n = 2;
16;

s(n, 9);
n = 3
729
