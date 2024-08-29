#ifndef Hp_H
#define Hp_H
#include "Displayable.h"
class Hp
{
	public:
		Hp();
		~Hp();
	
		void init(Vector2f pos, Vector2f size, int color);
		void update(Vector2f pos, Vector2f size);
		RectangleShape get() {return c;};
		int getColor() {return mycolor;};
		void setColor(int color) {mycolor = color;};
	private:
		RectangleShape c;
		int mycolor;
};

#endif