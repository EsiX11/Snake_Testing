#pragma once
#include "header.h"
#include <vector>

struct lost {
	void lostText(RenderWindow&, const int, const int );
};

struct snakeTail {
public:	
	//x, y, dir, speed, size(Size of vector)
	void grow(int,int,int, const int, const int);
	//window, size(Location of data)
	void draw(RenderWindow&, const int);
	//dir, speed, size(Location of data)
	void move(const int, const int, const int);
	int test;
	vector<int> tailX;
	vector<int> tailY;
private:


};