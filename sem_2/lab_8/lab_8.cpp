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