#pragma once
#include "Vehicle.h"
// машіна
class Car : public Vehicle {
public:
    Car();
    void drive() const override;
};