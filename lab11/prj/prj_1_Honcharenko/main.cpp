#include <iostream>
#include <ctime>
#include <fstream>
#include <conio.h>

#include "struct_type_project_1.h"
#include "ModulesHrebeniuk.h"
#include "ModulesHoncharenko.h"
#include "ModulesKlui.h"

#define REGISTER_NAME "register_database"

using namespace std;

void displayMenu() {
    system("cls");
    cout << " ======================= Ðåºñòð ÌÂÑ Óêðà¿íè ========================= " << endl;
    cout << "| 1. Äîäàòè àâòîìîá³ëü ó ðåºñòð                                      |" << endl;
    cout << "| 2. Ïîøóê àâòîìîá³ëÿ çà íîìåðîì                                     |" << endl;
    cout << "| 3. Âèäàëåííÿ àâòîìîá³ëÿ ç ðåºñòðó çà íîìåðíèì çíàêîì               |" << endl;
    cout << "| 4. Âèâåñòè óñ³ äàí³ ç ðåºñòðó                                      |" << endl;
    cout << "| 5. Âèéòè ç ïðîãðàìè                                                |" << endl;
    cout << " ==================================================================== " << endl;
    cout << "Âèáåð³òü îïö³þ: ";
}


void exitApp(List *list) {
    delete list->head;
    delete list->tail;
    delete list;

    exit(0);
}

int main()
{
    
    system("chcp 1251 & cls");
    
    List *list = loadRegisterData("register_database");
    if (list == nullptr) {
        list = new List;
        list->head = nullptr;
        list->tail = nullptr;
    }

    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
        system("cls");

        switch (choice) {
            case 1: {
                addCarInRegister(list);
                saveRegisterData(list, REGISTER_NAME);
                break;
            }
            case 2: {
                string searchLicensePlate;
                cout << "Ââåä³òü íîìåð àâòî äëÿ ïîøóêó: ";
                cin >> searchLicensePlate;

                if (searchLicensePlate.empty() || searchLicensePlate.size() > 10) {
                    cout << "Ïîìèëêà: íîìåðíèé çíàê íå ìîæå áóòè ïîðîæí³ì òà éîãî ìàêñèìàëüíà äîâæèíà ïîâèííà áóòè íå á³ëüøå 10 ñèìâîë³â!" << endl;
                    break;
                }

                searchCarInRegister(list, searchLicensePlate);
                break;
            }
            case 3: {
                string removeLicensePlate;
                cout << "Ââåä³òü íîìåð àâòî äëÿ âèäàëåííÿ: ";
                cin >> removeLicensePlate;

                if (removeLicensePlate.empty() || removeLicensePlate.size() > 10) {
                    cout << "Ïîìèëêà: íîìåðíèé çíàê íå ìîæå áóòè ïîðîæí³ì òà éîãî ìàêñèìàëüíà äîâæèíà ïîâèííà áóòè íå á³ëüøå 10 ñèìâîë³â!" << endl;
                    break;
                }

                removeCarFromRegister(list, removeLicensePlate);
                saveRegisterData(list, REGISTER_NAME);
                break;
            }
            case 4: {
                outputRegisterData(list);
                break;
            }
            case 5: {
                cout << "Äî ïîáà÷åííÿ!" << endl;
                exitApp(list);
                break;
            }
            default:
                cout << "Íåâ³ðíèé âèá³ð. Ñïðîáóéòå ùå ðàç." << endl;
        }

        cout << "Ïðîäîâæèòè ðîáîòó çàñòîñóíêó? (y/n): ";
        choice = getch();
    } while (choice == 'Y' || choice == 'y');

    exitApp(list);

    return 0;
}
