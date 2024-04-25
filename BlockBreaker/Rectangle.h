#pragma once
#include "GameObject.h"

class Rectangle: public GameObject
{
public:
	Rectangle(const sf::Vector2f& position, const sf::Vector2f& size);
	void update() override;
	void onCollision() override;
};

