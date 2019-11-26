#include "main.h"

//turn back on hitbox out of bounds 

void drawBackground(RenderWindow& window,int x, int y) {
	RectangleShape background;
	background.setSize(Vector2f(x-20, y-20));
	background.setFillColor(Color(23,0,255));
	background.setPosition(10,10);
	background.setOutlineThickness(10);
	background.setOutlineColor(Color(255, 255, 50));
	
	window.draw(background);
}
/*
 * Snake made by Olaf Oude Reimer.
 * It will use WASD to move the snake around
 * The snake is not allowed outside the bounds
 * Hitting the red apple increases the snakes length
 * Hitting yourself or going out of bounds loses you the game.
*/
int main(){

	const int FPS(60); // Sets FPS to 30 so it will always run at the same speed
	const int sizeWindowX(600), sizeWindowY(400); //Sets the size of the window to a const so it re-usable
	const int speed(10); //Sets the speed of the player.
	int playerX(sizeWindowX / 2), playerY(sizeWindowY / 2); //Default spawning location for player. Player starts in center
	int appleX, appleY;
	int slowingDownPlayer(1); //Only triggers once at the beginning. (for now)
	int dir(4); //Default direction for player. Which is the middle of the screen and doesn't move
	int points(0);
	bool alive = true; 
	bool appleHit = false; //set to true to trigger setting apple at random location. Once set it will set it self to false (Not true atm)
	int testTimer(0);
	
	RenderWindow window(VideoMode(sizeWindowX, sizeWindowY, 32), "Snake!"); // Create the main window

	window.setFramerateLimit(FPS); // Sets FPS to 60 so it will always run at the same speed

	//random location for apple
	apple.spawnLocation(sizeWindowX, sizeWindowY, appleX, appleY);
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
		time1 = playClock.getElapsedTime();
		//Player drawing + moving
		if (alive) {
			// Clear screen
			window.clear();
			drawBackground(window, sizeWindowX, sizeWindowY);
			pMove.changeDirection(playerX, playerY, dir); //checks user input (change name)
			//Slows the game down and makes it able to move in jumps of 10 instead of 5 which is half of the blocks size.
			if (time1.asMilliseconds() >= 100) {
				tail.currentPosPlayer(playerX, playerY);
				pMove.moveDirection(playerX, playerY, dir, speed); //changes direction. X & Y changed here.
				pCheck.outOfBounds(playerX, playerY, alive, sizeWindowX, sizeWindowY); //check if player is out of bounds
				pCheck.hitApple(playerX, playerY, appleX, appleY, appleHit); //checks if player hit apple
				if (appleHit) { //Fix it not growing after getting 1 but not 2
					points++;
					tail.grow(); //Increases tail length (By pushing back vector with a 0)
					apple.spawnLocation(sizeWindowX, sizeWindowY, appleX, appleY); //Randomly chooses apple location
					appleHit = false;
				}
				tail.move();
				playClock.restart();
			}
			if (points > 0) {
				tail.draw(window); //draws tail (Doesn't draw in correct position)(Check notebook)
			}
			pMove.draw(window, playerX, playerY); //Draws player rectangle
			apple.draw(window, appleX, appleY); //draws apple at it's assigned random location
		}
		else {
			playerLost.lostText(window, sizeWindowX, sizeWindowY);
		}
	// Update the window			
	window.display();
	}
	return EXIT_SUCCESS;
}




