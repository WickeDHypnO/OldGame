#include "SkillButtoned.h"
SkillButtoned::SkillButtoned(Character * owner, Character * target, int mainTexture, int overTexture, int clickedTexture, sf::Vector2f &position, View * parent, Game * game, SKILLS type)
	:Skill(owner, target, parent, game, type), Button(mainTexture, overTexture, clickedTexture, position, parent, game)
{
	switch (type)
	{
	case fireball:
		addInfo("Koszt: 30");
		break;
	case heal:
		addInfo("Koszt: 25");
		break;
	case lightningbolt:
		addInfo("Koszt: 40");
		break;
	case iceshard:
		addInfo("Koszt: 60");
		break;
	default:
		break;
	}
}


SkillButtoned::~SkillButtoned()
{
}

void SkillButtoned::doAction()
{
	Skill::doAction();
}

void SkillButtoned::setView(View * parent)
{
	GameObject::_parent = parent;
	Skill::setView(parent);
}