#include "Board.h"

Board::Board (size_t newsize){
	bsize=newsize;
	board=new Piece*[bsize];
	for(int i=0;i<bsize;i++){
		board[i]=new Piece[bsize];
	}
}

Board::Board (Board &b){
	bsize=b.bsize;
	board=new Piece*[bsize];
	for(int i=0;i<bsize;i++){
		board[i]=new Piece[bsize];
	}
	for (int i=0; i<bsize; i++){
		for (int j=0; j<bsize; j++){
			board[i][j]=b.board[i][j];
		}
	}
}

Board::~Board(){
	for(int i=0;i<bsize;i++){
		delete board[i];
	}
	delete board;
};


Board& Board::operator = (Board newb){
	bsize=newb.bsize;
	for (int i=0; i<newb.bsize; i++){
		for (int j=0; j<newb.bsize; j++){
			board[i][j]=newb.board[i][j];
		}
	}
	return *this;
};

Board& Board::operator = (char c){
	if(c!='X'&&c!='O'&&c!='.') throw IllegalCharException(c);
	for (int i=0; i<bsize; i++){
		for (int j=0; j<bsize; j++){
			board[i][j]=c;
		}
	}
	return *this;
};


std::ostream& operator<<(std::ostream& o, Board const& b){
	string matrix="";
	for (int i=0; i<b.bsize; i++){
    for (int j=0; j<b.bsize; j++){
      matrix+=b.board[i][j].getValue();
    }
    matrix+="\n";
  }
  return o<<matrix;
}

Piece& Board::operator [] (const Coordinate& c) const{
	if(c.getI()>bsize-1||c.getJ()>bsize-1){
		throw IllegalCoordinateException(c);
	}
	return board[c.getI()][c.getJ()];
}

uint Board:: size() const{
	return bsize;
}

//char operator [] (const Coordinate& place) const{
//	int x=place.getI();
//	int y=place.getJ();
//	return board[{x,y}]
//}
