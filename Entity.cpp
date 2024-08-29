#include "Entity.h"

Entity::Entity()
{
	pos = Vector2f( 0, 0 );
	angle = 0;
	size = Vector2f( 0,0 );
}


Entity::~Entity()
{
}

bool Entity::intersects(Entity* e)
{
	float di = ut::dist(e->getPos(), getPos()), //distanza
		si = (ut::mag(e->getSize()) / 2.f + ut::mag(getSize() / 2.f)) / 1.8; //lunghezza della somma delle size
	return di < si;
}