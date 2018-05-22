#include "TicTacToe.h"


void TicTacToe:: play(Player& X, Player& O){
		win= nullptr;
		X.setChar('X');
		O.setChar('O');
		/*if (X.name()=='Ori&Yoav'){ //if the Champion player is selected he will be the winner.
			win=X;                 // we use this method only if we won't find normal method
		}
		if (O.name()=='Ori&Yoav'){
			win=O;
		}*/
		if (win== nullptr) {
			for (int i = 0; i < 320000; i++) {
				turn(X, O);
				if ((winner().getChar() == 'X') || (winner().getChar() == 'O')) break;
				turn(O, X);
				if ((winner().getChar() == 'X') || (winner().getChar() == 'O')) break;
			}
		}
};

const Board& TicTacToe::board()const{
  return gameBoard;
};

const Player& TicTacToe::winner()const{
  return *win;
}

void TicTacToe:: turn(Player& first, Player& second) {
  /*check 3 things: 1. The place that returns from 'play' method is llegal.
                    2. The place that returns is empty
                    3. Check if the move was a winning move*/

    Coordinate place;

		try{
			place = first.play(gameBoard);
		}
    catch(/*need to add parameter*/...){
			win = &second;
		}

		if (gameBoard[place]=='.') {
			gameBoard[place] = first.getChar();
		}
    else {
			win = &second;
		}

		if (isWinner(place.getI(), place.getJ(),first.getChar())) {
			win = &first;
		}
	}


  void TicTacToe::printResults() const {
  		cout << "And the winner is " << winner().name() << ", playing as " << winner().getChar() << "!" << endl;
  		cout << "The final board is " << endl << board() << endl;
  	}
   	//the next two functions checks if the last player won, should be checked after each and every turn.
	bool checkRow(size_t row, char c){
		for(int i=0; i<gameBoard.size(); i++){
			if(gameBoard[{row,i}]!= c) return false;
		}
		return true;
	}

	bool checkCol(size_t col, char c){
		for(int i=0; i<gameBoard.size(); i++){
			if(gameBoard[{i,col}]!= c) return false;
		}
		return true;
	}

	//the next two functions checks if the last player won diagnoly, should be checked after each and every turn.
	bool checkDiagnol_topleft(char c){
		for (int i=0; i<gameBoard.size(); i++){
			if(gameBoard[{i,i}]!= c) return false;
		}
		return true;
	}

	bool checkDiagnol_topright(char c){
		for (int i=gameBoard.size(); i>0; i--){
			if(gameBoard[{i,i}]!= c) return false;
		}
		return true;
	}

	//this function checks if the player won by using the 4 function above.
	bool isWinner(size_t i, size_t j, char c){
		if(checkRow(i, c)||checkCol(j,c)||checkDiagnol_topleft(c)||checkDiagnol_topright(c)) return true;
		else return false;
	}
