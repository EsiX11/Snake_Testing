#include "apple.h"

//draws apple.
void applePoint::draw(RenderWindow& window,int appleLocationX, int appleLocationY) {
	RectangleShape rectangle;
	rectangle.setSize(Vector2f(10, 10));
	rectangle.setFillColor(Color::Red);
	rectangle.setPosition(appleLocationX, appleLocationY); //These are randomly generated in apple::spawnLocation().
	window.draw(rectangle);
}

//spawns apple at a random location.
void applePoint::spawnLocation(const int maxX, const int maxY, int& appleLocationX, int& appleLocationY) {
	random_device rd;   // non-deterministic generator  
	mt19937 gen(rd());  // to seed mersenne twister.
	uniform_int_distribution<> distX(10, maxX-30); // distribute results between 5 and and max screen size inclusive. -10 so it won't be offscreen
	uniform_int_distribution<> distY(10, maxY-30); // Start at 5 so it won't be off screen.
	do {
		appleLocationX = distX(gen);
		appleLocationY = distY(gen);
	} while (!((appleLocationX % 10) == 0) || !((appleLocationY % 10) == 0)); //Makes sure that 
}
