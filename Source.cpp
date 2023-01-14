#include <iostream>
#include <string>
using namespace std;

// �������, ����������� ��������� ������
void IsKPeriodic(int K, const string& txt)
{
    // ��������� ������� ������ K > 0
    if (K <= 0)
    {
        cout << "� ������ ���� ������ 0" << endl;
    }

    // ���� ����� ������ �� ������ �, �� � ���� ������ �� ������ �
    if (txt.size() % K != 0)
    {
        cout << "������ " << txt << " �� ������ � = " << K << endl;
        exit(0);
    }

    // ������� ��������� ������������� �������� �
    string pat;
    for (int i = 0; i < K; ++i)
    {
        pat.push_back(txt[i]);
    }

    // ������ ������
    int i = 0;

    // ���� ��������� pat � ������ txt
    while (i < txt.size())
    {
        // ������ ���������
        int j = 0;

        // ��������� ������������� ������
        while (j < K)
        {
            if (pat[j] == txt[j + i])
            {
                j++;
            }
            else
            {
                cout << "������ " << txt << " �� ������ � = " << K << endl;
                exit(0);
            }
        }

        i += K;
    }

    cout << "������ " << txt << " ������ � = " << K << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    
    string txt;
    int K;

    cout << "������� ������: ";
    cin >> txt;
    cout << "������� �����, �������� ������ ���� ������ ������: ";
    cin >> K;

    IsKPeriodic(K, txt);

    return 0;
}