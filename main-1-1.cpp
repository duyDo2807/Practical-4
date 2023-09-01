#include "Bus.h"
#include "Car.h"
#include "Motorbike.h"
#include "Vehicle.h"

int main() {
  int numCars, numBuses, numMotorbikes;
  std::cout << "Enter the number of cars: ";
  std::cin >> numCars;
  std::cout << "Enter the number of buses: ";
  std::cin >> numBuses;
  std::cout << "Enter the number of motorbikes: ";
  std::cin >> numMotorbikes;

  const int maxVehicles = numCars + numBuses + numMotorbikes;
  Vehicle* vehicles[maxVehicles];

  int vehicleIndex = 0;

  for (int i = 1; i <= numCars; ++i) {
    vehicles[vehicleIndex++] = new Car(i);
  }

  for (int i = 1; i <= numBuses; ++i) {
    vehicles[vehicleIndex++] = new Bus(i + numCars);
  }

  for (int i = 1; i <= numMotorbikes; ++i) {
    vehicles[vehicleIndex++] = new Motorbike(i + numCars + numBuses);
  }

  std::cout << "\nParking Durations:" << std::endl;
  for (int i = 0; i < maxVehicles; i++) {
    std::cout << "Vehicle " << vehicles[i]->getType() << " "
              << vehicles[i]->getID() << " has parked for "
              << vehicles[i]->getParkingDuration() << " seconds" << std::endl;
    delete vehicles[i];
  }

  return 0;
}