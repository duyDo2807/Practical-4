#include <cctype>
#include <iostream>

#include "Bus.h"
#include "Car.h"
#include "Motorbike.h"
#include "ParkingLot.h"

int main() {
  ParkingLot parkingLot(10);
  int count = 0;
  while (count < 10) {
    std::string vehicle;
    std::cout << "Enter vehicle type:";
    std::cin >> vehicle;
    for (char& c : vehicle) {
      c = std::tolower(c);
    }

    Vehicle* newVehicle;
    if (vehicle == "car") {
      newVehicle = new Car(parkingLot.getCount() + 1);
    } else if (vehicle == "bus") {
      newVehicle = new Bus(parkingLot.getCount() + 1);
    } else if (vehicle == "motorbike") {
      newVehicle = new Motorbike(parkingLot.getCount() + 1);
    } else {
      std::cout
          << "Invalid vehicle type. Please enter 'car', 'bus', or 'motorbike'."
          << std::endl;
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
    count++;
  }

  int countOverstay = parkingLot.countOverstayingVehicles(15);
  std::cout << "Number of vehicle overstayed: " << countOverstay << std::endl;

  return 0;
}