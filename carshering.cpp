#include <iostream>
#include <string>
#include <Windows.h>
#include "CarModel.h"
#include "Voditel.h"
#include"conio.h"

// обертка над методом класса
void NewVoditel()
{
    system("cls");
    std::string name = "", lastName = "", fatherName = "";
    int age = -1;
    int nomervu = -1;
    std::cout << "Введите данные о водителе:" << std::endl << "Фамилия: ";
    std::cin >> lastName;

    std::cout << "Имя: ";
    std::cin >> name;

    std::cout << "Отчество: ";
    std::cin >> fatherName;

    age == -1;
    //пока водителю меньше 18 лет выход.
    while (age < 18)
    {
        std::cout << "Возраст: ";
        std::cin >> age;
    }
    std::cout << "Номер водительского удостоверения: ";
    std::cin >> nomervu;

    Voditel newPerson = Voditel(name, lastName, fatherName, age, nomervu);
    newPerson.saveToFile();
}

// обертка над методом класса
void NewCar()
{
    system("cls");
    ModelCar newItem;
    newItem.saveToFile();
    return;
}

// обертка над методом класса для вызова метода через меню
void DeleteCar()
{
    system("cls");
    std::string askedID;
    std::cout << "Введите ID: ";
    std::cin >> askedID;

    ModelCar::disable(askedID, true);
}
void escape()
{
    exit(0);
}

void select(int position) {
    system("cls");
    // проверяем, что пользователь выбрал
    switch (position)
    {
        // зарегистрировать нового водителя
    case 0: NewVoditel();
        //очистка экрана
        system("cls");
        break;
        //добавить новую машину
    case 1:
        NewCar();
        system("cls");
        break;

    case 2:
        //удалить старую машину
        DeleteCar();
        system("cls");
        break;
    case 3:
        //показать все доступные машины
        ModelCar::getAll();
        system("pause");
        system("cls");

        break;
    case 4:
        //показать всех зарегистрированных водителей
        Voditel::getAllParters();
        system("pause");
        system("cls");

        break;

    case 5:
        //выход
        system("cls");
        escape();
        system("pause");
        system("cls");
        break;
    }
}

int main(int argc, char* argv[])
{
    SetConsoleCP(1251); // установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position1;
    COORD position2;
    COORD position3;
    COORD position4;
    COORD position5;
    COORD position6;
    //задаем цвет
    //При выборе 
    WORD active = FOREGROUND_BLUE | FOREGROUND_GREEN |
        FOREGROUND_RED;
    //когда обычный
    WORD nactive = FOREGROUND_BLUE | FOREGROUND_GREEN |
        FOREGROUND_RED;
    //позиция вывода каждой строчки из меню
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
    // список пунктов меню. Хотел через enum сделать, но не додумался как это нормально организовать
    std::string menuItems[6] = {
        "Зарегистрировать нового водителя",
        "Добавить машину",
        "Удалить машину",
        "Показать информацию о машинах",
        "Вывести информацию о всех водителях",
        "Выйти"
    };
    char code;
    int position = 0;

    //выводим цвет каждой строчке при определенной позиции
    while (true)
    {
        if (argc == 1)
        {
            system("cls");
            //цвет у первой позиции при выборе её
            if (position == 0)
            {
                SetConsoleTextAttribute(hwnd,
                    FOREGROUND_RED);
            }
            //иначе такой цвет
            else
                SetConsoleTextAttribute(hwnd, nactive);
            //вывод 1 надписи в позиции X;Y
            SetConsoleCursorPosition(hwnd, position1);
            std::cout << menuItems[0] << std::endl;
            //цвет у второй позиции
            if (position == 1)
            {
                SetConsoleTextAttribute(hwnd,
                    FOREGROUND_RED | FOREGROUND_GREEN
                );
            }
            //иначе такой цвет
            else
                SetConsoleTextAttribute(hwnd, nactive);
            //вывод 2 надписи в позиции X;Y
            SetConsoleCursorPosition(hwnd, position2);
            std::cout << menuItems[1] << std::endl;
            //цвет у третьей позиции
            if (position == 2)

            {
                SetConsoleTextAttribute(hwnd,

                    FOREGROUND_BLUE);
            }
            //иначе такой цвет
            else
                SetConsoleTextAttribute(hwnd, nactive);
            //вывод 3 надписи в позиции X;Y
            SetConsoleCursorPosition(hwnd, position3);
            std::cout << menuItems[2] << std::endl;
            //цвет у четвертой позиции
            if (position == 3)
            {
                SetConsoleTextAttribute(hwnd,
                    FOREGROUND_BLUE |
                    FOREGROUND_GREEN);
            }
            //иначе такой цвет
            else
                SetConsoleTextAttribute(hwnd, nactive);
            //вывод 4 надписи в позиции X;Y
            SetConsoleCursorPosition(hwnd, position4);
            std::cout << menuItems[3] << std::endl;
            //цвет у пятой позиции при выборе 
            if (position == 4)
            {
                SetConsoleTextAttribute(hwnd, FOREGROUND_BLUE |
                    FOREGROUND_RED);
            }
            //иначе такой цвет 
            else
                SetConsoleTextAttribute(hwnd, nactive);
            //вывод 5 надписи в позиции X;Y
            SetConsoleCursorPosition(hwnd, position5);
            std::cout << menuItems[4] << std::endl;

            //цвет у шестой позиции
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

            //для переключения стрелками между пунктами меню если доходит до первого пункта переход на последний элемент
            code = _getch();//считывание нажатий на клавиатуре
            if (code == 72)//код стрелки вверх в char
            {
                if (position == 0)//если дошли до верхнего пункта в меню переход на низ
                    position = 5;

                else position--;
            }
            //для переключения стрелками между пунктами меню если доходит до последнего пункта переход на первый элемент
            if (code == 80)//код стрелки вниз в char
            {
                if (position == 5)//если дошли до последнего пункта в меню переход на вверх
                {
                    position = 0;
                }
                else position++;
            }

            //при нажатии на левую стрелку переход в нужную вкладку
            if (code == 77)//код левой стрелки в char
                select(position);//Выбор текущей позиции с выполнением
        }
        else
        {

            std::string prevParam = "";

            for (int i = 1; i < argc; i++)
            {

                // в нормальный человеческий вид приводим текущий аргумент
                std::string param(argv[i]);
                // вывод всех машин
                if (param == "-all_car")
                {
                    ModelCar::getAll();

                    exit(0);
                }
                // вывод всех водителей
                if (param == "-all_voditel")
                {
                    Voditel::getAllParters();

                    exit(0);
                }
            }
        }
    }


    // пока пользователь в системе


    return 0;
}
