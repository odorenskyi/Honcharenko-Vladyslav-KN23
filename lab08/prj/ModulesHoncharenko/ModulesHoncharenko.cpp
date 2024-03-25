#include <cmath>
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

double s_calculation(double x, double y, double z) {
    return z * sin(pow(x, 2) * y) + sqrt(fabs(z - 12 * x)) / pow(y, 3);
}

// Function for Lab 9
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


// Function for Lab 10.1
// Function for counting the number of vowels in a word
int countVowels(string word) {
    int count = 0;
    string vowels = "aeiouаеіїоуюя";
    for (char& c : word) {
        if (vowels.find(c) != string::npos) {
            count++;
        }
    }
    return count;
}

// Function to check the presence of a word in the specified string
bool containsWord(const string& poem, const string& word) {
    return poem.find(word) != string::npos;
}

// Basic function for processing files
void processFiles(const string& input, const string& output) {
    ifstream inputFile(input);
    if (!inputFile.is_open()) {
        cout << "Неможливо відкрити файл!";
        return;
    }

    string inputText;
    getline(inputFile, inputText);

    inputFile.close();

    ofstream outputFile(output);
    if (!outputFile.is_open()) {
        cout << "Неможливо відкрити файл!";
        return;
    }

    outputFile << "Авторська інформація: \nІм'я та прізвище розробника модуля: Гончаренко Влад, \nУстанова/організація: ЦНТУ, \nМісто: Кропівницький, \nКраїна: Україна, \nРік розробки: 2024\n";

    int vowelCount = countVowels(inputText);
    outputFile << "Кількість голосних літер у слові з вхідного файла: " << vowelCount;

    string poem = "До щастя не пускає лінощів орава.\nУ чім воно - ніхто не знає до пуття.\nНавчитись радісно робити кожну справу -\nНайперше правило щасливого життя.";
    bool containsWordInPoem = containsWord(poem, inputText);
    outputFile << "Слово з вихідного файлу " << (containsWordInPoem ? "є" : "не є") << " у вірші Віталя Іващенка\n";

    outputFile.close();

    cout << "Обробку завершено. Висновок записаний у " << output;
}

//Task 10.2
int countConsonants(string word) {
    int countCons = 0;
    string consonants = "bcdfghjklmnpqrstvwxyzбвгґджзйклмнпрстфхцчшщюя";
    for (char& ch : word) {
        if (consonants.find(ch) != string::npos) {
            countCons++;
        }
    }
    return countCons;
}
// Function to write the number of consonant letters, date and time to the output file
void writeToInputFile(const string& input) {
    ofstream inputFile(input, ios_base::app);
    if (!inputFile.is_open()) {
        cout << "Неможливо відкрити файл!";
        return;
    }
// Time and date
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    char timeBuffer[50];
    strftime(timeBuffer, 50, "%Y-%m-%d %H:%M:%S", localTime);

    ifstream inputFileRead(input);
    if (!inputFileRead.is_open()) {
        cerr << "Unable to open input file for reading" << endl;
        return;
    }

    string fileContent((istreambuf_iterator<char>(inputFileRead)), istreambuf_iterator<char>());
    inputFileRead.close();

    int consonantCount = countConsonants(fileContent);

    inputFile << "Кількість приголосних літер у тексті: " << consonantCount;
    inputFile << "Дата та час дозапису: " << timeBuffer;

    inputFile.close();

    cout << "Дані успішно записано у вхідний файл!";
}

//Task 10.3
double calcS_calculation (double x, double y, double z) {
    return s_calculation(x, y, z);
}

string BinaryNum(int n) {
    if (n == 0)
        return "0";
    string binary = "";
    while (n > 0){
        binary = to_string(n % 2) + binary;
        n = n / 2;
    }
    return binary;
}
