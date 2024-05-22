#ifndef CLASSLAB12_HONCHARENKO_H
#define CLASSLAB12_HONCHARENKO_H

#include <cmath>
#include <stdexcept>
#include <iostream>

class ClassLab12_Honcharenko {
private:
    double radius;  // Радіус колеса
    double diameter; // Діаметр колеса

public:
    // Конструктор для ініціалізації атрибутів
    ClassLab12_Honcharenko() : radius(3.5), diameter(2.0) {}
    ClassLab12_Honcharenko(double radius, double diameter) {
        if (radius <= 0 || diameter <= 0) {
            throw std::invalid_argument("Розміри повинні бути більше нуля");
        }
        this->radius = radius;
        this->diameter = diameter;
    }

    // Геттери для отримання значень атрибутів
    double getRadius() const {
        return radius;
    }

    double getDiameter() const {
        return diameter;
    }

    // Сеттери для зміни значень атрибутів з валідацією
    void setRadius(double radius) {
        if (radius <= 0) {
            throw std::invalid_argument("Радіус повинен бути більше нуля");
        }
        this->radius = radius;
    }

    void setDiameter(double diameter) {
        if (diameter <= 0) {
            throw std::invalid_argument("Діаметр повинен бути більше нуля");
        }
        this->diameter = diameter;
    }

    // Метод для обчислення площі
    double calculateArea() const {
        return M_PI * std::pow(radius, 2);
    }
};

#endif // CLASSLAB12_HONCHARENKO_H
