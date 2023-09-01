#ifndef VEHICLE_H
#define VEHICLE_H
#include <ctime>
#include <iostream>

class Vehicle {
 private:
  std::time_t timeOfEntry;
  int ID;

 public:
  Vehicle(int id);
  int getID();
  virtual int getParkingDuration();
  virtual std::string getType();
};

#endif