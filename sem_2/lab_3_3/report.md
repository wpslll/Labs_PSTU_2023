# 1) Задание
Решить ханойскую башню с заданным кол-вом блинов через рекурсию.
# 2) Код программы
```cpp
#include <iostream>
using namespace std;
void f(int n, int i, int j)
{
	if (n == 1)
	{
		cout << "moving circle " << n << " from pin " << i << " to pin " << j << endl;
	}
	else
	{
		int tmp = 6 - i - j;
		f(n - 1, i, tmp);
		cout << "moving circle " << n << " from pin " << i << " to pin " << j << endl;
		f(n - 1, tmp, i);
	}
}
int main()
{
	f(3, 1, 2);
	return 0;
}
```
# 3) Блок-схема
![lab_3_3_main drawio](https://github.com/wpslll/Labs_PSTU_2023/assets/151571121/afc95832-adab-454c-9e33-9989e85f96bd)
![lab_3_3_f drawio](https://github.com/wpslll/Labs_PSTU_2023/assets/151571121/77faf4e9-fd67-41ee-8e5c-2c678b52e31b)
# 4)Тесты
```cpp
3 блина;
moving circle 1 from pin 1 to pin 2
moving circle 2 from pin 1 to pin 3
moving circle 1 from pin 2 to pin 1
moving circle 3 from pin 1 to pin 2
moving circle 1 from pin 3 to pin 2
moving circle 2 from pin 3 to pin 1
moving circle 1 from pin 2 to pin 3
4 блина;
moving circle 1 from pin 1 to pin 3
moving circle 2 from pin 1 to pin 2
moving circle 1 from pin 3 to pin 1
moving circle 3 from pin 1 to pin 3
moving circle 1 from pin 2 to pin 3
moving circle 2 from pin 2 to pin 1
moving circle 1 from pin 3 to pin 2
moving circle 4 from pin 1 to pin 2
moving circle 1 from pin 3 to pin 1
moving circle 2 from pin 3 to pin 2
moving circle 1 from pin 1 to pin 3
moving circle 3 from pin 3 to pin 1
moving circle 1 from pin 2 to pin 1
moving circle 2 from pin 2 to pin 3
moving circle 1 from pin 1 to pin 2
2 блина;
moving circle 1 from pin 1 to pin 3
moving circle 2 from pin 1 to pin 2
moving circle 1 from pin 3 to pin 1
```
