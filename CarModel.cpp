// реализация класса CarModel
// класс для работы с машинами

#include "CarModel.h"

#include <string>
#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>


// конструктор, вызывается при создании экземпляров класса
ModelCar::ModelCar()
{
    // статус машины
    isItemActive = true;

    //ввод марки машины
    std::cout << "Введите марку машины: ";
    std::cin >> itemName;


    //ввод характеристик, недостатков и тд машины
    std::cout << std::endl << "Введите описание машины: ";
    std::cin >> itemDesc;

    itemPrice = -1.0;

    // пока админ не введет цену аренды за час >0
    while (itemPrice < 0)
    {
        std::cout << std::endl << "Введите цену аренды машины за час: ";
        std::cin >> itemPrice;
    }

    // ID машины, чтобы искать потом
    id = time(0);

    std::cout << std::endl << "Generated ID: " << id << std::endl;
    std::cout << "Марка: " << itemName << std::endl;
    std::cout << "Описание: " << itemDesc << std::endl;
    std::cout << "Аренда в час: " << itemPrice << std::endl;
}

// деструктор
ModelCar::~ModelCar()
{
}

// получить список всех машин
void ModelCar::getAll()
{

    std::streampos size;
    char* memblock;

    // открываем файлик бинарно на чтение с курсором в конце файла
    std::ifstream fin("C:\\Users\\User\\source\\repos\\carshering\\model_car.bin", std::ios_base::binary | std::ios_base::ate);

    if (fin.is_open())
    {
        // узнаем, какая сейчас позиция у курсора
        size = fin.tellg();

        // создаем буффер для чтения данных
        memblock = new char[size];

        // перемещаем курсор в начало файла
        fin.seekg(0, std::ios::beg);

        // читаем весь файл в буффер
        fin.read(memblock, size);

        // закрываем файл
        fin.close();

        // если файл пустой, выводим сообщение и завершаем работу метода
        if (size == 0)
        {
            std::cout << "Машин не найдено. Добавьте первый!" << std::endl << std::endl;
            return;
        }

        // тут уже точно файл не пустой, выводим прочитанный буффер
        std::cout << "__________________________________________________" << std::endl;
        std::cout << "Список всех машин:" << std::endl << std::endl;

        // счётчик строк в записи каждой машины, нужен для форматирования
        int newRowsCounter = 0;

        // переменные под символы - текущий, предыдущий, предпредыдущий
        char currChar, prevChar = ' ', prevPrevChar = ' ';

        for (int i = 0; i < size; i++)
        {
            // суем сюда текущий элем. буффера
            currChar = memblock[i];

            // если на втором элементе буффера, то предыдущий символ сущ-ет, => можно записать его
            if (i >= 1)
                prevChar = memblock[i - 1];

            // аналогично вышеупомянотому
            if (i >= 2)
                prevPrevChar = memblock[i - 2];

            // работа с счетчиком строк.
            // Каждая запись о машине отделяется от следующей последовательностью символов "\n\n"
            // По этой комбинации и оперируем счетчиком
            if (currChar == '\n')
            {
                // если пошла новая запись о машине, то есть наткнулись на "\n\n", то обнуляем счётчик строк
                if (prevChar == '\n')
                    newRowsCounter = 0;
                else
                    // иначе просто добавляем кол-во
                    newRowsCounter += 1;
            }

            // если на первом символе буффера, т.е. только начали выводить записи
            // или
            // если выводим 2-ую и последующие записи
            // то выводим надпись "ID"
            if (i == 0 || (prevPrevChar == '\n' && prevChar == '\n'))
            {
                std::cout << "ID: ";
            }

            // если начали выводить очередную строку (но не первую) записи о машине, т.е.
            // предыдущий символ - переход на новую строку, а текущий не переход, а обычный символ
            if (currChar != '\n' && prevChar == '\n')
            {
                // если вторая строка, то выводим подпись "Статус машины"
                if (newRowsCounter == 1)
                {
                    std::cout << "Статус машины: ";

                    // если в файле написан 1, то это активный
                    if (currChar == '1')
                    {
                        std::cout << "Активна";
                    }
                    // если 0, то неактивный
                    else if (currChar == '0')
                    {
                        std::cout << "Не активна";
                    }
                    // а если ваще, то следует об этом уведомить
                    // такое было, когда bool сувал в .bin файл
                    else
                    {
                        std::cout << "Неопознанный символ";
                    }

                    // чтобы не выводить этот 0 или 1, а то и вообще кракозябру, завершаем текущую итерацию и идем дальше
                    continue;
                }
                // если третья строка
                else if (newRowsCounter == 2)
                {
                    std::cout << "Название машины: ";
                }
                // если четвертая строка
                else if (newRowsCounter == 3)
                {
                    std::cout << "Описание машины: ";
                }
                // если пятая строка
                else if (newRowsCounter == 4)
                {
                    std::cout << "Цена аредны машины за час: ";
                }
            }

            // ну и выводим символ, чтобы инфу то вообще получить
            std::cout << currChar;
        }
        std::cout << "_____________________________________________________" << std::endl;

        // чистим за собой *****ь
        delete[] memblock;
    }
    else
    {

        std::cout << "ошибка открытия файла для чтения всех участников" << std::endl;

    }
}

// сохранение машины в файл
void ModelCar::saveToFile()
{
    // открываем файлик на запись в конец бинарно
    std::ofstream itemsFile("C:\\Users\\User\\source\\repos\\carshering\\model_car.bin", std::ios_base::binary | std::ios_base::app);

    if (itemsFile.is_open())
    {
        // чтобы работало, по-другому никак
        char newRow = '\n';

        //пишем ID
        itemsFile.write(std::to_string(id).c_str(), std::to_string(id).length());
        itemsFile.write((char*)&newRow, sizeof(char));

        // дописываем остальные данные

        // статус
        char status = '1';
        itemsFile.write((char*)&status, sizeof(char));
        itemsFile.write((char*)&newRow, sizeof(char));

        // название машины
        itemsFile.write(itemName.c_str(), itemName.length());
        itemsFile.write((char*)&newRow, sizeof(char));

        // описание машины
        itemsFile.write(itemDesc.c_str(), itemDesc.length());
        itemsFile.write((char*)&newRow, sizeof(char));

        // начальная аренды цена машины
        std::string priceString = std::to_string(itemPrice);

        itemsFile.write(priceString.c_str(), priceString.length());
        // тут пишем 2 \n, чтобы потом при выводе на них опираться
        itemsFile.write((char*)&newRow, sizeof(char));
        itemsFile.write((char*)&newRow, sizeof(char));


        // раньше была запись целой строки через .c_str(), это осталось от тех времен, пусть лучше будет, чем вообще без проверки
        if (!itemsFile.bad())
        {
            std::cout << "Успешно добавлено" << std::endl;
        }
        else
        {
            std::cout << "Ошибка при записи данных" << std::endl;
        }

        // закрываем файлик
        itemsFile.close();
    }
    else
    {
        std::cout << "Ошибка при открытии файла для записи" << std::endl;
    }
}

// поиск в файле по ID. Возвращает позицию курсора на символе '\n' после совпадения ID
std::streampos ModelCar::findByID(std::string ID)
{
    // Открываем файлик на чтение бинарно с позицией в концее файла, по-другому у меня не получилось
    std::ifstream auctionItemsFile("C:\\Users\\User\\source\\repos\\carshering\\model_car.bin", std::ios_base::binary | std::ios_base::ate);

    if (auctionItemsFile.is_open())
    {
        // длина файла
        std::streampos cursorEnd = auctionItemsFile.tellg();
        char* memblock = new char[cursorEnd];

        // в начало
        auctionItemsFile.seekg(0, std::ios::beg);

        // для символов, чтобы опираться на '\n' дальше
        char currChar = ' ', prevChar = ' ';

        // чтобы избежать этого массива чаров, в него будем писать прочитанный в файле ID
        std::stringstream ss;

        // счетчик строк для каждой записи о машины
        int rowsCounter = 0;

        for (int i = 0; i < cursorEnd; i++)
        {
            // читаем посимвольно
            currChar = auctionItemsFile.get();
            //std::cout << currChar;

            // суем в массивчик наш, тут удобно им пользоваться
            memblock[i] = currChar;

            // предыдущий символ сущ-ет только на второй итерации цикла
            if (i >= 1)
                prevChar = memblock[i - 1];

            // читаем строку до перехода на новую строку, пишем в стрингстрим и переходим на след итерацию
            if (currChar != '\n' && rowsCounter == 0)
            {
                ss << currChar;
                continue;
            }
            // если перешли на новую строку
            else if (currChar == '\n')
            {
                // счётчик строк ++
                rowsCounter++;

                // если пошла запись о другой машине
                if (prevChar == '\n')
                {
                    // обнуляем счётчик строк
                    rowsCounter = 0;

                    // чистим стрингстрим
                    ss.str("");
                }

                // если считали строку с ID
                if (rowsCounter == 1)
                {
                    //std::cout << "Нашли ID: " << ss.str() << std::endl;

                    // если прочитанный ID совпадает с нужным, возвращаем позицию курсора на символе '\n'
                    if (ss.str() == ID)
                    {
                        //std::cout << "ID совпали" << std::endl;
                        return auctionItemsFile.tellg();
                    }
                }
            }
        }

        // закрываем файлик
        auctionItemsFile.close();

        // чистим память
        delete[] memblock;
    }
    else
    {
        std::cout << "Ошибка при открытии файла для чтения" << std::endl;
        return -1;
    }
}

// смена статуса машины в файле
void changeStatusInFile(int cursorPos)
{
    // делаем красоту с файлом в стиле C
    FILE* pFile;

    // открываем safety обязательно, для правки
    fopen_s(&pFile, "C:\\Users\\User\\source\\repos\\carshering\\model_car.bin", "rb+");

    //проверяем что удалось открыть
    if (pFile != NULL)
    {
        //в файле pFile перемещаемся на нужную позицию вперёд относительно начала файла
        fseek(pFile, cursorPos, SEEK_SET);

        //пишем туда символ '0'. Мы же только снимаем машину, потом когда надо будет, напишем сюда обратное условие;
        fwrite("0", 1, 1, pFile);

        // закрываем файлик
        fclose(pFile);
    }
    else
    {


        std::cout << "Ошибка при открытии файла для изменения статуса" << std::endl;

    }
}

// обертка над магией смены статуса в файле.
// manual - режим запуска.
// true - из меню, false - из CMD
void ModelCar::disable(std::string IDparam, bool manual)
{
    int cursorPosition = ModelCar::findByID(IDparam);

    // это из функции получается
    if (cursorPosition == -1)
    {
        std::cout << "Такой ID не найден. Попробуйте другой";
        return;
    }
    else // если ID в файле найден
    {
        // если было вызвано из меню
        if (manual)
        {
            char agreement = ' ';
            std::cout << "Вы точно хотите снять машину с ID " << IDparam << "? (Y / N)" << std::endl;

            // пока не будет введен один из символов
            while (!(agreement == 'Y' || agreement == 'N'))
            {
                std::cin >> agreement;
            }

            // если подтвердил, то меняем
            if (agreement == 'Y')
            {
                changeStatusInFile(cursorPosition);
            }
            // иначе не меняем...
            else if (agreement == 'N')
            {
                std::cout << std::endl << "Отмена..." << std::endl;
                return;
            }
        }
        // если было вызвано из параметров CMD
        else
        {
            changeStatusInFile(cursorPosition);
        }
    }
}
