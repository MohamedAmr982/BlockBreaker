#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

class Input
{
private:
	sf::Window* window;
	static Input* input;
	Input();
public:
	static void setWindow(sf::Window* window);
	static bool mouseClicked();
	static sf::Vector2i getMousePosition();
};

