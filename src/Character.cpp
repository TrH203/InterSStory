#include "Character.h"



Character::Character()
{
	//dmg = 5;
	Mover();
	//sprite.setScale(2,2);
	setDir(0);
	myHp.init(getPos(), getSize(),1);
	originHp.init(getPos(), Vector2f(getSize().x+2, 12),0);
}
Character::Character(Weapon _weapon)
{
	Mover();
	weapon = _weapon;
	//sprite.setScale(2, 2);
	setDir(0);
	myHp.init(getPos(), getSize(), 1);
	originHp.init(getPos(), Vector2f(getSize().x + 2, 12), 0);
}
//FIX
Character::Character(int _type)
{
	type = _type;
	if (_type == -1)
		//sprite.setScale(4,4);
	
	//dmg = 5;
	Mover();
	setDir(0);
	myHp.init(getPos(), Vector2f(getSize().x+2, getSize().y/10.f),1);
	originHp.init(getPos(), Vector2f(getSize().x+2, getSize().y/10.f),0);
}

Character::~Character()
{
	//dmg = 5;
}

void Character::update(Time& elapsed)
{

	if (getType() >= 4){
		damage(elapsed.asMilliseconds());
		Mover::update(elapsed);
	}
	else{
		Mover::update(elapsed);
		weapon.setPos(getPos());
		weapon.setAngle(getAngle());
		weapon.update(elapsed);
		originHp.update(Vector2f(getPos().x - getSize().x/2 ,getPos().y - getSize().y/2) ,Vector2f(getSize().x ,getSize().y/10.0f));
		myHp.update(Vector2f(getPos().x - getSize().x/2 ,getPos().y - getSize().y/2) ,Vector2f(getSize().x * getPerHp(),getSize().y/10.0f));
	}
	coolDown.add(elapsed.asMilliseconds());
}