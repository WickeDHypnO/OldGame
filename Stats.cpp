#include "Stats.h"
#include "Player.h"
#include "Battle.h"
#include "Town.h"
#include "Menu.h"
#include "Avatar.h"
#include "HpBar.h"
#include "ManaBar.h"
#include "Shop.h"
#include "SkillButtoned.h"

Stats::Stats(Player * player) : _player(player), GameObject(player->_parent, player->_game)
{
	_avatar = _player->_avatar;
	_hp = _player->_hp;
	_mana = _player->_mana;
	for (SkillButtoned * var : _player->_Skills)
	{
		_Skills.push_back(var);
	}
}


Stats::~Stats()
{

}

void Stats::Update()
{

}

void Stats::setParentView(View * parent)
{
	if (_parent && dynamic_cast<Battle*>(_parent))
	{
		int temp = _Skills.size();
		for (int i = 0; i < 4 + temp; i++)
			_parent->removeLastObject();
		_player->_opponent = NULL;
	}
	else if (dynamic_cast<Town*>(_parent) || dynamic_cast<Shop*>(_parent))
	{
		int temp = _Skills.size();
		for (int i = 0; i < 3 + temp; i++)
			_parent->removeLastObject();
	}
	_player->_parent = parent;
	_parent = _player->_parent;
	_hp->setView(_parent);
	_mana->setView(_parent);
	_avatar->setView(_parent);
	for (SkillButtoned * var : _Skills)
		var->setView(_parent);
	if (dynamic_cast<Battle*>(_parent))
	{
		_parent->addObject(_player);
		_player->takeTurn();
	}
	if (!dynamic_cast<Menu*>(_parent))
	{
		_parent->addObject(_hp);
		_parent->addObject(_mana);
		_parent->addObject(_avatar);
		for (SkillButtoned * var : _Skills)
			_parent->addObject(var);
	}
}