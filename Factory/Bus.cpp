#include "Bus.h"
#include <iostream>
Bus::Bus() : Vehicle("Bus", 120) {}
void Bus::drive() const {
    std::cout << "Bus перевозить пасажирів зі швидкістю до 120 км/год.\n";
}