#pragma once
#include <memory>
#include "Vehicle.h"
// Фабрика лише створює об'єкти і повертає їх через спільний тип Vehicle.
// Самих об'єктів вона не зберігає
class VehicleFactory {
public:
    enum Type { CAR = 1, TRUCK = 2, BUS = 3 };
    // Повертає nullptr, якщо такого типу транспорту немає
    static std::unique_ptr<Vehicle> create(int type);
};