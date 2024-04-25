#include "Rectangle.h"

Rectangle::Rectangle(const sf::Vector2f& position, const sf::Vector2f& size)
	:GameObject(
		*new sf::RectangleShape(size),
		sf::Color::White,
		position
	) 
{
}

void Rectangle::update(){
	
}

void Rectangle::onCollision(){}