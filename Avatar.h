#pragma once
#include "GameObject.h"
class Player;
class Avatar :
	public GameObject
{
	sf::Texture * _texture;
	Player * _player;
public:
	void Update();
	Avatar(View *parent, int texture, Player * player, Game * game);
	void setView(View * parent);
	~Avatar();
};