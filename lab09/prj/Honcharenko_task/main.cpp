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
        cout << "Введіть символ ('q' - s_caclulation, 'e' - задача 9.1, 'r' - задача 9.2, 't' - задача 9.3, 'y' або 'н' - вихід): ";
        cin >> choice;

        switch (choice) {
            case 'q': {
                double x, y, z;
                cout << "Введіть значення x, y та z: ";
                cin >> x >> y >> z;
                cout << "Результат обчислення: " << s_calculation(x, y, z) << endl;
                break;
            }
            case 'e': {
                double grade, waveHeight;
                string seaDescription;
                cout << "Введіть бал (0 - 9): ";
                cin >> grade;
                calcWave(grade, waveHeight, seaDescription);
                cout << "Висота хвилі: " << waveHeight << " метрів\n";
                cout << "Опис: " << seaDescription << "\n\n";
                break;
            }
            case 'r': {
                int n, negativeCount, zeroCount, rangeCount;
                cout << "Введіть n кількість чисел: ";
                cin >> n;
                countNumbers(n, negativeCount, zeroCount, rangeCount);
                cout << "Від'ємні числа: " << negativeCount << endl;
                cout << "Числа, які = нулю: " << zeroCount << endl;
                cout << "Діапазон від [5 - 1024]: " << rangeCount << endl;
                break;
            }
            case 't': {
                unsigned int N;
                bool D1;
                int binaryCount;
                cout << "Введіть число N: ";
                cin >> N;
                calcBinaryInfo(N, D1, binaryCount);
                cout << "Біт D1 числа N: " << (D1 ? "1" : "0") << endl;
                cout << "Кількість двійкових " << (D1 ? "нулів" : "одиниць") << " у числі N: " << binaryCount << endl;
                break;
            }
            case 'y':
            case 'н': {
                exit = true;
                break;
            }
            default: {
                Beep(500, 300); // Звуковий сигнал у разі неправильного введення
                cout << "Неправильний ввід! Будь ласка, введіть 'q', 'e', 'r', 't', 'y' або 'н'.\n";
                break;
            }
        }
    }

    return 0;
}
