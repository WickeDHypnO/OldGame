#include "StatusBar.h"
#include "Character.h"
#include "View.h"
#include "Game.h"
#include "Player.h"
#include <sstream>

StatusBar::StatusBar(int maxLevel, int texture, Character * owner, int height, int length, View *parent, Game * game) : GameObject(parent, game)
{
	this->_owner = owner;
	_texture = _game->findTexture(texture);
	_maxLevel = _actualLevel = maxLevel;
	_length = length;
	_height = height;
	this->setSize(sf::Vector2f(length * _actualLevel / _maxLevel , height));
	this->setTexture(_texture);
	this->_texture->setRepeated(true);
	_font.loadFromFile("arial.ttf");
	std::ostringstream ss;
	ss << _maxLevel;
	_points = new sf::Text(ss.str(), _font, _height);
	_points->setColor(sf::Color::Red);
}

StatusBar::~StatusBar()
{
	delete _points;
}

void StatusBar::Update()
{
	this->setSize(sf::Vector2f(_length * _actualLevel / _maxLevel, _height));
	std::ostringstream ss;
	ss << _actualLevel;
	_points->setString(ss.str());
}

void StatusBar::setView(View *parent)
{
	_parent = parent;
}

void StatusBar::setMaxLevel()
{
	_actualLevel = _maxLevel;
}

void StatusBar::setMaxLevel(int amount)
{
	_maxLevel = amount;
}

int StatusBar::getActualLevel()
{
	return _actualLevel;
}

int StatusBar::getMaxLevel()
{
	return _maxLevel;
}

