#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include "ModulesHoncharenko.h"

void printDeveloperInfo() {
    std::cout << "���������� ��������� �. �� ����� �������." << std::endl;
}

void LogicalResult(int  a, int  b) {
     std::cout << "��������� �������� ������ a + 1 = b + 2: " << std::boolalpha << (a + 1 == b + 2) << std::endl;
}

void NumericalSystems(double x, double y, double z) {
    std::cout << "�������� x: " << x << " (10-��), " << std::hex << std::showbase << x << " (16-��)" << std::endl;
    std::cout << "�������� y: " << y << " (10-��), " << std::hex << std::showbase << y << " (16-��)" << std::endl;
    std::cout << "�������� z: " << z << " (10-��), " << std::hex << std::showbase << z << " (16-��)" << std::endl;

    double S = s_calculation(x, y, z);
    std::cout << "�������� S, �� ������������ �������� s_calculation(): " << S << std::dec << std::endl;
}

int main() {
    setlocale(LC_ALL, "ukr");
    double x, y, z;
    int a, b;
    std::cout << "������ �������� x: ";
    std::cin >> x;
    std::cout << "������ �������� y: ";
    std::cin >> y;
    std::cout << "������ �������� z: ";
    std::cin >> z;
    std::cout << "������ �������� a: ";
    std::cin >> a;
    std::cout << "������ �������� b: ";
    std::cin >> b;

    printDeveloperInfo();
    LogicalResult(a, b);
    NumericalSystems(x, y, z);

    return 0;
}
