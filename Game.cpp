#include "Game.h"
#include "Menu.h"
#include "Battle.h"
#include "Town.h"
#include "View.h"
#include <fstream>
#include "Player.h"
#include "Shop.h"
#include "Animation.h"

Game::Game() : mWindow(sf::VideoMode(1024, 768), "Another Story Fate", sf::Style::Fullscreen)
{

}

void Game::run()
{
	mWindow.setFramerateLimit(60);
	loadTextures();
	_player = new Player(44, this);
	new Menu(5, this);
	this->actualView = _views[0];

	while (mWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::changeView(int i)
{
	this->actualView = _views[i];
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyReleased:
			if (event.key.code == sf::Keyboard::Escape)
			{
				if (dynamic_cast<Town*>(actualView))
				{
					actualView = _views[findView(menu)];
					changePlayerOwner();
					delete _views[findView(town)];
					_views.pop_back();
					_player->saveGame();
				}
				else if (dynamic_cast<Shop*>(actualView))
				{
					actualView = _views[findView(town)];
					changePlayerOwner();
					delete _views[findView(shop)];
					_views.pop_back();
				}
			}
			break;
		case sf::Event::Closed:
			_player->setParentView(_views[findView(menu)]);
			mWindow.close();
			break;
		case sf::Event::MouseMoved:
		case sf::Event::MouseButtonPressed:
		case sf::Event::MouseButtonReleased:
			this->actualView->eventHandler(sf::Mouse::getPosition(mWindow), sf::Mouse::isButtonPressed(sf::Mouse::Button::Left));
			break;
		}
	}
}

void Game::update()
{
	this->actualView->Update();
}

void Game::render()
{
	mWindow.clear();
	actualView->draw(mWindow);
	mWindow.display();
}

Game::~Game()
{
	for (int i = 0; i < _views.size(); i++)
		delete _views[i];
	for (int i = 0; i < _textures.size(); i++)
		delete _textures[i];
	delete _player;
}

void Game::AddView(View * view)
{
	_views.push_back(view);
}

int Game::findView(VIEWS view)
{
	int temp;
	for (int i = 0; i < _views.size(); i++)
	{
		switch (view)
		{
		case menu:
			if (dynamic_cast<Menu*>(_views[i]))
				temp = i;
			break;
		case battle:
			if (dynamic_cast<Battle*>(_views[i]))
				temp = i;
			break;
		case town:
			if (dynamic_cast<Town*>(_views[i]))
				temp = i;
			break;
		case shop:
			if (dynamic_cast<Shop*>(_views[i]))
				temp = i;
			break;
		}
	}
	return temp;
}

void Game::addTexture(std::string & path, int index)
{
	sf::Texture * temp = new sf::Texture();
	temp->loadFromFile(path);
	_textures[index] = temp;
}

sf::Texture * Game::findTexture(int index)
{
	return _textures[index];
}

void Game::loadTextures()
{
	std::ifstream file;
	file.open("Textures/textures.txt");
	if (file.good())
	{
		int index;
		std::string path;
		while (!file.eof())
		{
			file >> index;
			file >> path;
			path = "Textures/" + path;
			addTexture(path, index);
		}
		file.close();
	}
	else
		exit(0);
}

void Game::changePlayerOwner()
{
	_player->setParentView(actualView);
}

void Game::newGame()
{
	_player->newGame();
}

void Game::wonGame()
{
	new Animation(140, actualView, this, 1, sf::seconds(2), sf::Vector2f(279, 151), NULL, false);
	_player->addGold(100);
	_player->increaseLevel(1);
}

void Game::lostGame()
{
	new Animation(139, actualView, this, 1, sf::seconds(2), sf::Vector2f(279, 151), NULL, false);
	_player->addGold(-100);
	_player->increaseLevel(-1);
}

void Game::endGame(Animation * anim)
{
	delete anim;
	//update();
	actualView = _views[findView(town)];
	changePlayerOwner();
	delete _views[findView(battle)];
	_views.pop_back();
	
}

Player * Game::getPlayer()
{
	return _player;
}