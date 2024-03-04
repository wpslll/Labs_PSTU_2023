# 1) Задание
1) Реализовать с использованием массива двунаправленное
кольцо (просмотр возможен в обе стороны, от последнего
элемента можно перейти к первому).
2) Распечатать полученный массив, начиная с К-ого элемента
и до К-1 ( по кольцу влево).
3) Удалить из кольца первый и последний элементы.
4) Распечатать полученный массив, начиная с К-ого элемента
(и до К+1 по кольцу вправо).
# 2) Код программы
```cpp
#include <iostream>
using namespace std;
int main()
{
	int r, k, b, n = 10;
	int a[10];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 101 - 50;
		cout << a[i] << " ";
	}
	cout << endl << "enter k" << endl;
	cin >> k;
	cout << "1. move array k times to the left" << endl << "2. move array k times to the right" << endl;
	cin >> b;
	if (b == 2)
	{
		for (int i = 0; i < k; i++)
		{
			r = a[n - 1];
			for (int j = n - 1; j > 0; j--)
			{
				a[j] = a[j - 1];
			}
			a[0] = r;
		}
	}
	if (b == 1)
	{
		for (int i = 0; i < k; i++)
		{
			r = a[0];
			for (int j = 0; j < n - 1; j++)
			{
				a[j] = a[j + 1];
			}
			a[n - 1] = r;
		}
	}
	for (int i = n - 1; i > n - k - 1; i--)
	{
		cout << a[i] << " ";
	}
	for (int i = 0; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
```
# 3) Блок-схема
![lab_4 drawio](https://github.com/wpslll/Labs_PSTU_2023/assets/151571121/83f5a443-7e21-490a-a0e4-35e840be9f9c)
# 4) Тесты
```cpp
-9 35 22 -12 30 19 15 18 46 -28
enter k
3
1. move array k times to the left
2. move array k times to the right
1
22 35 -9
30 19 15

-9 35 22 -12 30 19 15 18 46 -28
enter k
5
1. move array k times to the left
2. move array k times to the right
2
30 -12 22 35 -9
15 18 46 -28 -9

-9 35 22 -12 30 19 15 18 46 -28
enter k
8
1. move array k times to the left
2. move array k times to the right
1
18 15 19 30 -12 22 35 -9
-28 -9 35 22 -12 30 19 15
```
