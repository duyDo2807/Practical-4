#include "Car.h"

Car::Car(int id) : Vehicle(id) {}

int Car::getParkingDuration() { return Vehicle::getParkingDuration() * 0.9; }

int Car::getID() { return Vehicle::getID(); }

std::string Car::getType() { return "Car"; }