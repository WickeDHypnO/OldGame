#ifndef _HEADER_HPP_
#define _HEADER_HPP_
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>

enum SKILLS
{
	attack,
	defend,
	fireball,
	heal,
	lightningbolt,
	iceshard
};

enum VIEWS
{
	menu,
	battle,
	town,
	shop
};

enum states4
{
	start,
	progress,
	end,
	none
};
#endif