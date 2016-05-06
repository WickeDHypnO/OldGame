#pragma once
#include "GameObject.h"
class Game;
class View : public sf::RectangleShape
{
public:
	View(int texture, Game * game);
	~View();
	void draw(sf::RenderWindow &window);
	void Update();
	void addObject(GameObject * obj);
	void eventHandler(sf::Vector2i &mousePosition, bool isPressed);
	Game * _parent;
	void removeLastObject();
	void deleteLastObject();
private:
	sf::Texture * _background;
protected:
	std::vector<GameObject *> _objects;
};