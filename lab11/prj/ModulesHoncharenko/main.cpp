// modules_honcharenko.cpp
#include <iostream>
#include <fstream>

#include "struct_type_project_1.h"

using namespace std;

void saveRegisterData(List *list, string registerFileName) {
    ofstream registerFile(registerFileName, ios::binary | ios::out);

    if (!registerFile) {
        cerr << "�� ������� ������� " << registerFileName << " ��� ����, ��� �������� �����!" << endl;
        return;
    }

    Node *current = list->head;
    size_t stringSize;
    while (current != nullptr) {
        stringSize = current->data.lastName.size();
        registerFile.write((char*) &stringSize, sizeof(size_t));
        registerFile.write((char*) &current->data.lastName[0], stringSize);

        stringSize = current->data.firstName.size();
        registerFile.write((char*) &stringSize, sizeof(size_t));
        registerFile.write((char*) &current->data.firstName[0], stringSize);

        stringSize = current->data.middleName.size();
        registerFile.write((char*) &stringSize, sizeof(size_t));
        registerFile.write((char*) &current->data.middleName[0], stringSize);

        stringSize = current->data.carBrand.size();
        registerFile.write((char*) &stringSize, sizeof(size_t));
        registerFile.write((char*) &current->data.carBrand[0], stringSize);

        registerFile.write((char*) &current->data.year, sizeof(int));

        stringSize = current->data.registrationDate.size();
        registerFile.write((char*) &stringSize, sizeof(size_t));
        registerFile.write((char*) &current->data.registrationDate[0], stringSize);

        stringSize = current->data.licensePlate.size();
        registerFile.write((char*) &stringSize, sizeof(size_t));
        registerFile.write((char*) &current->data.licensePlate[0], stringSize);

        stringSize = current->data.lastName.size();
        registerFile.write((char*) &stringSize, sizeof(size_t));
        registerFile.write((char*) &current->data.lastName[0], stringSize);

        current = current->next;
    }

    registerFile.close();
}


void searchCarInRegister(List* list, string stateLicensePlate) {
    Node* current = list->head;
    while (current != nullptr) {
        if (current->data.licensePlate == stateLicensePlate) {
            cout << "�������: " << current->data.lastName << endl;
            cout << "��'�: " << current->data.firstName << endl;
            cout << "��-�������: " << current->data.middleName << endl;
            cout << "������ ����: " << current->data.carBrand << endl;
            cout << "г�: " << current->data.year << endl;
            cout << "���� �����������: " << current->data.registrationDate << endl;
            cout << "����� ����: " << current->data.licensePlate << endl;
            cout << "�������: " << current->data.notes << endl;
            return;
        }
        current = current->next;
    }

    cerr << "��������� � ��������� ������� " << stateLicensePlate << " �� �������� � �����." << endl;
}
