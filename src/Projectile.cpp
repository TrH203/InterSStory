#include "Projectile.h"

Projectile::Projectile()
{
	Displayable();
	velocity = 0;
}

Projectile::~Projectile()
{
	tex = NULL;
	delete tex;
}

void Projectile::init(Vector2f _position, float _dir, float _velocity, int _life, Texture* _tex, int type)
{
	life.init(_life);
	setSize(Vector2f( BULLET_SIZE, BULLET_SIZE ));
	rect.setSize(getSize());
	setPos(_position);
	velocity = _velocity;
	dir = _dir;
	tex = _tex;
	sprite.setTexture(*tex);
	Ptype = type;
}
void Projectile::init(Vector2f _position, Vector2f _size,float _dir, float _velocity, int _life, Texture* _tex)
{
	_position += ut::toVector(1, _dir) * (350 * 0.1f);
	life.init(_life);
	setSize(_size);
	rect.setSize(_size);
	setPos(_position);
	velocity = _velocity;
	dir = _dir;
	tex = _tex;
	sprite.setTexture(*tex);
}

void Projectile::init(Vector2f _position, float _dir, float _velocity, int _life)
{
	life.init(_life);
	//setPos(_position + ut::toVector(10, _dir + 30));
	setPos(_position);
	velocity = _velocity;
	dir = _dir;
}

void Projectile::update(Time& elapsed)
{

	move(ut::toVector(velocity, dir) * (elapsed.asMilliseconds() * 1.f));
	setAngle(dir + 90);
	Displayable::updateObject();
	life.add(-elapsed.asMilliseconds());
}

void Projectile::destroy()
{
	life.setEmpty();
}

bool Projectile::isDestroyed()
{
	return life.isEmpty();
}