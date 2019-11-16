#pragma once
#include "header.h"

struct applePoint {
	void draw(RenderWindow&, int, int);
	void spawnLocation(const int, const int, int&, int&);
};