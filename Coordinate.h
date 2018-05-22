#pragma once
#include <iostream>
#include <string>
using namespace std;

class Coordinate{
private:
  size_t i,j;

public:
//Constractor
    Coordinate (size_t i, size_t j);
    Coordinate();

    size_t getI()const;
    size_t getJ()const;

    Coordinate& operator = (Coordinate newc);
};
