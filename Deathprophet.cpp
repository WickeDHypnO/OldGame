#include "Deathprophet.h"
#include "Skill.h"
#include "ManaBar.h"
#include "HpBar.h"

Deathprophet::Deathprophet(int texture, View *parent, Game * game, sf::Vector2f position, Character * player) : Enemy(texture, parent, game, position, player)
{
	_level = _opponent->getLevel();
	this->_mana = new ManaBar(200 + (_level * 50), this, this->getPosition() - sf::Vector2f(-10, 10), 10, 200, _parent, _game);
	this->_hp = new HpBar(200 + (_level * 75), this, this->getPosition() - sf::Vector2f(-10, 25), 10, 200, _parent, _game);
	_Skills.push_back(new Skill(this, _opponent, _parent, _game, fireball));
	_Skills.push_back(new Skill(this, _opponent, _parent, _game, lightningbolt));
	_Skills.push_back(new Skill(this, _opponent, _parent, _game, heal));
	_Skills.push_back(new Skill(this, _opponent, _parent, _game, iceshard));
}

Deathprophet::~Deathprophet()
{
}

void Deathprophet::Play()
{
	_currentTime2 += clock2.getElapsedTime();
	clock2.restart();
	int turn;
	turn = rand() % 1000;
	if (_currentTime2 >= _frameTime2 && getPosition() == sf::Vector2f(700, 50))
	{
		_currentTime2 = sf::microseconds(_currentTime2.asMicroseconds() % _frameTime2.asMicroseconds());
		if (howMuchHp() < 0.3 && _opponent->howMuchHp() > 0.1)
			_Skills[2]->doAction();
		else if (turn < 900)
		{
			if (turn < 300)
				_Skills[0]->doAction();
			else if (turn < 600)
				_Skills[1]->doAction();
			else
				_Skills[3]->doAction();
		}
		else
		{
			if (_attack == none)
				_attack = start;
		}
	}
}

void Deathprophet::Update()
{
	_mana->Update();
	_hp->Update();
	_currentTime += clock.getElapsedTime();
	clock.restart();
	if (_currentTime >= _frameTime)
	{
		_currentTime = sf::microseconds(_currentTime.asMicroseconds() % _frameTime.asMicroseconds());
		if (_currentFrame < 20)
		{
			_currentFrame++;
			if (_attack == none)
			{
				if (up)
					move(sf::Vector2f(0, -1));
				else
					move(sf::Vector2f(0, 1));
			}
			else
			{
				if (_attack == start)
				{
					_currentFrame = 0;
					_attack = progress;
					setPosition(sf::Vector2f(700, 50));
				}
				if (_attack == progress)
					move(sf::Vector2f(-15, 0));
				else if (_attack == end)
					move(sf::Vector2f(15, 0));
			}
		}
		else
		{
			_currentFrame = 0;
			up = !up;
			if (_attack == progress)
			{
				_opponent->getDamage(attack);
				_attack = end;
			}
			else if (_attack == end)
			{
				_attack = none;
				if (_opponent->howMuchHp() > 0)
					giveTurn();
				else
					doTurn();
				_currentFrame = 0;
				setPosition(sf::Vector2f(700, 50));
			}
		}
	}
	if (isTurn())
		Play();
	else
		clock2.restart();
}