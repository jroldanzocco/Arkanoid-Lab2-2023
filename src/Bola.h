#pragma once
#include <SFML/Graphics.hpp>
class Bola
{
private:
	sf::Texture _txtBola;
	sf::CircleShape _bola;
	sf::Vector2f _velocidad;
	float _speed;
public:
	Bola()
	{
		_speed = 5.f;
		_velocidad = { -_speed,-_speed };
		_bola.setRadius(7.f);
		_bola.setPosition({ 256,530 });
		_bola.setOrigin(_bola.getRadius(), _bola.getRadius());
		_txtBola.loadFromFile("resources/images/ball.png");
		_bola.setTexture(&_txtBola);
		
	}
	float getSpeed() { return _speed; }
	void setVelocidad(sf::Vector2f velocidad) { _velocidad = velocidad; }
	sf::Vector2f getVelocidad() { return _velocidad; }

	sf::CircleShape getDraw()
	{
		return _bola;
	}
	
	void Update()
	{
		_bola.move(_velocidad);
		if (left() < 115.f)
			_velocidad.x = _speed;
		else if (right() > 580.f) 
			_velocidad.x = -_speed;

		if (top() < 17.f) _velocidad.y = _speed;
		else if (bottom() > 600.f) _velocidad.y = -_speed;

	}


	float x()		{ return _bola.getPosition().x; }
	float y()		{ return _bola.getPosition().y; }
	float left()	{ return x() - _bola.getRadius(); }
	float right()	{ return x() + _bola.getRadius(); }
	float top()     { return y() - _bola.getRadius(); }
	float bottom()	{ return y() + _bola.getRadius(); }

	
};

