#pragma once
#include "Button.h"
class ToTavern :
	public Button
{
public:
	ToTavern(View *parent, Game * game);
	~ToTavern();
private:
	void doAction();
};

