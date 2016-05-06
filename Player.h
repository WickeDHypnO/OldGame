#pragma once
#include "Character.h"
class Avatar;
class Game;
class Stats;
class SkillButtoned;
class Player :
	public Character
{
	Avatar * _avatar;
	Stats * _stats;
	int _gold = 0;
	sf::Font _font;
	std::vector<SkillButtoned *> _Skills;
public:
	sf::Text  * _goldText;
	sf::Text * _levelText;
	void addGold(int amount);
	friend class Stats;
	friend class ToTavern;
	Player(int texture, Game * game);
	void Update();
	~Player();
	void setParentView(View * parent);
	void newGame();
	void setMaxHealth();
	void setMaxMana();
	void setOpponent(Character * opponent);
	bool loadGame();
	void saveGame();
	void uploadManaHp();
};