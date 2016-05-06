#pragma once
#include "GameObject.h"
class Character;
class StatusBar : public GameObject
{
protected:
	sf::Font _font;
	int _maxLevel;
	int _actualLevel;
	sf::Texture * _texture;
	Character * _owner;
	int _height, _length;
public:
	sf::Text * _points;
	void changeLevel(int value);
	StatusBar(int maxLevel, int texture, Character * owner, int height, int length, View *parent, Game * game);
	void Update();
	void setView(View *parent);
	virtual void newGame() = 0;
	void setMaxLevel();
	void setMaxLevel(int amount);
	int getActualLevel();
	int getMaxLevel();
	~StatusBar();
};

