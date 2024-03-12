# 1) Задание
Сформировать двумерный массив. Удалить из него
строку и столбец, на пересечении которых находится
максимальный элемент.
# 2) Код программы
```cpp
#include <iostream>
using namespace std;
int** make_matr(int n)
{
	int** matr;
	matr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			matr[i][j] = rand() % 10;
		}
	}
	return matr;
}
int main()
{
	int n, max = INT_MIN, x = 0, y;
	cin >> n;
	int** matr = make_matr(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matr[i][j] > max)
			{
				max = matr[i][j];
				x = i;
				y = j;
			}
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	int matr1[4][4] = { 0 };
	for (int i = x; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			matr1[i][j] = matr[i + 1][j];
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = y; j < n - 1; j++)
		{
			matr1[i][j] = matr[i][j + 1];
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			cout << matr1[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
```
# 3) Блок-схема
![lab_10_main drawio](https://github.com/wpslll/Labs_PSTU_2023/assets/151571121/5ff01a0f-e585-4af1-af96-807622a97787)
![lab_10_make_matr drawio](https://github.com/wpslll/Labs_PSTU_2023/assets/151571121/c03daf3c-482d-47f4-bef5-afa1a9126397)
# 4) Тесты
```cpp
n = 5;
1 7 4 0 9
4 8 8 2 4
5 5 1 7 1
1 5 2 7 6
1 4 2 3 2

4 8 8 2
5 5 1 7
1 5 2 7
1 4 2 3
```
