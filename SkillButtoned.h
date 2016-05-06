#pragma once
#include "Skill.h"
#include "Button.h"
class SkillButtoned :
	public Skill, public Button
{
public:
	SkillButtoned(Character * owner, Character * target, int mainTexture, int overTexture, int clickedTexture, sf::Vector2f &position, View * parent, Game * game, SKILLS type);
	~SkillButtoned();
	void doAction();
	void setView(View * parent);
};

