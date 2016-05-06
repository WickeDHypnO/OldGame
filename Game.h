#pragma once
#include <map>
#include "View.h"
class Player;
class Animation;
class Game
{
public:
	Game();
	~Game();
	void run();
	void changeView(int i);
	void AddView(View * view);
	friend class ExitGame;
	friend class ToTavern;
	int findView(VIEWS view);
	sf::Texture * findTexture(int index);
	void changePlayerOwner();
	void newGame();
	sf::RenderWindow mWindow;
	void wonGame();
	void endGame(Animation * anim);
	void lostGame();
	Player * getPlayer();
private:
	void processEvents();
	void update();
	void render();
	void addTexture(std::string &path, int index);
	void loadTextures();
private:
	View *actualView = NULL;
	std::vector<View *> _views;
	Player * _player;
	std::map<int, sf::Texture *> _textures;
};