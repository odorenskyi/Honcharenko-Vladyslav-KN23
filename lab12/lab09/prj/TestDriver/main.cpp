#include <iostream>
#include <string>
#include "ModulesHoncharenko.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");

    //Task 9.1
    double grade, waveHeight;
    std::string seaDescription;

    cout << "������ ��� ( 0 - 9 ): ";
    cin >> grade;

    calcWave(grade, waveHeight, seaDescription);

    cout << "������ ����: " << waveHeight << "�����\n";
    cout << "����: " << seaDescription << "\n\n";

    //Task 9.2
    int n, negativeCount, zeroCount, rangeCount;

    cout << "������ n ������� �����: ";
    cin >> n;

    countNumbers(n, negativeCount, zeroCount, rangeCount);

    cout << "³�'��� �����: " << negativeCount << endl;
    cout << "����� �� = ����: " << zeroCount << endl;
    cout << "ĳ������ �� [5 - 1024]: " << rangeCount << endl;

    return 0;
}
