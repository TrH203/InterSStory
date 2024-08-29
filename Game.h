#ifndef GAME_H
#define GAME_H
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>
#include <ctime>
#include <SFML\Audio.hpp>
#include "Character.h"
#include "Projectile.h";
#include "TextureManager.h"
#include "Pointer.h"
#include "FloatingText.h"
#include "Weapon.h"
#include "Obstacle.h"

using namespace sf;
using namespace std;

class Game
{
public:
	Game();
	~Game();

	bool init();
	void run();
	void movePlayer(Time& elapsed, int x, int y, int w, int h);
	void movePlayerObstacle(Time& elapsed, int x, int y, int w, int h, vector<Obstacle> _obstacles);
	void reset(vector<Character> vz, Projectile p, vector<Projectile> vp, vector<Projectile> vef, vector<Animation> vHitEffect, vector<Animation> vDeadEffect, Character boss, Text life);
	inline void setResetPos(bool _reset) { resetPos = _reset; }
	inline void setScreen(int _scrn) {
		screen = _scrn;
	}
	inline int getScreen() { return screen; }
	float critRate, missRate, max_mons;
	int audioVolumn, soundVolumn, defaultTime, tryed, tryAgain, lastScreen, skin, skinBoss, lifes, lastSeason;
	bool godMode;
private:
	int screen;
	bool resetPos;
	RenderWindow window;
	View view;
	Character player;
	TextureManager texManager;
	Pointer cursor;
};

#endif