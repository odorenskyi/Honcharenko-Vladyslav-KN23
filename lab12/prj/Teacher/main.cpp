#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include "ClassLab12_Honcharenko.h"

#define TEST_SUITE_FILE "..\\..\\TestSuite\\TestSuite.txt"
#define TEST_RESULTS_FILE "..\\..\\TestSuite\\TestResults.txt"

using namespace std;

int main()
{
    system("chcp 1251 & cls");

    string currentFilePath = __FILE__;
    int checkResult = currentFilePath.find("\\lab12\\prj\\");
    if (checkResult == -1) {
        for (int i = 0; i < 100; ++i) {
            Beep(500, 100);
        }

        ofstream resultFile(TEST_RESULTS_FILE);
        if (resultFile.is_open()) {
            resultFile << "Помилка: програма запущена не від кореневої теки проекту!";
            resultFile.close();
        } else {
            cerr << "Помилка: не вдається відкрити файл для запису результатів.";
            return 1;
        }
    } else {
        ifstream inputFile(TEST_SUITE_FILE);
        ofstream outputFile(TEST_RESULTS_FILE);
        string line;
        int testCase = 0;

        while (getline(inputFile, line)) {
            stringstream ss(line);
            double radius, diameter;

            ss >> radius;
            ss.ignore(1, '|');
            ss >> diameter;

            try {
                ClassLab12_Honcharenko testObject(radius, diameter);

                testCase += 1;
                outputFile << "Тест " << testCase << endl;
                outputFile << "Радіус об'єкта: " << testObject.getRadius() << endl;
                outputFile << "Діаметр об'єкта: " << testObject.getDiameter() << endl;
                outputFile << "Площа об'єкта: " << testObject.calculateArea() << endl << endl;
            } catch (const std::invalid_argument& e) {
                testCase += 1;
                outputFile << "Тест " << testCase << " (помилка): " << e.what() << endl << endl;
            }
        }

        cout << "Тестування завершено, результати збережено у файлі TestResults.txt" << endl;
        system("pause");

        inputFile.close();
        outputFile.close();
    }

    return 0;
}
