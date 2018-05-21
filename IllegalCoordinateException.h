#pragma once
#include <iostream>
#include <string>
#include "Coordinate.h"
using namespace std;

class IllegalCoordinateException{
private:
  Coordinate c;
public:
//Constractor
    IllegalCoordinateException (Coordinate newc);

    string theCoordinate()const;
};
