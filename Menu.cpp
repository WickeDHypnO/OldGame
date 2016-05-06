#include "Menu.h"
#include "LoadGame.h"
#include "NewGame.h"
#include "ExitGame.h"

Menu::Menu(int texture, Game * parent) : View(texture, parent)
{
	new NewGame(this, _parent);
	new LoadGame(this, _parent);
	new ExitGame(this, _parent);
}


Menu::~Menu()
{
}
