#include "ShopButton.h"
#include "View.h"
#include "Game.h"


ShopButton::ShopButton(int mainTexture, int overTexture, int clickedTexture, std::string _info, sf::Vector2f &position, View *parent, Game * game) :
Button(mainTexture, overTexture, clickedTexture, position, parent, game)
{
	info = _info;
	font.loadFromFile("arial.ttf");
}

ShopButton::~ShopButton()
{
}

void ShopButton::doAction()
{

}

void ShopButton::onHover()
{
	sf::Text text(info, font, 20);
	text.setPosition(sf::Vector2f(637, 565));
}
