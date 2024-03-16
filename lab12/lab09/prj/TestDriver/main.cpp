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

    return 0;
}
