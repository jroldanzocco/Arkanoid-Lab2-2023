#include "Paleta.h"

Paleta::Paleta()
{
	_txtPaleta = new sf::Texture[3];
	if (_txtPaleta == nullptr) std::cout << "ERROR DE MEMORIA" << std::endl;
	_txtPaleta[0].loadFromFile("resources/images/paddle.png");
	_estado = NORMAL;
	ManejarEstado();
	_speed = 6.f;
	_paleta.setPosition({ 333,550 });
	_paleta.setOrigin(_paleta.getSize().x / 2.f, _paleta.getSize().y / 2.f);

}

void Paleta::Update(Bola& bola)
{
	_paleta.move(_velocidad);
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && left() > 115.f)
		_velocidad.x = -_speed;
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && right() < 580.f)
		_velocidad.x = _speed;
	else
		_velocidad.x = 0;
	Colision(bola);

}

void Paleta::ManejarEstado()
{
	switch (_estado)
	{
	case NORMAL:
		_paleta.setSize({ 88.f, 22.f });
		_paleta.setTexture(&_txtPaleta[0]);
		break;
	case GRANDE:
		break;
	case CHICO:
		break;
	default:
		break;
	}
}

bool Paleta::intersectan(Bola& bola)
{
	return	right() >= bola.left() && left() <= bola.right()
		&& bottom() >= bola.top() && top() <= bola.bottom();
}

void Paleta::Colision(Bola& bola)
{
	if (!intersectan(bola)) return;

	bola.setVelocidad({ bola.getVelocidad().x, bola.getSpeed() * -1 });

	if (bola.x() < x())
		bola.setVelocidad({ bola.getSpeed() * -1, bola.getVelocidad().y });
	else
		bola.setVelocidad({ bola.getSpeed(), bola.getVelocidad().y });
}