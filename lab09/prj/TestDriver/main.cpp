#include <iostream>
#include <string>
#include "ModulesHoncharenko.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");

    //Task 9.1
    double grade, waveHeight;
    std::string seaDescription;

    cout << "Введіть бал ( 0 - 9 ): ";
    cin >> grade;

    calcWave(grade, waveHeight, seaDescription);

    cout << "Висота хвилі: " << waveHeight << "метрів\n";
    cout << "Опис: " << seaDescription << "\n\n";

    //Task 9.2
    int n, negativeCount, zeroCount, rangeCount;

    cout << "Введіть n кількість чисел: ";
    cin >> n;

    countNumbers(n, negativeCount, zeroCount, rangeCount);

    cout << "Від'ємні числа: " << negativeCount << endl;
    cout << "Числа які = нулю: " << zeroCount << endl;
    cout << "Діапазон від [5 - 1024]: " << rangeCount << endl;

    //Task 9.3
    unsigned int N;
    bool D1;
    int binaryCount;

    cout << "Введіть число N: ";
    cin >> N;

    calcBinaryInfo(N, D1, binaryCount);

    if (D1) {
        cout << "Біт D1 числа N рівний 1." << endl;
        cout << "Кількість двійкових нулів у числі N: " << binaryCount << endl;
    } else {
        cout << "Біт D1 числа N рівний 0." << endl;
        cout << "Кількість двійкових одиниць у числі N: " << binaryCount << endl;
    }

    return 0;
}
