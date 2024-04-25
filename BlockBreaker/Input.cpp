#include "Input.h"


//static members should be assigned in c++ files
Input* Input::input = nullptr;

Input::Input()
	: window(nullptr)
{
}

void Input::setWindow(sf::Window* reference) {
	if (input == nullptr) {
		input = new Input();
	}
	input->window = reference;
}

bool Input::mouseClicked() {
	return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

sf::Vector2i Input::getMousePosition() {
	if (input == nullptr) {
		throw std::runtime_error("window attribute not assigned.");
	}
	return sf::Mouse::getPosition(*(input->window));
}