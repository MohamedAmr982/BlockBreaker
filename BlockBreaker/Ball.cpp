#include "Ball.h"
#include <iostream>

//if shape& is assigned to stack allocated circle
//the circle will go out of scope leaving
// a dangling reference

//if the class definition is changed,
//shape instead of shape&
//then assigning the circle (derived) to shape (base)
//causes object slicing, the extra attributes in 
//circle are lost

Ball::Ball()
	: GameObject(
		* new sf::CircleShape(0.f),
		sf::Color::Red,
		sf::Vector2f(0, 0)
	),
	velocity(*new sf::Vector2f(0, 0))
{
	setSize(10.f);
}

void Ball::setSize(float radius) {
	dynamic_cast<sf::CircleShape&>(shape).setRadius(radius);
}

void Ball::setVelocity(const sf::Vector2f& velocity) {
	this->velocity = velocity;
} 

const sf::Vector2f& Ball::getVelocity() {
	return velocity;
}

void Ball::update() {
	shape.setPosition(shape.getPosition() + velocity);
}

void Ball::onCollision() {

}

Ball::~Ball() {
	/*delete& shape;
	delete& velocity;*/
}
