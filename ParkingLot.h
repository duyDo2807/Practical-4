#ifndef PARKINGLOT_H
#define PARKINGLOT_H
#include "Vehicle.h"

class ParkingLot {
 private:
  int capacity;
  int currentCount;
  Vehicle** vehicles;

 public:
  ParkingLot(int capacity);
  int getCount();
  void parkVehicle(Vehicle* vehicle);
  void unparkVehicle(int id);

  int countOverstayingVehicles(int maxParkingDuration);
};

#endif