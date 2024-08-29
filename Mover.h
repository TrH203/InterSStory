#ifndef MOVER_H
#define MOVER_H

#include "Animation.h"

static const float SEEK_MOVER = 0.3;

class Mover :
	public Animation
{
public:
	Mover();
	Mover(float _maxSpeed);

	~Mover();

	void init(Vector2f _position, Animator _animator);

	void update(Time& elapsed);
	void setForce(Vector2f force);
	void addForce(Vector2f force);
	void addForce(float x, float y);
	void look(Vector2f target, Time elapsed = milliseconds(1));
	void look(float angle, Time elapsed = milliseconds(1));
	void moveFwd();
	void moveBwd();
	void jetForce();
	void speedMod(float amount);

	const inline Vector2f getVelocity() { return velocity; }
	const inline Vector2f getAcceleration() { return acceleration; }
	const inline float getMaxSpeed() { return maxSpeed; }
	inline void setMaxSpeed(float _maxSpeed) { maxSpeed = _maxSpeed; }
	const inline float getAngularVelocity() { return aVelocity; }
	inline void setAngularVelocity(float angularVelocity) { aVelocity = angularVelocity; }
	const inline float getSpeedModifier() { return speedModifier; }
	inline void setSpeedModifier(float speedMod) { speedModifier = speedMod; }

private:
	Vector2f velocity;
	Vector2f acceleration;
	float maxSpeed;
	float maxForce;
	float aVelocity;
	float speedModifier;
};

#endif