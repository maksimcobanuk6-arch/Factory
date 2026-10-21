#include "Vehicle.h"
#include <utility>
Vehicle::Vehicle(std::string name, int maxSpeed)
    : name_(std::move(name)), maxSpeed_(maxSpeed) {
}
const std::string& Vehicle::getName() const { return name_; }
int Vehicle::getMaxSpeed() const { return maxSpeed_; }