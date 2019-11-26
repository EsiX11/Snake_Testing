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

	RenderWindow window(VideoMode(sizeWindowX, sizeWindowY, 32), "Snake!"); // Create the main window

	window.setFramerateLimit(FPS); // Sets FPS to 60 so it will always run at the same speed

	apple.spawnLocation(sizeWindowX, sizeWindowY, appleX, appleY);	//random location for apple
	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		while (window.pollEvent(event))
		{
			// Close window: exit
			if ((event.type == Event::Closed) || (Keyboard::isKeyPressed(Keyboard::Escape)))
				window.close();
		}
		time1 = playClock.getElapsedTime(); //Starts timer for game speed
		//Player drawing + moving
		if (alive) {
			// Clear screen
			window.clear();
			drawBackground(window, sizeWindowX, sizeWindowY);
			//Slows the game down and makes it able to move in jumps of 10 instead of 5 which is half of the blocks size.
			if (time1.asMilliseconds() >= gameSpeed) {
				pMove.changeDirection(playerX, playerY, dir); //checks user input (change name)
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
				tail.move(); //Moves the tail behind the head
				playClock.restart(); //Resets to 0 to start counting up again (For game speed)
				
			}
			if (points > 0) {
				tail.draw(window); //draws tail
				if ((alive))
					alive = !(tail.hit(playerX, playerY));
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




