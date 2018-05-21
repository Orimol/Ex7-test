#include "TicTacToe.h"


void TicTacToe:: play(Player& X, Player& O){
		X.setChar('X');
		O.setChar('O');
		for (int i=0; i<(size+1)/2; i++) {
			turn(X, O);
			if ((winner.getChar=='X')||(winner.getChar=='O')) break;
			turn(O, X);
			if ((winner.getChar=='X')||(winner.getChar=='O')) break;
		}
};

const Board& TicTacToe::board()const{
  return gameBoard;
};

const Player& TicTacToe::winner()const{
  return *win;
}

void TicTacToe:: turn(Player& first, Player& second) {
  /*check 3 things: 1. The place that returns from 'play' method is ligal.
                    2. The place that returns is empty
                    3. Check if the move was a winning move*/

    Coordinate place;

		try{
			place = first.play(gameBoard);
		}
    catch(/*need to add parameter*/){
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
		for(int i=0; i<TicTacToe::gameBoard.size; i++){
			if(TicTacToe::gameBoard[{row,i}]!= c) return false;
		}
		return true;
	}

	bool checkCol(size_t col, char c){
		for(int i=0; i<TicTacToe::gameBoard.size; i++){
			if(TicTacToe::gameBoard[{i,col}]!= c) return false;
		}
		return true;
	}

	//the next two functions checks if the last player won diagnoly, should be checked after each and every turn.
	bool checkDiagnol_topleft(char c){
		for (int i=0; i<TicTacToe:: gameBoard.size; i++){
			if(TicTacToe::gameBoard[{i,i}]!= c) return false;
		}
		return true;
	}

	bool checkDiagnol_topright(char c){
		for (int i=TicTacToe:: gameBoard.size; i>0; i--){
			if(TicTacToe::gameBoard[{i,i}]!= c) return false;
		}
		return true;
	}

	//this function checks if the player won by using the 4 function above.
	bool isWinner(size_t i, size_t j, char c){
		if(checkRow(i, c)||checkCol(j,c)||checkDiagnol_topleft(c)||checkDiagnol_topright(c)) return true;
		else return false;
	}