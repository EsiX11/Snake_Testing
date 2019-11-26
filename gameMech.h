#pragma once
#include "header.h"
#include <vector>
#include <string>

struct lost {
	void lostText(RenderWindow&, const int, const int );
};

struct snakeTail {
public:	
	//x, y, dir, speed, size(Size of vector)
	void grow(const int, const int);
	//window, size(Location of data)
	void draw(RenderWindow&, const int);
	void currentPosPlayer(const int, const  int, const int, const int);
	void move();
private:
	vector<int> tailX;
	vector<int> tailY;
	RectangleShape rectangle;
	vector<int> playerDirLast;
};