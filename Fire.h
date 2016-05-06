#pragma once
#include "Animation.h"
#include "View.h"
#include "Game.h"
#include "Player.h"
class Fire :
	public Animation
{
public:
	Fire(View *parent, Game * game);
	~Fire();
};

