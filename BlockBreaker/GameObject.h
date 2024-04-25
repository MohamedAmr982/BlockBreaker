#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{

protected:
	sf::Shape& shape;

public:
	GameObject(const sf::Shape& shape, const sf::Color& color, const sf::Vector2f& position);
	void setPosition(const sf::Vector2f& position);
	void setShape(const sf::Shape& shape);
	void setColor(const sf::Color& color);
	const sf::Shape& getShape();
	const sf::Vector2f& getPosition();
	virtual void update() = 0;
	virtual void onCollision() = 0;
	virtual ~GameObject();
};

