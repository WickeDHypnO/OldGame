#pragma once
#include "ShopButton.h"
class AxeShop :
	public ShopButton
{
public:
	AxeShop(View * parent, Game * game);
	~AxeShop();
private:
	std::string info;
};