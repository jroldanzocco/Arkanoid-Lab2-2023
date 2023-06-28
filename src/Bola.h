#pragma once
#include <SFML/Graphics.hpp>
class Bola
{
private:
	sf::Texture* _txtBola;
	sf::CircleShape _bola;
	sf::Vector2f _velocidad;
	float _speed;
public:
	Bola();
	float getSpeed() { return _speed; }
	void setVelocidad(sf::Vector2f velocidad) { _velocidad = velocidad; }
	void setPosition(sf::Vector2f pos) { _bola.setPosition(pos); }
	sf::Vector2f getVelocidad() { return _velocidad; }
	sf::CircleShape getDraw(){return _bola;}

	void Update();

	float x()		{ return _bola.getPosition().x; }
	float y()		{ return _bola.getPosition().y; }
	float left()	{ return x() - _bola.getRadius(); }
	float right()	{ return x() + _bola.getRadius(); }
	float top()     { return y() - _bola.getRadius(); }
	float bottom()	{ return y() + _bola.getRadius(); }

	
};

