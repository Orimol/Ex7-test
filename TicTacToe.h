#pragma once
#include "Board.h"
#include "Player.h"
#include "coordinate.h"
using namespace std;

class TicTacToe{

  Board gameBoard;
  Player* win;

public:
//Constractor
    TicTacToe (size_t size):gameBoard(size){};

//methods
    void play(player X, Player O);
    void turn(Player& first, Player& second);
    bool checkRow(size_t row, char c);
    bool checkCol(size_t col, char c);
    bool checkDiagnol_topleft(char c);
    bool checkDiagnol_topright(char c);
    void printResults() const;
    const Board& board()const;
    const Player& winner()const;
    bool isWinner(size_t i, size_t j, char c);
};
