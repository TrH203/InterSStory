#include "Weapon.h"



Weapon::Weapon()
{
	Mover();
}

Weapon::Weapon(int _type) {
	type = _type;
	switch (type)
	{
	case 0:
		dmg = 10;
		break;
	case 1:
		dmg = 20;
		break;
	case 2:
		dmg = 10;
		break;
	default:
		break;
	}
	Mover();
}


Weapon::~Weapon()
{
	dmg = 5;
}

void Weapon::update(Time& elapsed) {
	Mover::updateObject();
	coolDown.add(elapsed.asMilliseconds());
}
