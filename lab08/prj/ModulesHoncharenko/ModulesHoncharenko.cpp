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
    string vowels = "AEIOUАЕІЇОУЮЯaeiouаеіїоуюя";
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

    string inputText((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());

    inputFile.close();

    ofstream outputFile(output);
    if (!outputFile.is_open()) {
        cout << "Неможливо відкрити файл!";
        return;
    }

    outputFile << "Авторська інформація: \nІм'я та прізвище розробника модуля: Гончаренко Влад, \nУстанова/організація: ЦНТУ, \nМісто: Кропівницький, \nКраїна: Україна, \nРік розробки: 2024\n";

    int vowelCount = countVowels(inputText);
    outputFile << "\nКількість голосних літер у слові з вхідного файла: " << vowelCount;

    string poem = "\nДо щастя не пускає лінощів орава.\nУ чім воно - ніхто не знає до пуття.\nНавчитись радісно робити кожну справу -\nНайперше правило щасливого життя.";
    bool containsWordInPoem = containsWord(poem, inputText);
    outputFile << "\nСлово з вхідного файлу " << (containsWordInPoem ? "є" : "не є") << " у вірші Віталя Іващенка";

    outputFile.close();

    cout << "\nОбробку завершено. Висновок записаний у " << output;
}

//Task 10.2
// Function for counting the number of consonants in a word
int countConsonants(string word) {
    int countCons = 0;
    for (char& ch : word) {
        char lowercase_ch = tolower(ch);
        if ((lowercase_ch >= 'a' && lowercase_ch <= 'z') || (lowercase_ch >= 'а' && lowercase_ch <= 'я')) {
            if (!isvowel(lowercase_ch)) {
                countCons++;
            }
        }
    }
    return countCons;
}



// Function to append the number of consonant letters, date, and time to the output file
void writeToInputFile(const string& input) {
    ofstream inputFile(input, ios_base::app);
    if (!inputFile.is_open()) {
        cout << "Неможливо відкрити файл!";
        return;
    }

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

    inputFile << "\nКількість приголосних літер у тексті: " << consonantCount << endl;
    inputFile << "\nДата та час дозапису: " << timeBuffer << endl;

    inputFile.close();

    cout << "Дані успішно записано у вхідний файл!";
}

//Task 10.3
// Функція для обчислення результату за допомогою s_calculation


// Функція для переведення числа у двійковий формат
string BinaryNum(int b) {
    if (b == 0)
        return "0";
    string binary = "";
    while (b > 0){
        binary = to_string(b % 2) + binary;
        b = b / 2;
    }
    return binary;
}

// Функція для вирішення задачі 10.3
void solveTask103(const string& input, const string& output) {
    double x, y, z;
    int b;

    // Зчитуємо вхідні дані з файлу
    ifstream inputFile(input);
    if (!inputFile.is_open()) {
        cout << "Неможливо відкрити вхідний файл!" << endl;
        return;
    }
    inputFile >> x >> y >> z >> b;
    inputFile.close();

    // Відкриваємо файл для запису результатів
    ofstream outputFile(output, ios::app); // Використовуємо режим ios::app, щоб дописувати до вмісту файлу
    if (!outputFile.is_open()) {
        cout << "Неможливо відкрити вихідний файл!" << endl;
        return;
    }

    // Викликаємо функцію s_calculation та записуємо результат у файл
    double resultS_calc = s_calculation(x, y, z);
    outputFile << "\nРезультат виконання s_calculation з аргументами " << x << ", " << y << ", " << z << ": " << resultS_calc << endl;

    // Записуємо число b у двійковому коді у файл
    string resultBinary = BinaryNum(b);
    outputFile << "Число " << b << " у двійковому коді: " << resultBinary << endl;

    outputFile.close();

    cout << "Результати записані у файл " << output << endl;
}

