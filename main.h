#pragma once
#include "header.h"
#include "files.h"



Clock playClock;
Time time1;

playerRetangle pMove;
checkPlayer pCheck;
lost playerLost;
applePoint apple;
snakeTail tail;

Event event;

const int FPS(60); // Sets FPS to 30 so it will always run at the same speed
const int sizeWindowX(600), sizeWindowY(400); //Sets the size of the window to a const so it re-usable
const int speed(10); //Sets the speed of the player.
const int gameSpeed(100); //Sets the speed of game. Does this by setting timer that loops untill it's a 100 Miliseconds than does all the functions and resets timer
int appleX, appleY;
int playerX(sizeWindowX / 2), playerY(sizeWindowY / 2); //Default spawning location for player. Player starts in center
int slowingDownPlayer(1); //Only triggers once at the beginning. (for now)
int dir(4); //Default direction for player. Which is the middle of the screen and doesn't move
int points(0);
int testTimer(0);
bool alive = true;
bool appleHit = false; //set to true to trigger setting apple at random location. Once set it will set it self to false (Not true atm)
