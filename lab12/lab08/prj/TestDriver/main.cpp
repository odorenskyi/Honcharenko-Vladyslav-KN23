#include <iostream>
#include "ModulesHoncharenko.h"
using namespace std;

int main()
{
    cout << s_calculation << endl;
    setlocale(LC_ALL, "ukr");
    double x, y, z;
    std::cout << "¬ведите значение x: ";
    std::cin >> x;
    std::cout << "¬ведите значение y: ";
    std::cin >> y;
    std::cout << "¬ведите значение z: ";
    std::cin >> z;

    double result = s_calculation(x, y, z);

    std::cout << "«начение S = " << result << std::endl;

    return 0;
}
