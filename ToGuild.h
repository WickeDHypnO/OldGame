#pragma once
#include "Button.h"
class ToGuild :
	public Button
{
public:
	ToGuild(View *parent, Game * game);
	~ToGuild();
private:
	void doAction();
};

