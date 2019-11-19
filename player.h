#pragma once
#include "header.h"


struct playerRetangle {
	void draw(RenderWindow&, int, int );
	void changeDirection(int&, int&, int&);
	void moveDirection(int&, int&, int&, const int);
};