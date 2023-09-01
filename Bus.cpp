#include "Bus.h"

Bus::Bus(int id) : Vehicle(id) {}

int Bus::getParkingDuration() { return Vehicle::getParkingDuration() * 0.75; }

int Bus::getID() { return Vehicle::getID(); }

std::string Bus::getType() { return "Bus"; }