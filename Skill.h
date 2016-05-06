#pragma once
#include "Header.h"
class Character;
class View;
class Animation;
class Game;
class Skill
{
protected:
	SKILLS _type;
	View * _parent;
	Animation * _anim;
	Game * _game;
public:
	Character * _owner;
	Character * _target;
	Skill(Character * owner, Character * target, View *parent, Game * game, SKILLS type);
	~Skill();
	void setTarget(Character * target);
	void setView(View *parent);
	void unlockAnimation();
	void doAction();
	SKILLS getType();
};