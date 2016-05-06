#pragma once
#include "Character.h"
#include "Animation.h"
class Skill;
class Enemy :
	public Character
{
protected:
	std::vector<Skill *> _Skills;
	sf::Time _currentTime2 = sf::Time::Zero;
	sf::Clock clock2;
	sf::Time _frameTime2 = sf::seconds(1.3);
public:
	Enemy(int texture, View *parent, Game * game, sf::Vector2f position, Character * player);
	virtual void Play() = 0;
	void setOpponent(Character * opponent);
	~Enemy();
};