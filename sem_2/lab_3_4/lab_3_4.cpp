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
//[] [q] [] [] [] [] [] []

//[] [] [] [q] [] [] [] []

//[] [] [] [] [] [q] [] []

//[] [] [] [] [] [] [] [q]

//[] [] [q] [] [] [] [] []

//[q] [] [] [] [] [] [] []

//[] [] [] [] [] [] [q] []

//[] [] [] [] [q] [] [] []

//╣1

//[] [q] [] [] [] [] [] []

//[] [] [] [] [q] [] [] []

//[] [] [] [] [] [] [q] []

//[q] [] [] [] [] [] [] []

//[] [] [q] [] [] [] [] []

//[] [] [] [] [] [] [] [q]

//[] [] [] [] [] [q] [] []

//[] [] [] [q] [] [] [] []

//╣2

//[] [q] [] [] [] [] [] []

//[] [] [] [] [] [q] [] []

//[q] [] [] [] [] [] [] []

//[] [] [] [] [] [] [q] []

//[] [] [] [q] [] [] [] []

//[] [] [] [] [] [] [] [q]

//[] [] [q] [] [] [] [] []

//[] [] [] [] [q] [] [] []

//╣3