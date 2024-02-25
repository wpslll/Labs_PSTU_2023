# 1) Задание
1. Скопировать из файла F1 в файл F2 все строки,
заканчивающиеся на букву «А» и расположенные между
строками с номерами N1 и N2.
2. Определить номер той строки, в которой больше всего
букв «А», файла F2.
# 2) Код программы
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    int N1, N2;
    cout << "Enter N1, N2: ";
    cin >> N1 >> N2;
    ifstream F1("f1.txt");
    ofstream F2("f2.txt");
    string line;
    int lineNumber = 0;
    while (getline(F1, line))
    {
        lineNumber++;
        if (lineNumber >= N1 && lineNumber <= N2 && line[line.length() - 1] == 'A')
        {
            F2 << line << endl;
        }
    }
    F1.close();
    string l;
    int lNumber = 0;
    int maxCount = 0;
    int maxLineNumber = 0;
    ifstream F3("C:/Users/alexa/Desktop/f1.txt");
    while (getline(F3, l))
    {
        int count = 0;
        lNumber++;
        for (char c : l)
        {
            if (c == 'a')
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            maxLineNumber = lNumber;
        }
    }
    F3.close();
    cout << "Line with the biggest number of letter 'a': " << maxLineNumber << endl;
    return 0;
}
```
# 3) Блок-схема
![lab_9](https://github.com/wpslll/Labs_PSTU_2023/assets/151571121/500edca7-8a43-411e-ac6d-4f96c1439f85)
# 4) Тест
N1 = 1;
N2 = 7;

albania
austria
australia

