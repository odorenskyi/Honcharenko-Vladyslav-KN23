#include "ModulesHoncharenko.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    system("chcp 1251 & cls");

    string inputFileName = "input.txt";
    string outputFileName = "output.txt";

    //processFiles(inputFileName, outputFileName);

    //writeToInputFile(inputFileName);

    solveTask103(inputFileName, outputFileName);

    return 0;
}
