#include <cctype>
#include <iostream>

#include "Bus.h"
#include "Car.h"
#include "Motorbike.h"
#include "ParkingLot.h"

int main() {
  ParkingLot parkingLot(10);
  while (parkingLot.getCount() < 10) {
    std::string vehicle;
    std::cout << "Enter vehicle type:";
    std::getline(std::cin, vehicle);
    for (char& c : vehicle) {
      c = std::tolower(c);
    }

    Vehicle* newVehicle = nullptr;
    if (vehicle == "car") {
      newVehicle = new Car(parkingLot.getCount() + 1);
    } else if (vehicle == "bus") {
      newVehicle = new Bus(parkingLot.getCount() + 1);
    } else if (vehicle == "motorbike") {
      newVehicle = new Motorbike(parkingLot.getCount() + 1);
    } else if (vehicle.empty()) {
      newVehicle = nullptr;
    } else {
      std::cout << "Invalid vehicle type." << std::endl;
      continue;
    }

    parkingLot.parkVehicle(newVehicle);
    if (newVehicle != nullptr) {
      std::cout << "Vehicle " << newVehicle->getType() << " has been parked."
                << std::endl;
    } else {
      std::cout << "No vehicle has been parked for ID: "
                << parkingLot.getCount() << std::endl;
    }
  }

  if (parkingLot.getCount() == 10) {
    std::cout << "The lot is full" << std::endl;
  }

  int IDunpark;
  std::cout << "Enter ID vehicle to unpark:";
  std::cin >> IDunpark;

  parkingLot.unparkVehicle(IDunpark);

  return 0;
}