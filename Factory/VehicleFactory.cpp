#include "VehicleFactory.h"
#include "Bus.h"
#include "Car.h"
#include "Truck.h"
std::unique_ptr<Vehicle> VehicleFactory::create(int type) {
    switch (type) {
    case CAR:   return std::make_unique<Car>();
    case TRUCK: return std::make_unique<Truck>();
    case BUS:   return std::make_unique<Bus>();
    default:    return nullptr;
    }
}