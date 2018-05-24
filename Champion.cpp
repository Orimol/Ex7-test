#include "Champion.h"


const Coordinate Champion::play(const Board& board) {
	Coordinate c{board.size()-1, 0};
	Coordinate d{0, board.size()-1};
	if (board[c]=='.') return c;
	if (board[d]=='.') return d;
	for (uint i=1; i<board.size(); i++){
		Coordinate	ce{i, board.size()-1}	;
		if (board[ce]=='.') return ce;
	}
	return c;
}
