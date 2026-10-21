#pragma once
#include <string>
// Базовий (абстрактний) клас для будь-якого транспортного засобу.
class Vehicle {
public:
    Vehicle(std::string name, int maxSpeed);
    virtual ~Vehicle() = default;  // віртуальний деструктор
    const std::string& getName() const;
    int getMaxSpeed() const;
    // Кожен конкретний транспорт описує рух по-своєму.
    virtual void drive() const = 0;
private:
    std::string name_;
    int maxSpeed_;
};