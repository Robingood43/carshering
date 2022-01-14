#include <iostream>
#include <string>
#include <Windows.h>
#include "CarModel.h"
#include "Voditel.h"
#include"conio.h"

// ������� ��� ������� ������
void NewVoditel()
{
    system("cls");
    std::string name = "", lastName = "", fatherName = "";
    int age = -1;
    int nomervu = -1;
    std::cout << "������� ������ � ��������:" << std::endl << "�������: ";
    std::cin >> lastName;

    std::cout << "���: ";
    std::cin >> name;

    std::cout << "��������: ";
    std::cin >> fatherName;

    age == -1;
    //���� �������� ������ 18 ��� �����.
    while (age < 18)
    {
        std::cout << "�������: ";
        std::cin >> age;
    }
    std::cout << "����� ������������� �������������: ";
    std::cin >> nomervu;

    Voditel newPerson = Voditel(name, lastName, fatherName, age, nomervu);
    newPerson.saveToFile();
}

// ������� ��� ������� ������
void NewCar()
{
    system("cls");
    ModelCar newItem;
    newItem.saveToFile();
    return;
}

// ������� ��� ������� ������ ��� ������ ������ ����� ����
void DeleteCar()
{
    system("cls");
    std::string askedID;
    std::cout << "������� ID: ";
    std::cin >> askedID;

    ModelCar::disable(askedID, true);
}
void escape()
{
    exit(0);
}

void select(int position) {
    system("cls");
    // ���������, ��� ������������ ������
    switch (position)
    {
        // ���������������� ������ ��������
    case 0: NewVoditel();
        //������� ������
        system("cls");
        break;
        //�������� ����� ������
    case 1:
        NewCar();
        system("cls");
        break;

    case 2:
        //������� ������ ������
        DeleteCar();
        system("cls");
        break;
    case 3:
        //�������� ��� ��������� ������
        ModelCar::getAll();
        system("pause");
        system("cls");

        break;
    case 4:
        //�������� ���� ������������������ ���������
        Voditel::getAllParters();
        system("pause");
        system("cls");

        break;

    case 5:
        //�����
        system("cls");
        escape();
        system("pause");
        system("cls");
        break;
    }
}

int main(int argc, char* argv[])
{
    SetConsoleCP(1251); // ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������

    HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position1;
    COORD position2;
    COORD position3;
    COORD position4;
    COORD position5;
    COORD position6;
    //������ ����
    //��� ������ 
    WORD active = FOREGROUND_BLUE | FOREGROUND_GREEN |
        FOREGROUND_RED;
    //����� �������
    WORD nactive = FOREGROUND_BLUE | FOREGROUND_GREEN |
        FOREGROUND_RED;
    //������� ������ ������ ������� �� ����
    position1.X = 36;
    position1.Y = 6;
    position2.X = 44;
    position2.Y = 8;
    position3.X = 44;
    position3.Y = 10;
    position4.X = 38;
    position4.Y = 12;
    position5.X = 34;
    position5.Y = 14;
    position6.X = 48;
    position6.Y = 16;
    // ������ ������� ����. ����� ����� enum �������, �� �� ��������� ��� ��� ��������� ������������
    std::string menuItems[6] = {
        "���������������� ������ ��������",
        "�������� ������",
        "������� ������",
        "�������� ���������� � �������",
        "������� ���������� � ���� ���������",
        "�����"
    };
    char code;
    int position = 0;

    //������� ���� ������ ������� ��� ������������ �������
    while (true)
    {
        if (argc == 1)
        {
            system("cls");
            //���� � ������ ������� ��� ������ �
            if (position == 0)
            {
                SetConsoleTextAttribute(hwnd,
                    FOREGROUND_RED);
            }
            //����� ����� ����
            else
                SetConsoleTextAttribute(hwnd, nactive);
            //����� 1 ������� � ������� X;Y
            SetConsoleCursorPosition(hwnd, position1);
            std::cout << menuItems[0] << std::endl;
            //���� � ������ �������
            if (position == 1)
            {
                SetConsoleTextAttribute(hwnd,
                    FOREGROUND_RED | FOREGROUND_GREEN
                );
            }
            //����� ����� ����
            else
                SetConsoleTextAttribute(hwnd, nactive);
            //����� 2 ������� � ������� X;Y
            SetConsoleCursorPosition(hwnd, position2);
            std::cout << menuItems[1] << std::endl;
            //���� � ������� �������
            if (position == 2)

            {
                SetConsoleTextAttribute(hwnd,

                    FOREGROUND_BLUE);
            }
            //����� ����� ����
            else
                SetConsoleTextAttribute(hwnd, nactive);
            //����� 3 ������� � ������� X;Y
            SetConsoleCursorPosition(hwnd, position3);
            std::cout << menuItems[2] << std::endl;
            //���� � ��������� �������
            if (position == 3)
            {
                SetConsoleTextAttribute(hwnd,
                    FOREGROUND_BLUE |
                    FOREGROUND_GREEN);
            }
            //����� ����� ����
            else
                SetConsoleTextAttribute(hwnd, nactive);
            //����� 4 ������� � ������� X;Y
            SetConsoleCursorPosition(hwnd, position4);
            std::cout << menuItems[3] << std::endl;
            //���� � ����� ������� ��� ������ 
            if (position == 4)
            {
                SetConsoleTextAttribute(hwnd, FOREGROUND_BLUE |
                    FOREGROUND_RED);
            }
            //����� ����� ���� 
            else
                SetConsoleTextAttribute(hwnd, nactive);
            //����� 5 ������� � ������� X;Y
            SetConsoleCursorPosition(hwnd, position5);
            std::cout << menuItems[4] << std::endl;

            //���� � ������ �������
            if (position == 5)
            {
                SetConsoleTextAttribute(hwnd,
                    FOREGROUND_BLUE
                );
            }
            else
                SetConsoleTextAttribute(hwnd, nactive);
            SetConsoleCursorPosition(hwnd, position6);

            std::cout << menuItems[5] << std::endl;

            //��� ������������ ��������� ����� �������� ���� ���� ������� �� ������� ������ ������� �� ��������� �������
            code = _getch();//���������� ������� �� ����������
            if (code == 72)//��� ������� ����� � char
            {
                if (position == 0)//���� ����� �� �������� ������ � ���� ������� �� ���
                    position = 5;

                else position--;
            }
            //��� ������������ ��������� ����� �������� ���� ���� ������� �� ���������� ������ ������� �� ������ �������
            if (code == 80)//��� ������� ���� � char
            {
                if (position == 5)//���� ����� �� ���������� ������ � ���� ������� �� �����
                {
                    position = 0;
                }
                else position++;
            }

            //��� ������� �� ����� ������� ������� � ������ �������
            if (code == 77)//��� ����� ������� � char
                select(position);//����� ������� ������� � �����������
        }
        else
        {

            std::string prevParam = "";

            for (int i = 1; i < argc; i++)
            {

                // � ���������� ������������ ��� �������� ������� ��������
                std::string param(argv[i]);
                // ����� ���� �����
                if (param == "-all_car")
                {
                    ModelCar::getAll();

                    exit(0);
                }
                // ����� ���� ���������
                if (param == "-all_voditel")
                {
                    Voditel::getAllParters();

                    exit(0);
                }
            }
        }
    }


    // ���� ������������ � �������


    return 0;
}
