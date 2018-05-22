#include "Coordinate.h"

Coordinate::Coordinate (size_t newi, size_t newj):i(newi),j(newj){}
Coordinate::Coordinate ():i(0),j(0){}


size_t Coordinate::getI()const{
  return i;
}

size_t Coordinate::getJ()const{
  return j;
}


Coordinate& Coordinate::operator = (Coordinate newc){
  i = newc.getI();
  j = newc.getJ();
  return *this;
}
