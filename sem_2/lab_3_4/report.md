# 1) Задание
Расставить 8 ферзей через рекурсию так, чтобы они не били друг друга
# 2) Код программы
```cpp
#include <iostream>
using namespace std;
int board[8][8];
int n = 1;
void show()
{
	for (int a = 0; a < 8; a++)
	{
		for (int b = 0; b < 8; b++)
		{
			cout << ((board[a][b]) ? "[q] " : "[ ] ");
		}
		cout << endl << endl;
	}
}
bool check(int a, int b)
{
	for (int i = 0; i < a; i++)
	{
		if (board[i][b] == 1)
		{
			return false;
		}
	}
	for (int i = 1; i <= a && b - 1 >= 0; i++)
	{
		if (board[a - i][b - i] == 1)
		{
			return false;
		}
	}
	for (int i = 1; i <= a && b + i < 8; i++)
	{
		if (board[a - i][b + i] == 1)
		{
			return false;
		}
	}
	return true;
}
void set(int a)
{
	if (a == 8)
	{
		show();
		cout << " №" << n++ << endl << endl;
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		if (check(a, i))
		{
			board[a][i] = 1;
			set(a + 1);
			board[a][i] = 0;
		}
	}
	return;
}
int main()
{
	set(0);
	return 0;
}
```
# 3) Блок-схема
![lab_3_4_main drawio](https://github.com/wpslll/Labs_PSTU_2023/assets/151571121/64fa27a7-07a6-4ae0-b96b-3f2f64d9079f)
![lab_3_4_show drawio](https://github.com/wpslll/Labs_PSTU_2023/assets/151571121/bdc91906-bc00-46bd-9e92-55ef4c835d5b)
![lab_3_4_check drawio](https://github.com/wpslll/Labs_PSTU_2023/assets/151571121/613d5905-54d8-4b1f-a2b5-4873d5346032)
![lab_3_4_set drawio](https://github.com/wpslll/Labs_PSTU_2023/assets/151571121/37cf438d-f4da-4a74-8962-48a6686c7665)
# 4) Тесты
[ ] [q] [ ] [ ] [ ] [ ] [ ] [ ]

[ ] [ ] [ ] [q] [ ] [ ] [ ] [ ]

[ ] [ ] [ ] [ ] [ ] [q] [ ] [ ]

[ ] [ ] [ ] [ ] [ ] [ ] [ ] [q]

[ ] [ ] [q] [ ] [ ] [ ] [ ] [ ]

[q] [ ] [ ] [ ] [ ] [ ] [ ] [ ]

[ ] [ ] [ ] [ ] [ ] [ ] [q] [ ]

[ ] [ ] [ ] [ ] [q] [ ] [ ] [ ]

 ╣1

[ ] [q] [ ] [ ] [ ] [ ] [ ] [ ]

[ ] [ ] [ ] [ ] [q] [ ] [ ] [ ]

[ ] [ ] [ ] [ ] [ ] [ ] [q] [ ]

[q] [ ] [ ] [ ] [ ] [ ] [ ] [ ]

[ ] [ ] [q] [ ] [ ] [ ] [ ] [ ]

[ ] [ ] [ ] [ ] [ ] [ ] [ ] [q]

[ ] [ ] [ ] [ ] [ ] [q] [ ] [ ]

[ ] [ ] [ ] [q] [ ] [ ] [ ] [ ]

 ╣2

[ ] [q] [ ] [ ] [ ] [ ] [ ] [ ]

[ ] [ ] [ ] [ ] [ ] [q] [ ] [ ]

[q] [ ] [ ] [ ] [ ] [ ] [ ] [ ]

[ ] [ ] [ ] [ ] [ ] [ ] [q] [ ]

[ ] [ ] [ ] [q] [ ] [ ] [ ] [ ]

[ ] [ ] [ ] [ ] [ ] [ ] [ ] [q]

[ ] [ ] [q] [ ] [ ] [ ] [ ] [ ]

[ ] [ ] [ ] [ ] [q] [ ] [ ] [ ]

 ╣3
