#include "Mover.h"
Mover::Mover()
{
	Animation();
	maxSpeed = 0;
	maxForce = 0;
	acceleration = ut::ZERO_VECTORf;
	velocity = ut::ZERO_VECTORf;
	aVelocity = 1.5;
	speedModifier = 1;
}

Mover::Mover(float _maxSpeed)
{
	Mover();
	maxSpeed = _maxSpeed;
}

Mover::~Mover()
{
}

void Mover::init(Vector2f _position, Animator _animator)
{
	Animation::init(_position, _animator);
}


void Mover::update(Time& elapsed)
{
	Animation::update(elapsed);
	/*if (acceleration == ut::ZERO_VECTORf)
	{
		Animation::update(0);
	}
	else
	{
		Animation::update(elapsed);
	}*/
	// Animation::update(elapsed);

	velocity += acceleration;
	ut::limit(velocity, maxSpeed);
	velocity += velocity * -0.1f;
	velocity *= speedModifier;
	move(velocity * (float)elapsed.asMilliseconds());
	acceleration *= 0.f;
	speedModifier = 1;
}

void Mover::addForce(Vector2f force)
{
	//cout << "Force: " << force.x << " " << force.y << endl;
	acceleration += force;
	//cout << "Acceleration: " << acceleration.x << " " << acceleration.y << endl;
}

void Mover::addForce(float x, float y)
{
	addForce(Vector2f(x, y));
}

void Mover::setForce(Vector2f force) {
	acceleration = force;
}


void Mover::look(Vector2f target, Time elapsed)
{
	float heading = 180 - atan2(target.x - getPos().x, target.y - getPos().y) * ut::TO_DEGREE;
	look(heading, elapsed);
}

void Mover::look(float angle, Time elapsed)
{
	while (angle < 0)
	{
		angle += 360;
	}

	if (abs(angle - getAngle()) > aVelocity * elapsed.asMilliseconds())
	{
		setAngle(getAngle() + aVelocity * (sin((angle - getAngle()) * ut::TO_RADIAN) >= 0 ? 1 : -1) * elapsed.asMilliseconds());
	}
	else
	{
		setAngle(angle);
	}
}

void Mover::moveFwd()
{
	addForce(ut::toVector(maxSpeed, getAngle() - 90));
}

void Mover::moveBwd() {
	addForce(ut::toVector(maxSpeed*3.f, getAngle() + 45));
}

void Mover::jetForce() {
	addForce(ut::toVector(maxSpeed*0.1f, getAngle() + 90));
}

void Mover::speedMod(float amount)
{
	speedModifier = amount;
}