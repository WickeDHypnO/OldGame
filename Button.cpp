#include "Button.h"
#include "View.h"
#include "Game.h"
#include "Player.h"
#include "Battle.h"

Button::Button(int mainTexture, int overTexture, int clickedTexture, sf::Vector2f &position, View *parent, Game * game) : GameObject(parent, game)
{
	_mainTexture = _game->findTexture(mainTexture);
	_overTexture = _game->findTexture(overTexture);
	_clickedTexture = _game->findTexture(clickedTexture);
	this->setTexture(_mainTexture);
	this->setSize(sf::Vector2f(_mainTexture->getSize()));
	this->setPosition(position);
	_isClicked = _isRelased = _isOver = false;
}

void Button::Update()
{
	if (_isOver)
	{
		this->setTexture(_overTexture);
		if (_isClicked)
		{
			this->setTexture(_clickedTexture);
		}
	}
	else
		this->setTexture(_mainTexture);
	if (_isRelased)
	{
		this->doAction();
		_isOver = false;
	}
	_isRelased = false;
}

Button::~Button()
{
	delete _info;
}

void Button::eventHandler(sf::Vector2i &mousePosition, bool isPressed)
{
	if (this->getGlobalBounds().contains(sf::Vector2f(mousePosition)))
	{
		_isOver = true;
		if (_info && dynamic_cast<Battle*>(_parent))
		{
			if (!_shown)
			{
				_shown = true;
			}
			if (_shown)
			{
				_info->setPosition(sf::Vector2f(mousePosition));
			}
		}
		if (isPressed)
		{
			_isClicked = true;
		}
		else
		{
			if (_isClicked)
				_isRelased = true;
			_isClicked = false;
		}
	}
	else
	{
		_isOver = _isClicked = _isRelased = _shown = false;
	}	
}

void Button::addInfo(std::string text)
{
	_font.loadFromFile("arial.ttf");
	_info = new sf::Text(text, _font);
	_info->setColor(sf::Color::Black);
}