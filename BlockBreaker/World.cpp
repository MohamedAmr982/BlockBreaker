#include "World.h"
#include "Rectangle.h"
#include <iostream>

World::World()
	:ball(*new Ball()),
	paddle(*new Paddle(ball)),
	walls(std::vector<Rectangle>())
{
	Rectangle top(sf::Vector2f(0, -100), sf::Vector2f(800, 100));
	Rectangle left(sf::Vector2f(-100, 0), sf::Vector2f(100, 600));
	Rectangle right(sf::Vector2f(800, 0), sf::Vector2f(100, 600));
	Rectangle center(sf::Vector2f(350, 275), sf::Vector2f(100, 50));
	
	walls.emplace_back(top);
	walls.emplace_back(left);
	walls.emplace_back(right);
	walls.emplace_back(center);
	walls.emplace_back(paddle);
	
}

void World::updateAll() {
	ball.update();
	paddle.update();
}

void World::drawAll(sf::RenderWindow& window) {
	window.draw(ball.getShape());
	window.draw(paddle.getShape());
	for (auto& w : walls) {
		window.draw(w.getShape());
	}
}

bool horizontalCollision(Ball& ball, Rectangle& rect) {
	auto& circle = dynamic_cast<const sf::CircleShape&>(ball.getShape());
	auto& rectangle = dynamic_cast<const sf::RectangleShape&>(rect.getShape());
	float rad = circle.getRadius();
	sf::Vector2f center = circle.getPosition() + sf::Vector2f(rad, rad);
	//top left corner of the rectangle
	sf::Vector2f rectPos = rectangle.getPosition();
	sf::Vector2f rectSize = rectangle.getSize();
	//upper surface of the rectangle
	float u = rectPos.y;
	//lower surface of the rectangle
	float l = u + rectSize.y;

	// the ball intersects the either the straight lines of the upper or lower 
	//surfaces of the rectangle
	//while being confined within the range (leftcorner.x, leftcorner.x + w)
	return (rad * rad - (u - center.y) * (u - center.y) >= 0 ||
		rad * rad - (l - center.y) * (l - center.y) >= 0) &&
		((rectPos.x <= center.x + rad && center.x + rad <= rectPos.x + rectSize.x) ||
			(rectPos.x <= center.x - rad && center.x - rad <= rectPos.x + rectSize.x));
}

bool verticalCollision(Ball& ball, Rectangle& rect) {
	auto& circle = dynamic_cast<const sf::CircleShape&>(ball.getShape());
	auto& rectangle = dynamic_cast<const sf::RectangleShape&>(rect.getShape());
	float rad = circle.getRadius();
	sf::Vector2f center = circle.getPosition() + sf::Vector2f(rad, rad);
	sf::Vector2f rectPos = rectangle.getPosition();
	sf::Vector2f rectSize = rectangle.getSize();
	//left surface of the rectangle
	float l = rectPos.x;
	//right surface of the rectangle
	float r = l + rectSize.x;

	// the ball intersects the either the straight lines of the left or right 
	//surfaces of the rectangle
	//while being confined within the range (leftcorner.y, leftcorner.y + h)
	return (rad * rad - (l - center.x) * (l - center.x) >= 0 ||
		rad * rad - (r - center.x) * (r - center.x) >= 0) &&
		((rectPos.y <= center.y + rad && center.y + rad <= rectPos.y + rectSize.y) ||
			(rectPos.y <= center.y - rad && center.y - rad <= rectPos.y + rectSize.y));
}

void World::checkForCollisions() {
	//ball collides with stuff
	for (auto& wall : walls) {
		if (horizontalCollision(ball, wall)) {
			//std::cout << "horizontal Collision!" << std::endl;
			ball.setVelocity(sf::Vector2f(
				ball.getVelocity().x,
				-ball.getVelocity().y
			));
		}
		if (verticalCollision(ball, wall)) {
			//std::cout << "vertical Collision!" << std::endl;
			ball.setVelocity(sf::Vector2f(
				-ball.getVelocity().x,
				ball.getVelocity().y
			));
		}
	}
}

World::~World() {
	/*delete& ball;
	delete& paddle;*/
}