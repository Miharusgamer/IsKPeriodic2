#include <iostream>
#include <string>
using namespace std;

// Функция, проверяющая кратность строки
void IsKPeriodic(int K, const string& txt)
{
    // Проверяем условие задачи K > 0
    if (K <= 0)
    {
        cout << "К должно быть больше 0" << endl;
    }

    // Если длина строки не кратна К, то и сама строка не кратна К
    if (txt.size() % K != 0)
    {
        cout << "Строка " << txt << " не кратна К = " << K << endl;
        exit(0);
    }

    // Находим подстроку повторяемости размером К
    string pat;
    for (int i = 0; i < K; ++i)
    {
        pat.push_back(txt[i]);
    }

    // индекс строки
    int i = 0;

    // Ищем подстроку pat в строке txt
    while (i < txt.size())
    {
        // индекс подстроки
        int j = 0;

        // Проверяем повторяемость строки
        while (j < K)
        {
            if (pat[j] == txt[j + i])
            {
                j++;
            }
            else
            {
                cout << "Строка " << txt << " не кратна К = " << K << endl;
                exit(0);
            }
        }

        i += K;
    }

    cout << "Строка " << txt << " кратна К = " << K << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    
    string txt;
    int K;

    cout << "Введите строку: ";
    cin >> txt;
    cout << "Введите число, которому должна быть кратна строка: ";
    cin >> K;

    IsKPeriodic(K, txt);

    return 0;
}