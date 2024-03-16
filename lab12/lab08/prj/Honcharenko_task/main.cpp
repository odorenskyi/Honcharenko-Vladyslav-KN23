#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include "ModulesHoncharenko.h"

void printDeveloperInfo() {
    std::cout << "Гончаренко Владислав ©. Усі права захищіні." << std::endl;
}

void LogicalResult(int  a, int  b) {
     std::cout << "Результат логічного виразу a + 1 = b + 2: " << std::boolalpha << (a + 1 == b + 2) << std::endl;
}

void NumericalSystems(double x, double y, double z) {
    std::cout << "Значення x: " << x << " (10-вій), " << std::hex << std::showbase << x << " (16-вій)" << std::endl;
    std::cout << "Значення y: " << y << " (10-вій), " << std::hex << std::showbase << y << " (16-вій)" << std::endl;
    std::cout << "Значення z: " << z << " (10-вій), " << std::hex << std::showbase << z << " (16-вій)" << std::endl;

    double S = s_calculation(x, y, z);
    std::cout << "Значення S, що обчислюється функцією s_calculation(): " << S << std::dec << std::endl;
}

int main() {
    setlocale(LC_ALL, "ukr");
    double x, y, z;
    int a, b;
    std::cout << "Введіть значення x: ";
    std::cin >> x;
    std::cout << "Введіть значення y: ";
    std::cin >> y;
    std::cout << "Введіть значення z: ";
    std::cin >> z;
    std::cout << "Введіть значення a: ";
    std::cin >> a;
    std::cout << "Введіть значення b: ";
    std::cin >> b;

    printDeveloperInfo();
    LogicalResult(a, b);
    NumericalSystems(x, y, z);

    return 0;
}
