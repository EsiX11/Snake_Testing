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


void snakeTail::draw(RenderWindow& window) {
	for (int i(0); i < tailX.size(); i++) {
		rectangle.setSize(Vector2f(10, 10));
		rectangle.setFillColor(Color::Green);
		rectangle.setPosition(Vector2f(tailX[i], tailY[i]));
		window.draw(rectangle);
	}
}

void snakeTail::grow() {
	tailX.push_back(0);
	tailY.push_back(0);
}

void snakeTail::currentPosPlayer(const int x, const  int y) {
	if (tailX.empty()) {
		tailX.resize(1);
		tailY.resize(1);
	}
	tailX.at(0) = x;
	tailY.at(0) = y;

}
void snakeTail::move() {
	for (int i(0); i < tailX.size(); i++) {
		int max((tailX.size() - 1) - i);
		if (max >= 1) {
			tailX[max] = tailX[(max - 1)];
			tailY[max] = tailY[(max - 1)];
		}
	}
}
