#include "Car.h"
#include <iostream>
Car::Car() : Vehicle("Car", 180) {}
void Car::drive() const {
    std::cout << "Car їде дорогою зі швидкістю до 210 км/год\n";
}   