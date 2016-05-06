#pragma once
#include "GameObject.h"
class Info;
class Button : public GameObject
{
protected:
	sf::Texture * _mainTexture;
	sf::Texture * _overTexture;
	sf::Texture * _clickedTexture;
	sf::Font _font;
private:
	bool _isOver;
	bool _isClicked;
	bool _isRelased;
	virtual void doAction() = 0;
public:
	sf::Text * _info = NULL;
	bool _shown = false;
	Button(int mainTexture, int overTexture, int clickedTexture, sf::Vector2f &position, View * parent, Game * game);
	~Button();
	void Update();
	void eventHandler(sf::Vector2i &mousePosition, bool isPressed);
	void addInfo(std::string text);
};