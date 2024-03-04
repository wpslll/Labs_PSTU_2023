# 1) Задание
Задан двумерный массив. Найти сумму элементов
первого столбца без одного последнего элемента, сумму
элементов второго столбца без двух последних, сумму
элементов третьего столбца без трех последних и т. д.
Последний столбец не обрабатывается. Среди найденных
сумм найти максимальную.
# 2) Код программы
```cpp
#include <iostream>
using namespace std;
int main()
{
	int a[4][4], n = 4, s, l = 3, max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 101 - 50;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	for (int j = 0; j < n - 1; j++)
	{
		s = 0;
		for (int i = 0; i < l; i++)
		{
			s += a[i][j];
		}
		cout << s << endl;
		if (s > max)
		{
			max = s;
		}
		l--;
	}
	cout << "max sum is " << max;
	return 0;
}
```
# 3) Блок-схема
![lab_5 drawio](https://github.com/wpslll/Labs_PSTU_2023/assets/151571121/29cae1d3-9ffd-45da-bce9-adf83240368f)
# 4) Тесты
-9 35 22 -12
30 19 15 18
46 -28 -1 17
1 11 13 37
67
54
22
max sum is 67
