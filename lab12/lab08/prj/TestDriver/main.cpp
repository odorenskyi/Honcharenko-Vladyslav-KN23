#include <iostream>
#include "ModulesHoncharenko.h"
using namespace std;

int main()
{
    cout << s_calculation << endl;
    setlocale(LC_ALL, "ukr");
    double x, y, z;
    std::cout << "������� �������� x: ";
    std::cin >> x;
    std::cout << "������� �������� y: ";
    std::cin >> y;
    std::cout << "������� �������� z: ";
    std::cin >> z;

    double result = s_calculation(x, y, z);

    std::cout << "�������� S = " << result << std::endl;

    return 0;
}
