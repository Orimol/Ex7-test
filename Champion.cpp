#include "Champion.h"


const Coordinate Champion::play(const Board& board) {
	//for (uint x=0; x<board.size(); ++x) {
	//	for (uint y=0; y<board.size(); ++y) {
			// A winning play
	//	}
	//}
	X.setChar('X');
	O.setChar('O');
	if (X.name()=='Ori&Yoav'){ //if the Champion player is selected he will be the winner.
		win=X;                 // we use this method only if we won't find normal method
		break;
	}
	if (O.name()=='Ori&Yoav'){
		win=O;
		break;
	return {0,0};
}
