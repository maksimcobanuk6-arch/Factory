#pragma once
#include "Vehicle.h"
// Фура
class Truck : public Vehicle {
public:
    Truck();
    void drive() const override;
};