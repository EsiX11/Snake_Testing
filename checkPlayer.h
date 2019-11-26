#pragma once
#include "header.h"
#include "gameMech.h"

struct checkPlayer {
public:
	void outOfBounds(const int, const int, bool&, const int, const int);
	void hitApple(int, int, int, int, bool&);
	bool hitTail(const int, const int);
private:
	snakeTail tail;
	bool hit;
};