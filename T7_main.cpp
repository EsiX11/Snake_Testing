#include "main.h"


/*
SFML super skinny skeleton starter app
*/
int main(){

	const int sizeWindowX(1200), sizeWindowY(800);
	// Create the main window
	RenderWindow window(VideoMode(sizeWindowX, sizeWindowY), "Hello world!");
	window.setFramerateLimit(60);

	playerRetangle pMove;
	checkPlayer pCheck;

	int x(sizeWindowX / 2), y(sizeWindowY / 2); //Default spawning location for player
	int dir(4); //Default direction for player. Which is 0,0 and doesn't move.
	bool alive = true;

	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == Event::Closed)
				window.close();
		}


		// Clear screen
		window.clear();
		
		//Player drawing + moving
		if (alive) {
			pMove.draw(window, x, y); //Draws player rectangle
			pMove.changeDirection(x, y, dir);
			pMove.moveDirection(x, y, dir);
			pCheck.outOfBounds(x, y, alive, sizeWindowX, sizeWindowY);
		}
		// Update the window			
		window.display();
	}
	return EXIT_SUCCESS;
}


void playerRetangle::draw(RenderWindow& window, int x, int y) {

		RectangleShape rectangle;
		rectangle.setSize(Vector2f(10, 10));
		rectangle.setFillColor(Color::Green);
		rectangle.setPosition(x, y);
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

		if (GetAsyncKeyState('D')) {
			dir = 0;
		}
		else if (GetAsyncKeyState('A')) {
			dir = 1;
		}
		else if (GetAsyncKeyState('W')) {
			dir = 2;
		}
		else if (GetAsyncKeyState('S')) {
			dir = 3;
		}
		else if (GetAsyncKeyState('F')) {
			x = 600;
			y = 400;
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
void playerRetangle::moveDirection(int& x, int& y, int& dir) {

		int speed(7);

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

void checkPlayer::outOfBounds(const int x, const int y, bool& alive, const int sizeWindowX, const int sizeWindowY) {
	if ((x == sizeWindowX) && (y == sizeWindowY)) {
		alive = false;
	}
	else if ((x == 0) && (y == 0)) {
		alive = false;
	}
}


struct apple {

	void spawn() {
		int zX, zY;
		random_device rd;   // non-deterministic generator  
		mt19937 gen(rd());  // to seed mersenne twister.
		uniform_int_distribution<> dist(1, 8); // distribute results between 1 and 8 inclusive.
		zX = dist(gen);
		zY = dist(gen);
	}
};
