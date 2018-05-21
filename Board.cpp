#include "Board.h"

Board::Board (size_t newsize){
	size=newsize;
	board=new Piece*[size];
	for(int i=0;i<size;i++){
		board[i]=new Piece[size];
	}
}

Board::Board (Board &b){
	size=b.size;
	board=new Piece*[size];
	for(int i=0;i<size;i++){
		board[i]=new Piece[size];
	}
	for (int i=0; i<size; i++){
		for (int j=0; j<size; j++){
			board[i][j]=b.board[i][j];
		}
	}
}

Board::~Board(){
	for(int i=0;i<size;i++){
		delete board[i];
	}
	delete board;
};


Board& Board::operator = (Board newb){
	size=newb.size;
	for (int i=0; i<newb.size; i++){
		for (int j=0; j<newb.size; j++){
			board[i][j]=newb.board[i][j];
		}
	}
	return *this;
};

Board& Board::operator = (char c){
	if(c!='X'&&c!='O'&&c!='.') throw IllegalCharException(c);
	for (int i=0; i<size; i++){
		for (int j=0; j<size; j++){
			board[i][j]=c;
		}
	}
	return *this;
};


std::ostream& operator<<(std::ostream& o, Board const& b){
	string matrix="";
	for (int i=0; i<b.size; i++){
    for (int j=0; j<b.size; j++){
      matrix+=b.board[i][j].getValue();
    }
    matrix+="\n";
  }
  return o<<matrix;
}

Piece& Board::operator [] (const Coordinate& c){
	if(c.getI()>size-1||c.getJ()>size-1){
		throw IllegalCoordinateException(c);
	}
	return board[c.getI()][c.getJ()];
}
