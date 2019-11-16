#include "checkPlayer.h"

//Check if the player is outside of the screen 
void checkPlayer::outOfBounds(const int x, const int y, bool& alive, const int sizeWindowX, const int sizeWindowY) {
	if ((x >= sizeWindowX - 10) || (y >= sizeWindowY - 10)) {
		alive = false;
	}
	else if ((x <= 0) || (y <= 0)) {
		alive = false;
	}
}

/*
 * Creates 1d array for both player and apple. One runs of the y axis the other over the x axis to check whether
 * they line up meaning the player hit the apple and gets a point
 * IN: appleX & appleY & playerX & playerY & appleHit
 * OUT: 
 * pre-condition: 
 */
void checkPlayer::hitApple( int appleX, int appleY, int playerX, int playerY, bool& appleHit) {
	const int arraySizePlayer(10), arraySizeApple(10);
	int appleYArray[arraySizeApple], playerYArray[arraySizePlayer], appleXArray[arraySizeApple], playerXArray[arraySizePlayer];

	for (int i = 0; i < arraySizeApple; i++) {
		appleYArray[i] = appleY;
		appleY++;
	}	
	for (int i = 0; i < arraySizePlayer; i++) {
		playerYArray[i] = playerY;
		playerY++;
	}
	for (int i = 0; i < arraySizeApple; i++) {
		appleXArray[i] = appleX;
		appleX++;
	}
	for (int i = 0; i < arraySizePlayer; i++) {
		playerXArray[i] = playerX;
		playerX++;
	}
	/* 
	 * Checks every places in array against every place in other array.
	 * 2 arrays per object. 
	 * 1 x array and 1 y array.
	 * It will run through the Y array of both and compare them to eachother. If both of the arrays have the same Y number -
	 * it will go to the next check which will do the same but with the X arrays.
	 * If both are having corrosponding numbers it means the player got the apple.
	*/
	for (int i = 0; i < arraySizeApple; i++) {
		for (int j = 0; j < arraySizePlayer; j++) {
			//Checks if the Y axis are on the same line.
			if (appleYArray[i] == playerYArray[j]) {
				for (int k = 0; k < arraySizeApple; k++) {
					for (int g = 0; g < arraySizePlayer; g++) {
						//Check if X axis is on the same line. This check only occurs if the check for Y axis before is true
						if (appleXArray[k] == playerXArray[g]) {
							appleHit = true; //Sets to true if the snake head is hitting apple
							break; //So it won't keep check whether it's true or not
						}
					}
				}
			}
		}
	}
}