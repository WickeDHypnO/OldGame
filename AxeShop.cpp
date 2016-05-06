#include "AxeShop.h"

AxeShop::AxeShop(View * parent, Game * game) : ShopButton(90, 91, 92, info, sf::Vector2f(46, 35), parent, game)
{
	info = "atak: 30\n szybkosc: 50\n przebicie: 40\n cena:600";
}


AxeShop::~AxeShop()
{
}