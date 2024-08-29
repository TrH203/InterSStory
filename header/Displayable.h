#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H

#include "Entity.h"

class Displayable :
	public Entity
{
public:
	Displayable();
	~Displayable();

	void update();
	void updateObject();
	void draw(RenderWindow& win);
	void draw(RenderWindow& win, RectangleShape hp, RectangleShape OriginHp);
protected:
	RectangleShape rect;
	Texture* tex;
	Sprite sprite;

};

#endif