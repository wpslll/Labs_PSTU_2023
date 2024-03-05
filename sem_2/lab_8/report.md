# 1) Задание
.Структура "Автомобиль":
- марка;
- год выпуска;
- цена;
- цвет.
Удалить все элементы, у которых год выпуска меньше
заданного, добавить элемент в начало файла.
# 2) Код программы
```cpp
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct car
{
	string brand;
	int year;
	int price;
	string colour;
};
int main()
{
	car lada_priora;
	lada_priora.brand = "lada";
	lada_priora.year = 2007;
	lada_priora.price = 200000;
	lada_priora.colour = "black";
	car toyota_camry;
	toyota_camry.brand = "toyota";
	toyota_camry.year = 2013;
	toyota_camry.price = 2750000;
	toyota_camry.colour = "white";
	car tesla_cybertruck;
	tesla_cybertruck.brand = "tesla";
	tesla_cybertruck.year = 2023;
	tesla_cybertruck.price = 16800000;
	tesla_cybertruck.colour = "silver";
	car mazda_miata;
	mazda_miata.brand = "mazda";
	mazda_miata.year = 1990;
	mazda_miata.price = 1700000;
	mazda_miata.colour = "blue";
	int n;
	cout << "Entetr year: ";
	cin >> n;
	ofstream f2("f.txt", ios::binary);
	if (lada_priora.year < n)
	{
		lada_priora.year = 0;
	}
	if (toyota_camry.year < n)
	{
		toyota_camry.year = 0;
	}
	if (tesla_cybertruck.year < n)
	{
		tesla_cybertruck.year = 0;
	}
	if (mazda_miata.year < n)
	{
		mazda_miata.year = 0;
	}
	string l;
	int l1;
	if (lada_priora.year != 0)
	{
		l = lada_priora.brand;
		f2 << "lada_priora:" << endl;
		f2 << l << endl;
		l1 = lada_priora.year;
		f2 << l1 << endl;
		l1 = lada_priora.price;
		f2 << l1 << endl;
		l = lada_priora.colour;
		f2 << l << endl << endl;
	}
	if (toyota_camry.year != 0)
	{
		l = toyota_camry.brand;
		f2 << "toyota_camry:" << endl;
		f2 << l << endl;
		l1 = toyota_camry.year;
		f2 << l1 << endl;
		l1 = toyota_camry.price;
		f2 << l1 << endl;
		l = toyota_camry.colour;
		f2 << l << endl << endl;
	}
	if (tesla_cybertruck.year != 0)
	{
		l = tesla_cybertruck.brand;
		f2 << "tesla_cybertruck:" << endl;
		f2 << l << endl;
		l1 = tesla_cybertruck.year;
		f2 << l1 << endl;
		l1 = tesla_cybertruck.price;
		f2 << l1 << endl;
		l = tesla_cybertruck.colour;
		f2 << l << endl << endl;
	}
	if (mazda_miata.year != 0)
	{
		l = mazda_miata.brand;
		f2 << "mazda_miata:" << endl;
		f2 << l << endl;
		l1 = mazda_miata.year;
		f2 << l1 << endl;
		l1 = mazda_miata.price;
		f2 << l1 << endl;
		l = mazda_miata.colour;
		f2 << l << endl << endl;
	}
	return 0;
}
```
# 3) Блок-схема
![lab_8_struct drawio](https://github.com/wpslll/Labs_PSTU_2023/assets/151571121/9dfa5e14-5d65-4b01-814f-0bff8d7b9677)
![lab_8_main drawio](https://github.com/wpslll/Labs_PSTU_2023/assets/151571121/c5931e04-0a19-40cc-85c4-65e5cc86f3a3)
# 4) Тесты
```cpp
Enter year: 2000
файл f:
lada_priora:
lada
2007
200000
black

toyota_camry:
toyota
2013
2750000
white

tesla_cybertruck:
tesla
2023
16800000
silver
```
