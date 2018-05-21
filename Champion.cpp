#include "Champion.h"


const Coordinate Champion::play(const Board& board) {
	//for (uint x=board.size(); x>0; --x) {
	//	for (uint y=board.size(); y>0; --y) {
//
//		}
//
//	}
	static Coordinate c{board.size(), board.size()};
	int counter=board.size();
	if (board[{0,0}]=='.') return {c};
	if (board[{0,0}]!='.' && board[{0,1}]=='.' && board[{1,0}]=='.') return c;
	if(board[{0,0}]!='.' && board[{0,1}]!='.') {
		counter++;
		Coordinate c{board.size()-counter, board.size()};
	}
	else if(board[{0,0}]!='.' && board[{1,0}]!='.'){
		counter++;
		Coordinate c{board.size(),board.size()-counter};
	}
	return c;


}
