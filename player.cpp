#include "player.h"

void playerRetangle::draw(RenderWindow& window, int x, int y) {
	RectangleShape rectangle;
	rectangle.setSize(Vector2f(10, 10));
	rectangle.setFillColor(Color::Yellow);
	rectangle.move(Vector2f(x, y));

	window.draw(rectangle);
}

/*
 * Gets player input to change players direction.
 * 0 = Right
 * 1 = left
 * 2 = Up
 * 3 = Down
*/

void playerRetangle::changeDirection(int& x, int& y, int& dir) {
	
	//To make sure the player doesn't end up half on the grid. Now the player can only move 10 pixels instead of 5.
	//Without having to make the player go 10 pixel per frame.
	if ((GetAsyncKeyState('D')) && !(dir == 1)) {
		dir = 0;
	}
	else if ((GetAsyncKeyState('A')) && !(dir == 0)) {
		dir = 1;
	}
	else if ((GetAsyncKeyState('W')) && !(dir == 3)) {
		dir = 2;
	}
	else if ((GetAsyncKeyState('S')) && !(dir == 2)) {
		dir = 3;
	}
	else if (GetAsyncKeyState('F')) {
		x = 20;
		y = 20;
	}

}
/*
 * Changes player direction corresponding to player input. The player will keep moving towards that direction
 * Until player changes direction. Than player keeps moving towards updated direction
 * 0 = Right
 * 1 = Left
 * 2 = Up
 * 3 = Down
*/
void playerRetangle::moveDirection(int& x, int& y, int& dir,const int speed) {

	switch (dir) {
		case 0: x += speed;
				break;
		case 1: x -= speed;
				break;
		case 2: y -= speed;
				break;
		case 3: y += speed;
				break;
		default: y = y, x = x;
				break;
	}

}
