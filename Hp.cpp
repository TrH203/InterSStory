#include "Hp.h"
Hp::Hp(){

}
Hp::~Hp(){

}

void Hp::init(Vector2f pos, Vector2f size, int _color){
	setColor(_color);
	c.setSize(size);
	c.setPosition(pos);
}

void Hp::update(Vector2f pos, Vector2f size){
	if (getColor() == 1)
		c.setFillColor(Color::Green);
	else
		c.setFillColor(Color::Red);
	//cout << getColor() << endl;
	c.setSize(size);
	c.setPosition(pos);
	
}





