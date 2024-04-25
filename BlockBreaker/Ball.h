#pragma once
#include "GameObject.h"

class Ball: public GameObject
{
private:
	sf::Vector2f velocity;
public:
	Ball();
	void setSize(float radius);
	void setVelocity(const sf::Vector2f& velocity);
	const sf::Vector2f& getVelocity();
	void update() override;
	void onCollision() override;
	~Ball();
};

