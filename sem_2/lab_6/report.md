# 1) Задание
Преобразовать строку таким образом, чтобы в ней
остались только слова, содержащие буквы и цифры,
остальные слова удалить.
# 2) Код программы
```cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int r, n = 20;
	char c[20];
	fgets(c, sizeof(c), stdin);
	for (int i = 0; i < n; i++)
	{
		if (c[i] == '~' || c[i] == '!' || c[i] == '@' || c[i] == '#' || c[i] == '$' || c[i] == '%' || c[i] == '^' || c[i] == '&' || c[i] == '*' || c[i] == '(' || c[i] == ')' || c[i] == '-' || c[i] == '+' || c[i] == '_' || c[i] == '=' || c[i] == '`' || c[i] == '/' || c[i] == '.' || c[i] == ',' || c[i] == '?' || c[i] == '"' || c[i] == ':' || c[i] == ';' || c[i] == ']' || c[i] == '[' || c[i] == '{' || c[i] == '}' || c[i] == '|' || c[i] == '№')
		{
			c[i] = 0;
		}
	}
	for (int i = 0; i < 20; i++)
	{
		cout << c[i];
	}
	return 0;
}
```
# 3) Блок-схема
![lab_6 drawio](https://github.com/wpslll/Labs_PSTU_2023/assets/151571121/2f07b790-ba89-4c52-87f5-a85d1d2c0d2c)
# 4) Тесты
he@l$lo w%or*ld
hello world

he^^^^^llo w***orld
hello world

n=+umb!er
number
