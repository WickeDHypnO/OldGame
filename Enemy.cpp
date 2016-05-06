#include "Enemy.h"
#include "View.h"
#include "Game.h"
#include "ManaBar.h"
#include "HpBar.h"
#include "Skill.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>

Enemy::Enemy(int texture, View *parent, Game * game, sf::Vector2f position, Character * player) : Character(texture, parent, game, position)
{
	_opponent = player;
}

Enemy::~Enemy()
{
	for (Skill * var : _Skills)
		delete var;
}

void Enemy::setOpponent(Character * opponent)
{
	Character::setOpponent(opponent);
	for (Skill * var : _Skills)
		var->setTarget(opponent);
}