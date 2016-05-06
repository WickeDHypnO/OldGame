#pragma once
#include "Button.h"
class ToDungeon :
	public Button
{
public:
	ToDungeon(View *parent, Game * game);
	~ToDungeon();
public:
	void doAction();
};

