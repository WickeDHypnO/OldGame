#pragma once
#include "Button.h"
class NewGame :
	public Button
{
public:
	NewGame(View *parent, Game * game);
	~NewGame();
private:
	void doAction();
};

