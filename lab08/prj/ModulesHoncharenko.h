// ModulesHoncharenko.h (Заголовок функції)
#ifndef MODULES_HONCHARENKO_H
#define MODULES_HONCHARENKO_H
#include <string>

using namespace std;

double s_calculation(double x, double y, double z);

void calcWave(double grade, double& waveHeight, std::string& seaDescription);

void countNumbers(int n, int& negativeCount, int& zeroCount, int& rangeCount);

void calcBinaryInfo(unsigned int N, bool& D1, int& binaryCount);

//Task 10.1
int countVowels(string word);

bool containsWord(const string& poem, const string& word);

void processFiles(const string& input, const string& output);

//Task 10.2
int countConsonants(string word);

void writeToInputFile(const string& input);

//Task 10.3

string BinaryNum(int b);

void solveTask103(const string& input, const string& output);

#endif // MODULES_HONCHARENKO_H
