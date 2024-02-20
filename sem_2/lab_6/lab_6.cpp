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