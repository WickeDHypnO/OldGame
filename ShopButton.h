#pragma once
#include "Button.h"
#include <string>
class ShopButton :
	public Button
{
public:
	ShopButton(int mainTexture, int overTexture, int clickedTexture, std::string _info, sf::Vector2f &position, View * parent, Game * game);
	~ShopButton();
	std::string info;
private:
	sf::Font font;
	void doAction();
	void onHover();
};