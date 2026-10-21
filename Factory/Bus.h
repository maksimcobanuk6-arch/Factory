#pragma once
#include "Vehicle.h"
//автобус
class Bus : public Vehicle {
public:
    Bus();
    void drive() const override;
};