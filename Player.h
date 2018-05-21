#pragma once
#include <string>
#include"Coordinate.h"
using namespace std;

class Player{
protected:
	char pChar;

public:

  void setChar(char c) { pChar = c; }

	char getChar() const { return pChar; }

  virtual const string name()const;

  virtual const Coordinate play(const Board& board);
};
