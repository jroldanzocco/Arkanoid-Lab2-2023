#include "Bola.h"

Bola::Bola()
{
	_speed = 5.f;
	_velocidad = { -_speed,-_speed };
	_bola.setRadius(7.f);
	_bola.setPosition({ 256,530 });
	_bola.setOrigin(_bola.getRadius(), _bola.getRadius());
	_txtBola = new sf::Texture;
	_txtBola->loadFromFile("resources/images/ball.png");
	_bola.setTexture(_txtBola);

}

void Bola::Update()
{
	_bola.move(_velocidad);
	if (left() < 115.f)
		_velocidad.x = _speed;
	else if (right() > 580.f)
		_velocidad.x = -_speed;

	if (top() < 17.f) _velocidad.y = _speed;
	else if (bottom() > 600.f) _velocidad.y = -_speed;

}