#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"

class Bus : public Vehicle {
 public:
  Bus(int id);
  int getParkingDuration();
  int getID();
  std::string getType();
};

#endif