#include <cmath>
#include <iostream>
#include <string>

using namespace std;

double s_calculation(double x, double y, double z) {
    return z * sin(pow(x, 2) * y) + sqrt(fabs(z - 12 * x)) / pow(y, 3);
}

void calcWave(double grade, double& waveHeight, std::string& seaDescription) {
    if (grade < 0 || grade > 9) {
        waveHeight = 0;
        seaDescription = "Некоректний бал за шкалою ВМО.";
    } else {
        if (grade == 0) {
            waveHeight = 0;
            seaDescription = "CALM-GLASSY";
        } else if (grade == 1) {
            waveHeight = 0.1;
            seaDescription = "CALM-RIPPLED";
        } else if (grade == 2) {
            waveHeight = 0.5;
            seaDescription = "SMOOTH-WAVELET";
        } else if (grade == 3) {
            waveHeight = 1.25;
            seaDescription = "SLIGHT";
        } else if (grade == 4) {
            waveHeight = 2.50;
            seaDescription = "MODERATE";
        } else if (grade == 5) {
            waveHeight = 4.0;
            seaDescription = "ROUGHT";
        } else if (grade == 6) {
            waveHeight = 6.0;
            seaDescription = "VERY ROUGHT";
        } else if (grade == 7) {
            waveHeight = 9.0;
            seaDescription = "HIGHT";
        } else if (grade == 8) {
            waveHeight = 14.0;
            seaDescription = "VERY HIGHT";
        } else if (grade == 9) {
            waveHeight = 14.0;
            seaDescription = "PHENOMENAL";
        }
    }
}
void countNumbers(int n, int& negativeCount, int& zeroCount, int& rangeCount) {
    negativeCount = 0;
    rangeCount = 0;
    zeroCount = 0;

    for (int i = 0; i < n; ++i) {
        int num;
        cout << "Введіть число " << (i + 1) << ": ";
        cin >> num;

        if (num < 0) {
            negativeCount++;
        } else if (num == 0) {
            zeroCount++;
        } else if (num >= 5 && num <= 1024) {
            rangeCount++;
        }
    }
}

void calcBinaryInfo(unsigned int N, bool& D1, int& binaryCount) {
    D1 = (N & 1) == 1;
    binaryCount = 0;

    while (N > 0) {
        if (D1) {
            binaryCount += (N % 2 == 0) ? 1 : 0;
        } else {
            binaryCount += (N % 2 == 1) ? 1 : 0;
        }
        N /= 2;
    }
}
