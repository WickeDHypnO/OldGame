#pragma once
#include "Button.h"
class LoadGame :
	public Button
{
public:
	LoadGame(View *parent, Game * game);
	~LoadGame();
private:
	void doAction();
};