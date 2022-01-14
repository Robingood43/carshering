#pragma once
// класс для работы с водителями

#include <string>




class Voditel {
public:
    Voditel(std::string parterName, std::string parterLastname, std::string parterFathername, int parterAge, int nomervu);
    ~Voditel();

    void saveToFile();
    static void getAllParters();

    std::string name, lastName, fatherName;
    int nomervu;
    int age;
};