// ���������� ������ ��� ������ � ����������

#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>

#include "Voditel.h"

// ����������� ��� ����������� ������
Voditel::Voditel(std::string parterName, std::string parterLastname, std::string parterFathername, int parterAge, int vu)
{
    name = parterName;
    lastName = parterLastname;
    fatherName = parterFathername;
    age = parterAge;
    nomervu = vu;
}

// ����������
Voditel::~Voditel()
{
}

// ���������� ������ � �������� � ����
void Voditel::saveToFile()
{
    // �������� �� ������ � ����� �������
    std::ofstream fout("C:\\Users\\User\\source\\repos\\carshering\\voditel.bin", std::ios_base::binary | std::ios_base::app);

    // ���� ������ ��������
    if (fout.is_open()) {
        // ��������� ������
        std::string stringToSave = lastName + " " + name + " " + fatherName + ", " + std::to_string(age) + ", " + std::to_string(nomervu) + "\n";

        // ���� � ����
        fout.write(stringToSave.c_str(), stringToSave.length());

        // ���� �� ���, �� ���
        if (!fout.bad()) {


            std::cout << "������ ��������!" << std::endl;

        }
        // ����� �� ���
        else {


            std::cout << "��������� ������ ��� ������ �����!" << std::endl;

        }

        fout.close();
    }
    else {


        std::cout << "������ �������� ����� ��� ������ ��������" << std::endl;

    }

    return;
}

// ������� ������ ���� ���������
void Voditel::getAllParters()
{
    std::streampos size;
    char* memblock;

    // ��������� ������ �� ������ ������� � �������� � �����
    std::ifstream fin("C:\\Users\\User\\source\\repos\\carshering\\voditel.bin", std::ios_base::binary | std::ios_base::ate);

    if (fin.is_open()) {
        // �������� ������ �����
        size = fin.tellg();

        // ������ ������
        memblock = new char[size];

        // � ������
        fin.seekg(0, std::ios::beg);

        // ������ � ������
        fin.read(memblock, size);

        // ��������� ������
        fin.close();

        // �������. �� ������ ����������. ��� ������� �������������� ���� �� ������� ����� get() ������;
        std::cout << "__________________________________________________" << std::endl;
        std::cout << "������ ���� ���������:" << std::endl << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << memblock[i];
            // ��� ������ ��� ��������� \n, ������� << endl �� �����
        }
        std::cout << "_____________________________________________________" << std::endl;

        // ������ �� �����
        delete[] memblock;
    }
    else {
        // ������ �������

        std::cout << "������ �������� ����� ��� ������ ���� ���������" << std::endl;

    }
}
