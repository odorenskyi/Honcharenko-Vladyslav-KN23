#include <cmath>

double s_calculation(double x, double y, double z) {
    return z * sin(pow(x, 2) * y) + sqrt(fabs(z - 12 * x)) / pow(y, 3);
}
