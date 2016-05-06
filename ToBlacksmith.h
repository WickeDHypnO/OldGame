#pragma once
#include "Button.h"
class ToBlacksmith :
	public Button
{
public:
	ToBlacksmith(View *parent, Game * game);
	~ToBlacksmith();
private:
	void doAction();
};

