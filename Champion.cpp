#include "Champion.h"


const Coordinate Champion::play(const Board& board) {

	static Coordinate c{0, board.size()};
	static Coordinate d{board.size(), 0};
	 Coordinate zero{0,0};
	 Coordinate zo{0,1};
	 Coordinate oz{1,0};
	size_t counter=0;
	size_t count_down=board.size();
	if (board[zero]=='.') return c;
	if (board[zero]!='.' && board[oz]=='.' && board[zo]=='.') return c;
	if (board[zero]!='.'){
		Coordinate d{count_down, counter};
		counter++;
		count_down--;
	}
	return d;
}
