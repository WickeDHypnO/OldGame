#include "Player.h"
#include "View.h"
#include "Avatar.h"
#include "HpBar.h"
#include "ManaBar.h"
#include "Game.h"
#include "Stats.h"
#include "SkillButtoned.h"
#include <sstream>
#include <fstream>

Player::Player(int texture, Game * game) : Character(texture, NULL, game, sf::Vector2f(50,50))
{
	this->_mana = new ManaBar(230, this, sf::Vector2f(21, 719), 30, 569, _parent, _game);
	this->_hp = new HpBar(350, this, sf::Vector2f(21, 689), 30, 569, _parent, _game);
	this->_avatar = new Avatar(this->_parent, 46, this, _game);
	_Skills.push_back(new SkillButtoned(this, _opponent, 1, 2, 3, sf::Vector2f(455, 574), _parent, _game, attack));
	_Skills.push_back(new SkillButtoned(this, _opponent, 27, 28, 29, sf::Vector2f(522, 574), _parent, _game, defend));
	_Skills.push_back(new SkillButtoned(this, _opponent, 36, 37, 38, sf::Vector2f(144, 574), _parent, _game, fireball));
	_Skills.push_back(new SkillButtoned(this, _opponent, 117, 118, 119, sf::Vector2f(217, 574), _parent, _game, lightningbolt));
	_Skills.push_back(new SkillButtoned(this, _opponent, 40, 41, 42, sf::Vector2f(290, 574), _parent, _game, heal));
	_Skills.push_back(new SkillButtoned(this, _opponent, 105, 106, 107, sf::Vector2f(363, 574), _parent, _game, iceshard));
	this->_stats = new Stats(this);
	_font.loadFromFile("arial.ttf");
	std::ostringstream ss;
	std::ostringstream ss1;
	ss << _level;
	_levelText = new sf::Text(ss.str(), _font);
	ss1 << _gold;
	_goldText = new sf::Text(ss1.str(), _font);
	_levelText->setColor(sf::Color::Black);
	_goldText->setColor(sf::Color::Black);
	_levelText->setOrigin(sf::Vector2f(_levelText->getGlobalBounds().width / 2, _levelText->getGlobalBounds().height / 2));
	_goldText->setOrigin(sf::Vector2f(_goldText->getGlobalBounds().width / 2, _goldText->getGlobalBounds().height / 2));
	_levelText->setPosition(sf::Vector2f(800, 720));
	_goldText->setPosition(sf::Vector2f(800, 628));
}

Player::~Player()
{
	delete _goldText;
	delete _levelText;
	delete _mana;
	delete _hp;
	delete _avatar;
	for (SkillButtoned * var : _Skills)
		delete var;
	delete _stats;
}

void Player::Update()
{
	std::ostringstream ss;
	std::ostringstream ss1;
	ss << _level;
	_levelText->setString(ss.str());
	ss1 << _gold;
	_goldText->setString(ss1.str());
	_levelText->setOrigin(sf::Vector2f(_levelText->getGlobalBounds().width / 2, _levelText->getGlobalBounds().height / 2));
	_goldText->setOrigin(sf::Vector2f(_goldText->getGlobalBounds().width / 2, _goldText->getGlobalBounds().height / 2));
	_mana->Update();
	_hp->Update();
	_currentTime += clock.getElapsedTime();
	clock.restart();
	if (_currentTime >= _frameTime)
	{
		_currentTime = sf::microseconds(_currentTime.asMicroseconds() % _frameTime.asMicroseconds());
		if (_currentFrame < 20)
		{
			_currentFrame++;
			if (_attack != none)
			{
				if (_attack == start)
				{
					_currentFrame = 0;
					_attack = progress;
				}
				if (_attack == progress)
					move(sf::Vector2f(15, 0));
				else if (_attack == end)
					move(sf::Vector2f(-15, 0));
			}
		}
		else
		{
			_currentFrame = 0;
			if (_attack == progress)
			{
				_opponent->getDamage(attack);
				_attack = end;
			}
			else if (_attack == end)
			{
				_attack = none;
				if (_opponent->howMuchHp() > 0)
					giveTurn();
				else
					doTurn();
				setPosition(sf::Vector2f(50, 50));
			}
		}
	}
}

void Player::setParentView(View *parent)
{
	_stats->setParentView(parent);
}

void Player::newGame()
{
	_hp->newGame();
	_mana->newGame();
	_gold = 0;
	_level = 1;
	Update();
}

void Player::setMaxHealth()
{
	_hp->setMaxLevel();
}

void Player::setMaxMana()
{
	_mana->setMaxLevel();
}

void Player::setOpponent(Character * opponent)
{
	Character::setOpponent(opponent);
	for (SkillButtoned * var : _Skills)
		var->setTarget(opponent);
}

void Player::addGold(int amount)
{
	if (amount > 0)
		_gold += amount;
	else
	{
		if (_gold + amount < 0)
			_gold = 0;
		else
			_gold += amount;
	}
}

bool Player::loadGame()
{
	std::ifstream file;
	file.open("save.sav");
	if (file.good())
	{
		file >> _level;
		file >> _gold;
		file.close();
		uploadManaHp();
		Update();
		return true;
	}
	else
		return false;
}

void Player::saveGame()
{
	std::fstream file;
	file.open("save.sav", std::ios::out | std::ios::trunc);
	if (!file.good())
	{
		remove("save.sav");
		file.open("save.sav", std::ios::out | std::ios::trunc);
	}
	file << _level << std::endl << _gold;
	file.close();
}

void Player::uploadManaHp()
{
	_hp->setMaxLevel(250 + (100 * _level));
	_mana->setMaxLevel(150 + (80 * _level));
}