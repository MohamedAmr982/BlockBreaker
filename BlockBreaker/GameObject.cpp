#include "GameObject.h"

GameObject::GameObject(const sf::Shape& shape, const sf::Color& color, const sf::Vector2f& position)
	: shape((sf::Shape&)shape)
{
	this->shape.setFillColor(color);
	this->shape.setPosition(position);
}

void GameObject::setPosition(const sf::Vector2f& position) {
	this->shape.setPosition(position);
}

void GameObject::setShape(const sf::Shape& shape) {
	this->shape = shape;
}

void GameObject::setColor(const sf::Color& color) {
	this->shape.setFillColor(color);
}

const sf::Shape& GameObject::getShape() {
	return shape;
}

const sf::Vector2f& GameObject::getPosition(){
	return shape.getPosition();
}

GameObject::~GameObject() {}
