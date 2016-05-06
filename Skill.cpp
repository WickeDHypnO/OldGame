#include "Skill.h"
#include "View.h"
#include "Player.h"
#include "Enemy.h"

Skill::Skill(Character * owner, Character * target, View * parent, Game * game, SKILLS type)
{
	_type = type;
	_owner = owner;
	_parent = parent;
	_target = target;
	_game = game;
	switch (_type)
	{
	case attack:
		_anim = NULL;
		break;
	case fireball:
		if (dynamic_cast<Enemy*>(_owner))
		{
			_anim = new Animation(110, NULL, _game, 7, sf::seconds(0.25), sf::Vector2f(859, 24), this, false);
			_anim->scale(-1, 1);
		}
		else
			_anim = new Animation(110, NULL, _game, 7, sf::seconds(0.25), sf::Vector2f(165, 24), this, false);
		break;
	case heal:
		if (dynamic_cast<Enemy*>(_owner))
		{
			_anim = new Animation(127, NULL, _game, 5, sf::seconds(0.25), sf::Vector2f(700, 50), this, false);
		}
		else
			_anim = new Animation(127, NULL, _game, 5, sf::seconds(0.25), sf::Vector2f(20, 60), this, false);
		break;
	case lightningbolt:
		_anim = new Animation(120, NULL, _game, 7, sf::seconds(0.25), sf::Vector2f(262, 140), this, false);
		break;
	case iceshard:
		if (dynamic_cast<Enemy*>(_owner))
		{
			_anim = new Animation(132, NULL, _game, 7, sf::seconds(0.25), sf::Vector2f(934, 30), this, false);
			_anim->scale(-1, 1);
		}
		else
			_anim = new Animation(132, NULL, _game, 7, sf::seconds(0.25), sf::Vector2f(77, 56), this, false);
		break;
	default:
		break;
	}
}

Skill::~Skill()
{
	delete _anim;
}

void Skill::setTarget(Character * target)
{
	_target = target;
}

void Skill::setView(View *parent)
{
	_parent = parent;
}

void Skill::unlockAnimation()
{
	_owner->takeTurn();
	_parent->removeLastObject();
}

void Skill::doAction()
{
	if (_target && _owner->isTurn() && _owner->attackStatus() == none)
	{
		if (_type == attack)
			_owner->startAttack();
		else if (_type == defend)
		{
			_owner->wait();
			_owner->giveTurn();
		}
		else
		{
			if (_owner->useSpell(_type))
			{
				_parent->addObject(_anim);
				_owner->doTurn();
			}
			else if (dynamic_cast<Enemy*>(_owner))
				_owner->startAttack();
		}
	}
}

SKILLS Skill::getType()
{
	return _type;
}