#include <iostream>
#include <cmath>
#include <string>
#include <windows.h>
#include "ModulesHoncharenko.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");

    char choice;
    bool exit = false;

    while (!exit) {
        cout << "������ ������ ('q' - s_caclulation, 'e' - ������ 9.1, 'r' - ������ 9.2, 't' - ������ 9.3, 'y' ��� '�' - �����): ";
        cin >> choice;

        switch (choice) {
            case 'q': {
                double x, y, z;
                cout << "������ �������� x, y �� z: ";
                cin >> x >> y >> z;
                cout << "��������� ����������: " << s_calculation(x, y, z) << endl;
                break;
            }
            case 'e': {
                double grade, waveHeight;
                string seaDescription;
                cout << "������ ��� (0 - 9): ";
                cin >> grade;
                calcWave(grade, waveHeight, seaDescription);
                cout << "������ ����: " << waveHeight << " �����\n";
                cout << "����: " << seaDescription << "\n\n";
                break;
            }
            case 'r': {
                int n, negativeCount, zeroCount, rangeCount;
                cout << "������ n ������� �����: ";
                cin >> n;
                countNumbers(n, negativeCount, zeroCount, rangeCount);
                cout << "³�'��� �����: " << negativeCount << endl;
                cout << "�����, �� = ����: " << zeroCount << endl;
                cout << "ĳ������ �� [5 - 1024]: " << rangeCount << endl;
                break;
            }
            case 't': {
                unsigned int N;
                bool D1;
                int binaryCount;
                cout << "������ ����� N: ";
                cin >> N;
                calcBinaryInfo(N, D1, binaryCount);
                cout << "��� D1 ����� N: " << (D1 ? "1" : "0") << endl;
                cout << "ʳ������ �������� " << (D1 ? "����" : "�������") << " � ���� N: " << binaryCount << endl;
                break;
            }
            case 'y':
            case '�': {
                exit = true;
                break;
            }
            default: {
                Beep(500, 300); // �������� ������ � ��� ������������� ��������
                cout << "������������ ���! ���� �����, ������ 'q', 'e', 'r', 't', 'y' ��� '�'.\n";
                break;
            }
        }
    }

    return 0;
}
