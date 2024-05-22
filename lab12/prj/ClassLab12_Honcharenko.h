#ifndef CLASSLAB12_HONCHARENKO_H
#define CLASSLAB12_HONCHARENKO_H

#include <cmath>
#include <stdexcept>
#include <iostream>

class ClassLab12_Honcharenko {
private:
    double radius;  // ����� ������
    double diameter; // ĳ����� ������

public:
    // ����������� ��� ����������� ��������
    ClassLab12_Honcharenko() : radius(3.5), diameter(2.0) {}
    ClassLab12_Honcharenko(double radius, double diameter) {
        if (radius <= 0 || diameter <= 0) {
            throw std::invalid_argument("������ ������ ���� ����� ����");
        }
        this->radius = radius;
        this->diameter = diameter;
    }

    // ������� ��� ��������� ������� ��������
    double getRadius() const {
        return radius;
    }

    double getDiameter() const {
        return diameter;
    }

    // ������� ��� ���� ������� �������� � ���������
    void setRadius(double radius) {
        if (radius <= 0) {
            throw std::invalid_argument("����� ������� ���� ����� ����");
        }
        this->radius = radius;
    }

    void setDiameter(double diameter) {
        if (diameter <= 0) {
            throw std::invalid_argument("ĳ����� ������� ���� ����� ����");
        }
        this->diameter = diameter;
    }

    // ����� ��� ���������� �����
    double calculateArea() const {
        return M_PI * std::pow(radius, 2);
    }
};

#endif // CLASSLAB12_HONCHARENKO_H
