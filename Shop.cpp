#include "Shop.h"
#include "ExitShop.h"
#include "AxeShop.h"

Shop::Shop(int texture, Game * parent) : View(texture, parent)
{
	new ExitShop(this, _parent);
	new AxeShop(this, _parent);
}


Shop::~Shop()
{
}
