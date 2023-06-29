#pragma once
#include <SFML/Graphics.hpp>
class Bola
{
private:
	sf::Texture* _txtBola;
	sf::CircleShape _bola;
	sf::Vector2f _direccion;
	float _speed;
public:
	Bola();
	float getSpeed() { return _speed; }
	void setColor(sf::Color& color) { _bola.setFillColor(color); }
	void setVelocidad(sf::Vector2f velocidad) { _direccion = velocidad; }
	void setPosition(sf::Vector2f pos) { _bola.setPosition(pos); }
	sf::Vector2f getVelocidad() { return _direccion; }
	sf::CircleShape getDraw(){return _bola;}

	void Update();

	float x()		{ return _bola.getPosition().x; }
	float y()		{ return _bola.getPosition().y; }
	float left()	{ return x() - _bola.getRadius(); }
	float right()	{ return x() + _bola.getRadius(); }
	float top()     { return y() - _bola.getRadius(); }
	float bottom()	{ return y() + _bola.getRadius(); }

	
};

