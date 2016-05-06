#pragma once
#include "GameObject.h"
class Avatar;
class ManaBar;
class HpBar;
class SkillButtoned;
class View;
class Player;
class Stats :
	public GameObject
{
	Player * _player;
	Avatar * _avatar;
	HpBar * _hp;
	ManaBar * _mana;
	std::vector<SkillButtoned *> _Skills;
public:
	Stats(Player * player);
	~Stats();
	void Update();
	void setParentView(View * parent);
};