#include "View.h"
#include "Game.h"
#include "Button.h"
#include "StatusBar.h"
#include "Menu.h"
#include "Player.h"

View::View(int texture, Game * parent) : sf::RectangleShape()
{
	_parent = parent;
	_parent->AddView(this);
	_background = this->_parent->findTexture(texture);
	this->setTexture(_background);
	this->setSize(sf::Vector2f(_background->getSize()));
}

View::~View()
{
	for (GameObject * var : _objects)
		delete var;
}

void View::draw(sf::RenderWindow &window)
{
	window.draw(*this);
	for (sf::Drawable * var : _objects)
	{
		window.draw(*var);
		if (dynamic_cast<Button*>(var))
			if (dynamic_cast<Button*>(var)->_shown)
				window.draw(*(dynamic_cast<Button*>(var)->_info));
		if (dynamic_cast<StatusBar*>(var))
			window.draw(*(dynamic_cast<StatusBar*>(var)->_points));
	}
	if (!(dynamic_cast<Menu*>(this)))
	{
		window.draw(*(_parent->getPlayer()->_goldText));
		window.draw(*(_parent->getPlayer()->_levelText));
	}
}

void View::Update()
{
	for (int i = 0; i < _objects.size(); i++)
		_objects[i]->Update();
}

void View::eventHandler(sf::Vector2i &mousePosition, bool isPressed)
{
	for (int i = 0; i < _objects.size(); i++)
	{
		if (dynamic_cast<Button*>(_objects[i]))
			dynamic_cast<Button*>(_objects[i])->eventHandler(mousePosition, isPressed);
	}
}

void View::addObject(GameObject *obj)
{
	_objects.push_back(obj);
}

void View::removeLastObject()
{
	_objects.pop_back();
}

void View::deleteLastObject()
{
	delete _objects._Mylast;
}