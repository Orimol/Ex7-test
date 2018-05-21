#pragma once
#include <iostream>
#include <string>
#include "Piece.h"
#include "Coordinate.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"
using namespace std;

class Board{

private:
  Piece **board;
    uint bsize;


public:
//Constractor and Destractor
    Board (size_t newsize);
    Board (Board &b);
    ~Board();

//Methods

Board& operator = (Board newb);

Board& operator = (char c);

uint size() const;

friend std::ostream& operator<<(std::ostream& o, Board const& b);

Piece& operator [] (const Coordinate& c) const;

//char operator [] (const Coordinate&) const;

}
;
