#pragma once
#ifndef PERSON_H // Директива условной компиляции, чтобы header-файл был включен только один раз
#define PERSON_H

#include <iostream>
#include <cstring>
#include <limits>

class Person {
private:
    char* brand;
    int number;
    float sum;
public:
    // Конструкторы и деструктор
    Person(const char* b, int n, float s);
    Person();
    ~Person();
    // Методы вывода и ввода объекта
    void Print() const;
    void Input();
    // Методы установки и получения значений полей объекта
    void SetBrand(const char* b);
    void SetNumber(int n);
    void SetSum(float s);
    const char* GetBrand() const;
    int GetNumber() const;
    float GetSum() const;
};

#endif
