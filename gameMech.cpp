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

void snakeTail::grow(const int x, const  int y, const int playerDir, const int speed, const int size) {
	/* 
	 * 0 = player moving Right
	 * 1 = player moving Left
	 * 2 = player moving Up
	 * 3 = player moving Down
	*/
	switch (playerDir) {
		case 0: tailX.push_back((x - 15));
				tailY.push_back(y);
				break;
		case 1: tailX.push_back((x + 15));
				tailY.push_back(y);
				break;
		case 2: tailY.push_back((y + 15));
				tailX.push_back(x);
				break;
		case 3: tailY.push_back((y - 15));
				tailX.push_back(x);
				break;
		default: tailY.push_back(1000);
	}

}
void snakeTail::draw(RenderWindow& window,const int size) {
	RectangleShape rectangle;
	rectangle.setSize(Vector2f(10, 10));
	rectangle.setFillColor(Color::Green);
	rectangle.setPosition(Vector2f(tailX[size - 1], tailY[size - 1]));

	window.draw(rectangle);
	test++;
}

void snakeTail::move(const int playerDir, const int speed, const int size) {
	/*
	 * 0 = player moving Right
	 * 1 = player moving Left
	 * 2 = player moving Up
	 * 3 = player moving Down
	*/
	switch (playerDir) {
		case 0: tailX.at(size) += speed;
				break;
		case 1: tailX.at(size) -= speed;
				break; 
		case 2: tailY.at(size) -= speed;
				break;
		case 3: tailY.at(size) += speed;
				break;
		default: tailX.at(size) = tailX[size]; tailY[size] = tailY[size];
				break;
	}
}
