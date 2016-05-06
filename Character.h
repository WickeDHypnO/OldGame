#pragma once
#include "Animation.h"
class ManaBar;
class HpBar;
class View;
class Character :
	public Animation
{
protected:
	HpBar * _hp;
	ManaBar * _mana;
	sf::Texture * _texture;
	int _level = 1;
	bool _turn = false;
	states4 _attack = none;
	bool _shieldActive = false;
public:
	Character(int texture, View *parent, Game * game, sf::Vector2f & position);
	void setOpponent(Character * opponent);
	Character * _opponent;
	void doTurn();
	void getDamage(SKILLS type);
	bool isTurn();
	void giveTurn();
	void takeTurn();
	void startAttack();
	bool useSpell(SKILLS type);
	double howMuchHp();
	void increaseLevel(int amount);
	states4 attackStatus();
	void wait();
	int getLevel();
	~Character();
};

