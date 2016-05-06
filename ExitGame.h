#pragma once
#include "Button.h"
class ExitGame :
	public Button
{
public:
	ExitGame(View * parent, Game * game);
	~ExitGame();
private:
	void doAction();
};