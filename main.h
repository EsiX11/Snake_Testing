#pragma once
#include "SFML/Graphics.hpp"
#include <Windows.h>
#include <random>
#include <iostream>

using namespace sf;
using namespace std;


struct playerRetangle {
	void draw(RenderWindow&, int, int);
	void changeDirection(int&, int&, int&);
	void moveDirection(int&, int&, int&);
};
struct checkPlayer {
	void outOfBounds(const int, const int, bool&, const int, const int);
};

