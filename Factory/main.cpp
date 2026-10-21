#include <iostream>
#include <memory>
#include "Vehicle.h"
#include "VehicleFactory.h"
#include <windows.h>
void printMenu() {
    std::cout << "\n=== Вибір транспортного засобу ===\n"
        << "1 - Car (легковий автомобіль)\n"
        << "2 - Truck (вантажівка)\n"
        << "3 - Bus (автобус)\n"
        << "Введіть номер: ";
}
int main() {
	SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    printMenu();
    int choice = 0;
    std::cin >> choice;
    // об'єкт створює фабрику а не мейн
    std::unique_ptr<Vehicle> vehicle = VehicleFactory::create(choice);
    if (!vehicle) {
        std::cout << "Помилка: транспорту з таким номером не існує.\n";
        return 1;
    }
    std::cout << "\nСтворено: " << vehicle->getName() << "\n"
        << "Максимальна швидкість: " << vehicle->getMaxSpeed() << " км/год\n";
    vehicle->drive();
    return 0;
}