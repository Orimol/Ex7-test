#include "Champion.h"


const Coordinate Champion::play(const Board& board) {
	//for (uint x=board.size(); x>0; --x) {
	//	for (uint y=board.size(); y>0; --y) {
//
//		}
//
//	}
	static Coordinate c{0, board.size};
	static Coordinate d{board.size, 0};
	Coordinate zero{0,0};
	Coordinate zo{0,1};
	Coordinate oz{1,0};
	int counter=0;
	int count_down=board.size;
	if (board[zero]=='.') return c;
	if (board[zero]!='.' && board[oz]=='.' && board[zo]=='.') return c;
	if (board[zero]!='.'){
		Coordinate d{count_down, counter};
		counter++;
		count_down--;
	}
		//&& board[{0,1}]=='.' && board[{1,0}]=='.') return d;

	/*if(board[{0,0}]!='.' && board[{0,1}]!='.') {
		counter++;
		Coordinate c{board.size-counter, board.size};
	}
	else if(board[{0,0}]!='.' && board[{1,0}]!='.'){
		counter++;
		Coordinate c{board.size,board.size-counter};
	}*/
	return d;


}
