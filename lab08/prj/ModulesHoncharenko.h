// ModulesHoncharenko.h (Заголовок функції)
#ifndef MODULES_HONCHARENKO_H
#define MODULES_HONCHARENKO_H

double s_calculation(double x, double y, double z);

void calcWave(double grade, double& waveHeight, std::string& seaDescription);

void countNumbers(int n, int& negativeCount, int& zeroCount, int& rangeCount);

void calcBinaryInfo(unsigned int N, bool& D1, int& binaryCount);

int countVowels(string word);

bool checkWordInVerse(string word);

void processFiles(const string& input, const string& output);

int countConsonants(string word);

void writeToInputFile(const string& input);

double calcS_calculation (double x, double y, double z);

string BinaryNum(int n);

#endif // MODULES_HONCHARENKO_H
