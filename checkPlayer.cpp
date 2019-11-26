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
 * Checks whether both x & y line up meaning player is on the apple. Increases point by 1
 * IN: appleX & appleY & playerX & playerY & appleHit
 * OUT: 
 * pre-condition: 
 */
void checkPlayer::hitApple( int appleX, int appleY, int playerX, int playerY, bool& appleHit) {
	if ((appleX == playerX) && (appleY == playerY)) {
		appleHit = true;
	}
}

bool checkPlayer::hitTail(const int playerX, const int playerY) {
	hit = tail.hit(playerX, playerY);
	return (hit);
}