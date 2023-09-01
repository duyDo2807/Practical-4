#include "Motorbike.h"

Motorbike::Motorbike(int id) : Vehicle(id) {}

int Motorbike::getParkingDuration() {
  return Vehicle::getParkingDuration() * 0.85;
}

int Motorbike::getID() { return Vehicle::getID(); }

std::string Motorbike::getType() { return "Motorbike"; }