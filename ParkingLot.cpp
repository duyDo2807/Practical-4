#include "ParkingLot.h"

ParkingLot::ParkingLot(int capacity) : capacity(capacity), currentCount(0) {
  vehicles = new Vehicle*[capacity];
  for (int i = 0; i < capacity; i++) {
    vehicles[i] = nullptr;
  }
}

int ParkingLot::getCount() { return currentCount; }

void ParkingLot::parkVehicle(Vehicle* vehicle) {
  if (currentCount < capacity) {
    vehicles[currentCount] = vehicle;
    currentCount++;
  } else {
    std::cout << "The lot is full" << std::endl;
  }
}

void ParkingLot::unparkVehicle(int id) {
  for (int i = 0; i < capacity; i++) {
    if (vehicles[i] != nullptr && vehicles[i]->getID() == id) {
      delete vehicles[i];
      vehicles[i] = nullptr;

      if (i < currentCount - 1) {
        vehicles[i] = vehicles[currentCount - 1];
        vehicles[currentCount - 1] = nullptr;
      }

      currentCount--;
      std::cout << "Vehicle " << id << " has been unparked." << std::endl;
      return;
    }
  }
  std::cout << "Vehicle not in the lot." << std::endl;
}

int ParkingLot::countOverstayingVehicles(int maxParkingDuration) {
  int countStay = 0;
  for (int i = 0; i < capacity; i++) {
    if (vehicles[i] != nullptr) {
      int parkingDuration = vehicles[i]->getParkingDuration();
      if (parkingDuration > maxParkingDuration) {
        countStay++;
      }
    }
  }
  return countStay;
}