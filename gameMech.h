#pragma once
#include "header.h"

struct lost {
	void lostText(RenderWindow&, const int, const int );
};

struct snakeTail {
	int tailX, tailY;
	void grow(int,int,int,int);
	void draw(RenderWindow&);
	void move(const int, const int);
};