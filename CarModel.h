#pragma once
#include <string>

class ModelCar {
public:
    time_t id;
    std::string itemName, itemDesc;

    float itemPrice;
    //std::string inputItemPrice;

    bool isItemActive;

    ModelCar();
    ~ModelCar();

    void saveToFile();

    // static ������ ����� �������� ��� �������� ���������� ������
    static std::streampos findByID(std::string IDparam);
    static void getAll();

    // manual - ����� ������ ������
    // true - �� ����, false - �� CMD
    static void disable(std::string ID, bool manual);
};
