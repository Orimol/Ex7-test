#include "Champion.h"


const Coordinate Champion::play(const Board& board) {

	static const Coordinate c{0, board.size};
	static const Coordinate d{board.size, 0};
	const Coordinate zero{0,0};
	const Coordinate zo{0,1};
	const Coordinate oz{1,0};
	int counter=0;
	int count_down=board.size;
	if (board[zero]=='.') return c;
	if (board[zero]!='.' && board[oz]=='.' && board[zo]=='.') return c;
	if (board[zero]!='.'){
		Coordinate d{count_down, counter};
		counter++;
		count_down--;
	}
	return d;
}
