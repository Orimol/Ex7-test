#pragma once
#include "Player.h"

/*
	This player should win the XYPlayer and YXPlayer asstratagy
*/
class Champion: public Player {
public:
	const string name() const override { return "Ori&Yoav"; }
	const Coordinate play(const Board& board) override;
};
