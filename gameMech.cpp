#include "gameMech.h"


void lost::lostText(RenderWindow& window, const int sizeX, const int SizeY) {

	Font font;
	font.loadFromFile("fonts/arial.ttf");

	Text text("You lost!", font);

	text.setCharacterSize(50);
	text.setStyle(Text::Bold);
	text.setFillColor(Color::Red);

	FloatRect textRect = text.getLocalBounds(); //Gets the size of the text
	text.setOrigin(textRect.width / 2, textRect.height / 2); //Halfs it to find out middle to be able to center text
	text.setPosition(sf::Vector2f(sizeX / 2.0f, SizeY / 2.0f)); //Set position of text in the middle of the screen

	window.draw(text);
}

void snakeTail::grow(const int x, const  int y, const int timer, const int playerDir) {
	tailX = x;
	tailY = y;
	if (timer == 1) {
		/* 
		 * 0 = player moving Right
		 * 1 = player moving Left
		 * 2 = player moving Up
		 * 3 = player moving Down
		*/
		switch (playerDir) {
			case 0: tailX -= 5;
					break;
			case 1: tailX += 5;
					break;
			case 2: tailY += 5;
					break;
			case 3: tailY -= 5;
					break;
		}
	}

}

void snakeTail::draw(RenderWindow& window) {
	RectangleShape rectangle;
	rectangle.setSize(Vector2f(10, 10));
	rectangle.setFillColor(Color::Green);
	rectangle.move(Vector2f(tailX, tailY));

	window.draw(rectangle);
}

void snakeTail::move(const int playerDir, const int speed) {
	/*
	 * 0 = player moving Right
	 * 1 = player moving Left
	 * 2 = player moving Up
	 * 3 = player moving Down
	*/
	switch (playerDir) {
		case 0: tailX += speed*2;
				break;
		case 1: tailX -= speed*2;
				break;
		case 2: tailY -= speed*2;
				break;
		case 3: tailY += speed*2;
				break;
		default: tailX = tailX; tailY = tailY;
				break;
	}
}
