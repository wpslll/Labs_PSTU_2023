#include <iostream>
#include <string>
#include <wctype.h>
using namespace std;
int main()
{
	int countC = 0, countV = 0;
	std::wstring st;
	std::wcin >> st;
	const wchar_t* pt = st.c_str();
	for (int i = 0; i < st.length(); i++)
	{
		if (towlower(*pt) == 'у' || towlower(*pt) == 'е' || towlower(*pt) == 'ы' || towlower(*pt) == 'а' || towlower(*pt) == 'о' || towlower(*pt) == 'э' || towlower(*pt) == 'я' || towlower(*pt) == 'и' || towlower(*pt) == 'ю')
		{
			countV++;
		}
		else
		{
			countC++;
		}
		pt++;
	}
	cout << countC << "   " << countV;
	return 0;
}