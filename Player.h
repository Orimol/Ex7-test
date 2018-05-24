#pragma once
#include <string>
#include"Coordinate.h"
#include"Board.h"
using namespace std;

class Player{
protected:
	char myChar;

public:

  void setChar(char c) { myChar = c; }

	char getChar() const { return myChar; }

  virtual const string name()const=0;

  virtual const Coordinate play(const Board& board)=0;
};
