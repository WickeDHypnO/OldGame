#pragma once
#include "GameObject.h"
#include "View.h"
#include "Game.h"
class Skill;
class Animation :
	public GameObject
{
protected:
	Skill * _manager;
	bool _repeatable;
	std::vector <sf::Texture *> anim;
	int numberOfFrames, _currentFrame = 0, _steps;
	sf::Time _frameTime, _currentTime = sf::Time::Zero, elapsed;
	sf::Clock clock;
public:
	Animation(int tex, View *parent, Game * game, int frames, sf::Time frameTime, sf::Vector2f & position, Skill * manager = NULL, bool repeatable = true);
	void Update();
	~Animation();
};