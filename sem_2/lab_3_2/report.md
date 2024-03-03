# 1) Задание
Вычислить n-ый элемент последовательности чисел Фибоначчи через рекурсию
# 2) Код программы
```cpp
#include <iostream>
using namespace std;
int f(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	if (n == 0)
	{
		return 0;
	}
	return f(n - 1) + f(n - 2);
}
int main()
{
	int t;
	cin >> t;
	cout << f(t) << " ";
	return 0;
}
```
# 3) Блок-схема
![lab_3_2_main drawio](https://github.com/wpslll/Labs_PSTU_2023/assets/151571121/b877959e-99eb-4975-84d6-f98c49ef762d)
![lab_3_2_f drawio](https://github.com/wpslll/Labs_PSTU_2023/assets/151571121/16f8ba65-4ff3-4bb0-b317-104deb486d3a)
# 4) Тесты
```cpp
n = 4;
3
n = 10;
55
n = 12;
144
```
