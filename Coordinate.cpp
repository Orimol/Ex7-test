#include "Coordinate.h"

Coordinate::Coordinate (size_t newi, size_t newj):i(newi),j(newj){}


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
