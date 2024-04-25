#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Ball.h"
#include "Input.h"
#include "Rectangle.h"

class Paddle: public Rectangle
{
private:
	bool ballLaunched;
	Ball& ball;
public:
	Paddle(Ball& ball);
	void setSize(sf::Vector2f& newSize);
	void update() override;
	void onCollision() override;
	~Paddle();
};

