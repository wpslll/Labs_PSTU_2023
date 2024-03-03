# 1) Задание 
Заполнить двумерный массив в шахматном порядке.
# 2) Код программы
```cpp
#include <iostream>
using namespace std;
int main()
{
	int n = 5;
	int a[5][5];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i + j + 2) % 2 == 0)
			{
				a[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j];

		}
		cout << endl;
	}
	return 0;
}
```
# 3) Блок-схема
![lab_1 drawio](https://github.com/wpslll/Labs_PSTU_2023/assets/151571121/f4c8a7d8-7273-4f6c-817e-6cc6c308f435)
# 4) Тесты
n = 5
10101
01010
10101
01010
10101
n = 10
1010101010
0101010101
1010101010
0101010101
1010101010
0101010101
1010101010
0101010101
1010101010
0101010101
n = 2
10
01
