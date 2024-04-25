#include "Paddle.h"

void Paddle::setSize(sf::Vector2f& newSize) {
	dynamic_cast<sf::RectangleShape&>(shape).setSize(newSize);
}

Paddle::Paddle(Ball& ball)
	: Rectangle(
		*new sf::Vector2f(260, 580 - 10),
		*new sf::Vector2f(80, 20)
	),
	ball(ball),
	ballLaunched(false)
{
}


void Paddle::update() {
	if (!ballLaunched && Input::mouseClicked()) {
		ballLaunched = true;
		sf::Vector2f v(4, -4);
		ball.setVelocity(v);
	}


	sf::Vector2f newPos(Input::getMousePosition().x, shape.getPosition().y);
	setPosition(newPos);

	if (!ballLaunched) {
		sf::Vector2f offset(30, - 22 );
		ball.setPosition(shape.getPosition() + offset);
	}

}

void Paddle::onCollision(){}

Paddle::~Paddle(){
	//sfml does it for you
	// this will cause double deletion
	//delete& shape;
}



