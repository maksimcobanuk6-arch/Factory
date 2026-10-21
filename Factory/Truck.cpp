#include "Truck.h"
#include <iostream>
Truck::Truck() : Vehicle("Truck", 100) {}
void Truck::drive() const {
    std::cout << "Truck перевозить вантажі зі швидкістю до 95 км/год.\n";
}