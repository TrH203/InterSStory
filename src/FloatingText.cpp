#include "FloatingText.h"

FloatingText::FloatingText()
{
	setString("Default");
	setDuration(1000);
	speed = 1;
	setOrigin(Vector2f( text.getLocalBounds().width / 2, text.getLocalBounds().height / 2 ));
}
FloatingText::FloatingText(string s, float duration, float velocity)
{
	setString(s);
	setDuration(duration);
	speed = velocity;
	setOrigin(Vector2f( text.getLocalBounds().width / 2, text.getLocalBounds().height / 2 ));
}

void FloatingText::init(string s, float duration, float velocity)
{
	setString(s);
	setDuration(duration);
	speed = velocity;
	setOrigin(Vector2f( text.getLocalBounds().width / 2, text.getLocalBounds().height / 2 ));
}

void FloatingText::init(string s, Vector2f position)
{
	setString(s);
	setOrigin(Vector2f( text.getLocalBounds().width / 2, text.getLocalBounds().height / 2 ));
	setPosition(position);
}
void FloatingText::init(string s, Vector2f position, int size)
{
	setString(s);
	setSize(size);
	setOrigin(Vector2f( text.getLocalBounds().width / 2, text.getLocalBounds().height / 2 ));
	setPosition(position);
}
void FloatingText::update(Time& elapsed)
{
	move(0, -speed * elapsed.asMilliseconds());
	counter.add(elapsed.asMilliseconds());
	text.setFillColor(sf::Color( text.getFillColor().r, text.getFillColor().g, text.getFillColor().b, (Uint8)(255 * (100 - (counter.getPerc())) / 100) ));
}

void FloatingText::draw(RenderTarget& target, RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(text, states);
	//target.draw(text, getTransform());
}