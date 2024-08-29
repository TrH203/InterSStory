#include "Obstacle.h"

using namespace ut;

Obstacle::Obstacle()
{
}

Obstacle::Obstacle(Vector2f _pos, Animator _animator)
{
	setPos(_pos);
	animator = _animator;
	setSize(animator.getSize() * 0.7f);
	rect.setSize(Vector2f(getSize().x, getSize().x));
	tex = animator.getTexture();
	sprite.setTexture(*tex);
	Displayable::update();
	sprite.setTextureRect(animator.get(0));
}

bool Obstacle::isCollided(Character c, float sizex, float sizey, bool center)
{
	if (center) {
		return (c.getPos().x + c.getSize().x / 2.f >= getPos().x - sizex / 2.f)
			&& (c.getPos().x - c.getSize().x / 2.f <= getPos().x + sizex / 2.f)
			&& (c.getPos().y + c.getSize().y / 2.f >= getPos().y - sizey / 2.f)
			&& (c.getPos().y - c.getSize().y / 2.f <= getPos().y + sizey / 2.f);
	}
	return (c.getPos().x + c.getSize().x / 2.f >= getPos().x - sizex / 2.f)
		&& (c.getPos().x - c.getSize().x / 2.f <= getPos().x + sizex / 2.f)
		&& (c.getPos().y + c.getSize().y / 2.f >= getPos().y + getSize().y / 2.f - sizey)
		&& (c.getPos().y - c.getSize().y / 2.f <= getPos().y + getSize().y / 2.f);
}

bool Obstacle::isAttacked(Projectile c)
{
	return (c.getPos().x + c.getSize().x / 2.f >= getPos().x - getSize().x / 2.f)
		&& (c.getPos().x - c.getSize().x / 2.f <= getPos().x + getSize().x / 2.f)
		&& (c.getPos().y + c.getSize().y / 2.f >= getPos().y - getSize().y / 2.f)
		&& (c.getPos().y - c.getSize().y / 2.f <= getPos().y + getSize().y / 2.f);
}

Obstacle::~Obstacle() {
	tex = NULL;
	delete tex;
}