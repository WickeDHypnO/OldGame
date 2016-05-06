#pragma once
#include "Button.h"
class ExitShop :
	public Button
{
public:
	ExitShop(View * parent, Game * game);
	~ExitShop();
private:
	void doAction();
};