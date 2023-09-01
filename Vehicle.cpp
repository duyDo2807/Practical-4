#include "Vehicle.h"

Vehicle::Vehicle(int id) : ID(id), timeOfEntry(std::time(nullptr)) {}

int Vehicle::getID() { return ID; }

int Vehicle::getParkingDuration() {
  std::time_t currentTime = std::time(nullptr);
  return std::difftime(currentTime, timeOfEntry);
}

std::string Vehicle::getType() { return "No Type"; }