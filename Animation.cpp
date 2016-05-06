#include "Animation.h"
#include "View.h"
#include "Game.h"
#include "Skill.h"
#include "Player.h"

Animation::Animation(int tex, View *parent, Game * game, int frames, sf::Time frameTime, sf::Vector2f & position, Skill * manager, bool repeatable) : GameObject(parent, game)
{
	_manager = manager;
	_repeatable = repeatable;
	setPosition(position);
	numberOfFrames = frames;
	_frameTime = frameTime;
	anim.push_back(_game->findTexture(tex));
	for (int i = 1; i < frames; i++)
	{
		anim.push_back(_game->findTexture(tex + i));
	}
	setSize(sf::Vector2f(anim[0]->getSize()));
	setTexture(anim[0]);
	clock.restart();
	elapsed = clock.getElapsedTime();
}

void Animation::Update()
{
	_currentTime += clock.getElapsedTime();
	clock.restart();
	if (_currentTime >= _frameTime)
	{
		_currentTime = sf::microseconds(_currentTime.asMicroseconds() % _frameTime.asMicroseconds());

		if (_currentFrame < numberOfFrames - 1)			
		{
			_currentFrame++;
			this->setTexture(anim[_currentFrame]);
		}
		else
		{
			_currentFrame = 0;
			this->setTexture(anim[0]);
			if (!_repeatable)
			{
				if (_manager)
				{
					_manager->unlockAnimation();
					if (_manager->getType() == heal)
						_manager->_owner->getDamage(heal);
					else
						_manager->_target->getDamage(_manager->getType());
					if (_manager->_target->howMuchHp() > 0)
						_manager->_owner->giveTurn();
					else
						_manager->_owner->doTurn();
				}
				else
				{
					_parent->removeLastObject();
					_game->endGame(this);
				}
			}
		}
	}
}

Animation::~Animation()
{
	
}
