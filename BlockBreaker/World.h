#pragma once
#include "GameObject.h"
#include "Ball.h"
#include "Paddle.h"
#include "Rectangle.h"
#include <vector>

class World
{
private:
	Ball ball;
	Paddle paddle;
	std::vector<Rectangle> walls;
public:
	World();
	void updateAll();
	void checkForCollisions();
	void drawAll(sf::RenderWindow& window);
	~World();
};

