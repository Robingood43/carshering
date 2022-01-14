// ���������� ������ CarModel
// ����� ��� ������ � ��������

#include "CarModel.h"

#include <string>
#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>


// �����������, ���������� ��� �������� ����������� ������
ModelCar::ModelCar()
{
    // ������ ������
    isItemActive = true;

    //���� ����� ������
    std::cout << "������� ����� ������: ";
    std::cin >> itemName;


    //���� �������������, ����������� � �� ������
    std::cout << std::endl << "������� �������� ������: ";
    std::cin >> itemDesc;

    itemPrice = -1.0;

    // ���� ����� �� ������ ���� ������ �� ��� >0
    while (itemPrice < 0)
    {
        std::cout << std::endl << "������� ���� ������ ������ �� ���: ";
        std::cin >> itemPrice;
    }

    // ID ������, ����� ������ �����
    id = time(0);

    std::cout << std::endl << "Generated ID: " << id << std::endl;
    std::cout << "�����: " << itemName << std::endl;
    std::cout << "��������: " << itemDesc << std::endl;
    std::cout << "������ � ���: " << itemPrice << std::endl;
}

// ����������
ModelCar::~ModelCar()
{
}

// �������� ������ ���� �����
void ModelCar::getAll()
{

    std::streampos size;
    char* memblock;

    // ��������� ������ ������� �� ������ � �������� � ����� �����
    std::ifstream fin("C:\\Users\\User\\source\\repos\\carshering\\model_car.bin", std::ios_base::binary | std::ios_base::ate);

    if (fin.is_open())
    {
        // ������, ����� ������ ������� � �������
        size = fin.tellg();

        // ������� ������ ��� ������ ������
        memblock = new char[size];

        // ���������� ������ � ������ �����
        fin.seekg(0, std::ios::beg);

        // ������ ���� ���� � ������
        fin.read(memblock, size);

        // ��������� ����
        fin.close();

        // ���� ���� ������, ������� ��������� � ��������� ������ ������
        if (size == 0)
        {
            std::cout << "����� �� �������. �������� ������!" << std::endl << std::endl;
            return;
        }

        // ��� ��� ����� ���� �� ������, ������� ����������� ������
        std::cout << "__________________________________________________" << std::endl;
        std::cout << "������ ���� �����:" << std::endl << std::endl;

        // ������� ����� � ������ ������ ������, ����� ��� ��������������
        int newRowsCounter = 0;

        // ���������� ��� ������� - �������, ����������, ��������������
        char currChar, prevChar = ' ', prevPrevChar = ' ';

        for (int i = 0; i < size; i++)
        {
            // ���� ���� ������� ����. �������
            currChar = memblock[i];

            // ���� �� ������ �������� �������, �� ���������� ������ ���-��, => ����� �������� ���
            if (i >= 1)
                prevChar = memblock[i - 1];

            // ���������� ���������������
            if (i >= 2)
                prevPrevChar = memblock[i - 2];

            // ������ � ��������� �����.
            // ������ ������ � ������ ���������� �� ��������� ������������������� �������� "\n\n"
            // �� ���� ���������� � ��������� ���������
            if (currChar == '\n')
            {
                // ���� ����� ����� ������ � ������, �� ���� ���������� �� "\n\n", �� �������� ������� �����
                if (prevChar == '\n')
                    newRowsCounter = 0;
                else
                    // ����� ������ ��������� ���-��
                    newRowsCounter += 1;
            }

            // ���� �� ������ ������� �������, �.�. ������ ������ �������� ������
            // ���
            // ���� ������� 2-�� � ����������� ������
            // �� ������� ������� "ID"
            if (i == 0 || (prevPrevChar == '\n' && prevChar == '\n'))
            {
                std::cout << "ID: ";
            }

            // ���� ������ �������� ��������� ������ (�� �� ������) ������ � ������, �.�.
            // ���������� ������ - ������� �� ����� ������, � ������� �� �������, � ������� ������
            if (currChar != '\n' && prevChar == '\n')
            {
                // ���� ������ ������, �� ������� ������� "������ ������"
                if (newRowsCounter == 1)
                {
                    std::cout << "������ ������: ";

                    // ���� � ����� ������� 1, �� ��� ��������
                    if (currChar == '1')
                    {
                        std::cout << "�������";
                    }
                    // ���� 0, �� ����������
                    else if (currChar == '0')
                    {
                        std::cout << "�� �������";
                    }
                    // � ���� ����, �� ������� �� ���� ���������
                    // ����� ����, ����� bool ����� � .bin ����
                    else
                    {
                        std::cout << "������������ ������";
                    }

                    // ����� �� �������� ���� 0 ��� 1, � �� � ������ ����������, ��������� ������� �������� � ���� ������
                    continue;
                }
                // ���� ������ ������
                else if (newRowsCounter == 2)
                {
                    std::cout << "�������� ������: ";
                }
                // ���� ��������� ������
                else if (newRowsCounter == 3)
                {
                    std::cout << "�������� ������: ";
                }
                // ���� ����� ������
                else if (newRowsCounter == 4)
                {
                    std::cout << "���� ������ ������ �� ���: ";
                }
            }

            // �� � ������� ������, ����� ���� �� ������ ��������
            std::cout << currChar;
        }
        std::cout << "_____________________________________________________" << std::endl;

        // ������ �� ����� *****�
        delete[] memblock;
    }
    else
    {

        std::cout << "������ �������� ����� ��� ������ ���� ����������" << std::endl;

    }
}

// ���������� ������ � ����
void ModelCar::saveToFile()
{
    // ��������� ������ �� ������ � ����� �������
    std::ofstream itemsFile("C:\\Users\\User\\source\\repos\\carshering\\model_car.bin", std::ios_base::binary | std::ios_base::app);

    if (itemsFile.is_open())
    {
        // ����� ��������, ��-������� �����
        char newRow = '\n';

        //����� ID
        itemsFile.write(std::to_string(id).c_str(), std::to_string(id).length());
        itemsFile.write((char*)&newRow, sizeof(char));

        // ���������� ��������� ������

        // ������
        char status = '1';
        itemsFile.write((char*)&status, sizeof(char));
        itemsFile.write((char*)&newRow, sizeof(char));

        // �������� ������
        itemsFile.write(itemName.c_str(), itemName.length());
        itemsFile.write((char*)&newRow, sizeof(char));

        // �������� ������
        itemsFile.write(itemDesc.c_str(), itemDesc.length());
        itemsFile.write((char*)&newRow, sizeof(char));

        // ��������� ������ ���� ������
        std::string priceString = std::to_string(itemPrice);

        itemsFile.write(priceString.c_str(), priceString.length());
        // ��� ����� 2 \n, ����� ����� ��� ������ �� ��� ���������
        itemsFile.write((char*)&newRow, sizeof(char));
        itemsFile.write((char*)&newRow, sizeof(char));


        // ������ ���� ������ ����� ������ ����� .c_str(), ��� �������� �� ��� ������, ����� ����� �����, ��� ������ ��� ��������
        if (!itemsFile.bad())
        {
            std::cout << "������� ���������" << std::endl;
        }
        else
        {
            std::cout << "������ ��� ������ ������" << std::endl;
        }

        // ��������� ������
        itemsFile.close();
    }
    else
    {
        std::cout << "������ ��� �������� ����� ��� ������" << std::endl;
    }
}

// ����� � ����� �� ID. ���������� ������� ������� �� ������� '\n' ����� ���������� ID
std::streampos ModelCar::findByID(std::string ID)
{
    // ��������� ������ �� ������ ������� � �������� � ������ �����, ��-������� � ���� �� ����������
    std::ifstream auctionItemsFile("C:\\Users\\User\\source\\repos\\carshering\\model_car.bin", std::ios_base::binary | std::ios_base::ate);

    if (auctionItemsFile.is_open())
    {
        // ����� �����
        std::streampos cursorEnd = auctionItemsFile.tellg();
        char* memblock = new char[cursorEnd];

        // � ������
        auctionItemsFile.seekg(0, std::ios::beg);

        // ��� ��������, ����� ��������� �� '\n' ������
        char currChar = ' ', prevChar = ' ';

        // ����� �������� ����� ������� �����, � ���� ����� ������ ����������� � ����� ID
        std::stringstream ss;

        // ������� ����� ��� ������ ������ � ������
        int rowsCounter = 0;

        for (int i = 0; i < cursorEnd; i++)
        {
            // ������ �����������
            currChar = auctionItemsFile.get();
            //std::cout << currChar;

            // ���� � ��������� ���, ��� ������ �� ������������
            memblock[i] = currChar;

            // ���������� ������ ���-�� ������ �� ������ �������� �����
            if (i >= 1)
                prevChar = memblock[i - 1];

            // ������ ������ �� �������� �� ����� ������, ����� � ����������� � ��������� �� ���� ��������
            if (currChar != '\n' && rowsCounter == 0)
            {
                ss << currChar;
                continue;
            }
            // ���� ������� �� ����� ������
            else if (currChar == '\n')
            {
                // ������� ����� ++
                rowsCounter++;

                // ���� ����� ������ � ������ ������
                if (prevChar == '\n')
                {
                    // �������� ������� �����
                    rowsCounter = 0;

                    // ������ �����������
                    ss.str("");
                }

                // ���� ������� ������ � ID
                if (rowsCounter == 1)
                {
                    //std::cout << "����� ID: " << ss.str() << std::endl;

                    // ���� ����������� ID ��������� � ������, ���������� ������� ������� �� ������� '\n'
                    if (ss.str() == ID)
                    {
                        //std::cout << "ID �������" << std::endl;
                        return auctionItemsFile.tellg();
                    }
                }
            }
        }

        // ��������� ������
        auctionItemsFile.close();

        // ������ ������
        delete[] memblock;
    }
    else
    {
        std::cout << "������ ��� �������� ����� ��� ������" << std::endl;
        return -1;
    }
}

// ����� ������� ������ � �����
void changeStatusInFile(int cursorPos)
{
    // ������ ������� � ������ � ����� C
    FILE* pFile;

    // ��������� safety �����������, ��� ������
    fopen_s(&pFile, "C:\\Users\\User\\source\\repos\\carshering\\model_car.bin", "rb+");

    //��������� ��� ������� �������
    if (pFile != NULL)
    {
        //� ����� pFile ������������ �� ������ ������� ����� ������������ ������ �����
        fseek(pFile, cursorPos, SEEK_SET);

        //����� ���� ������ '0'. �� �� ������ ������� ������, ����� ����� ���� �����, ������� ���� �������� �������;
        fwrite("0", 1, 1, pFile);

        // ��������� ������
        fclose(pFile);
    }
    else
    {


        std::cout << "������ ��� �������� ����� ��� ��������� �������" << std::endl;

    }
}

// ������� ��� ������ ����� ������� � �����.
// manual - ����� �������.
// true - �� ����, false - �� CMD
void ModelCar::disable(std::string IDparam, bool manual)
{
    int cursorPosition = ModelCar::findByID(IDparam);

    // ��� �� ������� ����������
    if (cursorPosition == -1)
    {
        std::cout << "����� ID �� ������. ���������� ������";
        return;
    }
    else // ���� ID � ����� ������
    {
        // ���� ���� ������� �� ����
        if (manual)
        {
            char agreement = ' ';
            std::cout << "�� ����� ������ ����� ������ � ID " << IDparam << "? (Y / N)" << std::endl;

            // ���� �� ����� ������ ���� �� ��������
            while (!(agreement == 'Y' || agreement == 'N'))
            {
                std::cin >> agreement;
            }

            // ���� ����������, �� ������
            if (agreement == 'Y')
            {
                changeStatusInFile(cursorPosition);
            }
            // ����� �� ������...
            else if (agreement == 'N')
            {
                std::cout << std::endl << "������..." << std::endl;
                return;
            }
        }
        // ���� ���� ������� �� ���������� CMD
        else
        {
            changeStatusInFile(cursorPosition);
        }
    }
}
