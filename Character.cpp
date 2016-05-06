#include "Character.h"
#include "HpBar.h"
#include "View.h"
#include "Game.h"
#include "Skill.h"
#include "ManaBar.h"
#include "Player.h"

Character::Character(int texture, View *parent, Game * game, sf::Vector2f & position) : Animation(texture, parent, game, 0, sf::seconds(0.075), position)
{

}

Character::~Character()
{
}

void Character::setOpponent(Character * opponent)
{
	_opponent = opponent;
}

void Character::getDamage(SKILLS type)
{
	int function;
	switch (type)
	{
	case attack:
		function = (rand() % 25) * _level - _shieldActive * 40;
		if (function < 0)
			function = 0;
		break;
	case fireball:
		function = rand() % 50 + (_level * 50);
		break;
	case heal:
		function = -100;
		break;
	case lightningbolt:
		function = rand() % 65 + (_level * rand() % 25) + (_level * 40);
		break;
	case iceshard:
		function = rand() % 80 + (_level * rand() % 40) + (_level * 25);
		break;
	default:
		break;
	}
	_hp->getDamage(function);
}

bool Character::isTurn()
{
	return _turn;
}

void Character::giveTurn()
{
	_turn = false;
	_opponent->takeTurn();
}

void Character::takeTurn()
{
	_turn = true;
	_shieldActive = false;
}

void Character::doTurn()
{
	_turn = false;
}

void Character::startAttack()
{
	_attack = start;
}

states4 Character::attackStatus()
{
	return _attack;
}

bool Character::useSpell(SKILLS type)
{
	int cost;
	switch (type)
	{
	case fireball:
		cost = 30;
		break;
	case heal:
		cost = 25;
		break;
	case lightningbolt:
		cost = 40;
		break;
	case iceshard:
		cost = 60;
		break;
	case defend:
		cost = 0;
		break;
	}
	if (_mana->useMana(cost))
		return true;
	else
		return false;
}

double Character::howMuchHp()
{
	return (double)(_hp->getActualLevel()) / _hp->getMaxLevel();
}

void Character::wait()
{
	_shieldActive = true;
}

int Character::getLevel()
{
	return _level;
}

void Character::increaseLevel(int amount)
{
	if (amount > 0)
		_level += amount;
	else
	{
		if (_level + amount < 1)
			_level = 1;
		else
			_level += amount;
	}
	if (dynamic_cast<Player*>(this))
		dynamic_cast<Player*>(this)->uploadManaHp();
}