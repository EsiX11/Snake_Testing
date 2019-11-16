#include "main.h"

//fix hitbox out of bounds 

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

	const int FPS(30); // Sets FPS to 30 so it will always run at the same speed
	const int sizeWindowX(600), sizeWindowY(400); //Sets the size of the window to a const so it re-usable
	const int speed(5); //Sets the speed of the player.
	int playerX(sizeWindowX / 2), playerY(sizeWindowY / 2); //Default spawning location for player. Player starts in center
	int appleX, appleY;
	int slowingDownPlayer(0); //Only triggers once at the beginning. (for now)
	int dir(4); //Default direction for player. Which is the middle of the screen and doesn't move
	int points(0);
	bool alive = true; 
	bool appleHit = false; //set to true to trigger setting apple at random location. Once set it will set it self to false
	
	

	RenderWindow window(VideoMode(sizeWindowX, sizeWindowY), "Snake!"); // Create the main window

	window.setFramerateLimit(FPS); // Sets FPS to 60 so it will always run at the same speed

	playerRetangle pMove;
	checkPlayer pCheck;
	lost playerLost;
	applePoint apple;
	snakeTail tail;
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


		// Clear screen

		window.clear();
		drawBackground(window, sizeWindowX, sizeWindowY);
		
		//Player drawing + moving
		if (alive) {
			pMove.changeDirection(playerX, playerY, dir,slowingDownPlayer); //checks user input (change name)
			pMove.moveDirection(playerX, playerY, dir, speed); //changes direction
			pMove.draw(window, playerX, playerY); //Draws player rectangle
			pCheck.outOfBounds(playerX, playerY, alive, sizeWindowX, sizeWindowY); //check if player is out of bounds
			pCheck.hitApple(playerX, playerY, appleX, appleY, appleHit); //checks if player hit apple
			if (appleHit) {
				apple.spawnLocation(sizeWindowX, sizeWindowY, appleX, appleY); //Randomly chooses apple location
				tail.grow(playerX, playerY, slowingDownPlayer, dir); //Increases tail length
				points++;
				appleHit = false;
			}
			apple.draw(window, appleX, appleY); //draws apple at it's assigned random location
			for (int i(0); i < points; i++) {
				tail.draw(window); //draws tail (not yet working correctly)
			}
			tail.move(dir, speed); //Moves tail with head (Not yet working correctly)
		}
		else {
			playerLost.lostText(window, sizeWindowX, sizeWindowY);
		}
		// Update the window			
		window.display();
	}
	return EXIT_SUCCESS;
}




