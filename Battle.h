#pragma once
#include "View.h"
class Battle :
	public View
{
public:
	Battle(int texture, Game * game);
	~Battle();
};