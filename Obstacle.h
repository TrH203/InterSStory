#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "SFML\Graphics.hpp"
#include "Displayable.h"
#include "Character.h"
#include "Projectile.h"
#include "Animator.h"

using namespace sf;

class Obstacle:
	public Animation
{
public:
	Obstacle();
	Obstacle(Vector2f _pos, Animator _animator);
	~Obstacle();
	bool isCollided(Character c, float sizex, float sizey, bool center);
	bool isAttacked(Projectile p);
	Animator animator;

private:
};
#endif