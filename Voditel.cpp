// реализация класса для работы с водителями

#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>

#include "Voditel.h"

// конструктор для экземпляров класса
Voditel::Voditel(std::string parterName, std::string parterLastname, std::string parterFathername, int parterAge, int vu)
{
    name = parterName;
    lastName = parterLastname;
    fatherName = parterFathername;
    age = parterAge;
    nomervu = vu;
}

// деструктор
Voditel::~Voditel()
{
}

// сохранение данных о водителе в файл
void Voditel::saveToFile()
{
    // отрываем на запись в конец бинарно
    std::ofstream fout("C:\\Users\\User\\source\\repos\\carshering\\voditel.bin", std::ios_base::binary | std::ios_base::app);

    // если файлик открылся
    if (fout.is_open()) {
        // формируем данные
        std::string stringToSave = lastName + " " + name + " " + fatherName + ", " + std::to_string(age) + ", " + std::to_string(nomervu) + "\n";

        // суем в файл
        fout.write(stringToSave.c_str(), stringToSave.length());

        // если всё гуд, то гуд
        if (!fout.bad()) {


            std::cout << "Данные записаны!" << std::endl;

        }
        // иначе не гуд
        else {


            std::cout << "Произошла ошибка при записи файла!" << std::endl;

        }

        fout.close();
    }
    else {


        std::cout << "ошибка открытия файла для записи водителя" << std::endl;

    }

    return;
}

// вывести список всех водителей
void Voditel::getAllParters()
{
    std::streampos size;
    char* memblock;

    // открываем файлик на чтение бинарно с курсором в конце
    std::ifstream fin("C:\\Users\\User\\source\\repos\\carshering\\voditel.bin", std::ios_base::binary | std::ios_base::ate);

    if (fin.is_open()) {
        // получаем размер файла
        size = fin.tellg();

        // делаем буффер
        memblock = new char[size];

        // в начало
        fin.seekg(0, std::ios::beg);

        // читаем в буффер
        fin.read(memblock, size);

        // закрываем файлик
        fin.close();

        // выводим. Не совсем оптимально. Без всякого форматирования было бы быстрее через get() делать;
        std::cout << "__________________________________________________" << std::endl;
        std::cout << "Список всех водителей:" << std::endl << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << memblock[i];
            // тут каждый раз выводится \n, поэтому << endl не нужен
        }
        std::cout << "_____________________________________________________" << std::endl;

        // чистим за собой
        delete[] memblock;
    }
    else {
        // красим консоль

        std::cout << "ошибка открытия файла для чтения всех водителей" << std::endl;

    }
}
