#pragma once
#include <iostream>
#include "Bola.h"
#include <SFML/Graphics.hpp>


enum ESTADOS_PALETA
{
	NORMAL,
	GRANDE,
	CHICO
};

class Paleta
{
private:
	sf::Texture *_txtPaleta;
	sf::RectangleShape _paleta;
	float _speed;
	sf::Vector2f _velocidad;
	int _vida;
	ESTADOS_PALETA _estado;
	sf::Vector2f _size;

	void ManejarEstado()
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

	bool intersectan(Bola& bola)
	{
		return	right() >= bola.left() && left() <= bola.right()
			&& bottom() >= bola.top() && top() <= bola.bottom();
	}


public:
	Paleta()
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
	sf::Vector2f getPosition() { return _paleta.getPosition(); }
	sf::Vector2f getSize() { return _size; }
	int getVida() { return _vida; }
	void setVida(int vida) { _vida = vida; }
	void setVelocidad(float velocidad) { _speed = velocidad; }
	void setEstado(ESTADOS_PALETA estado) { _estado = estado; }
	void Update(Bola& bola)
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

	sf::RectangleShape getDraw()
	{
		return _paleta;
	}

	void Colision(Bola& bola)
	{
		if (!intersectan(bola)) return;

		bola.setVelocidad({ bola.getVelocidad().x, bola.getSpeed() * -1 });

		if (bola.x() < x())
			bola.setVelocidad({ bola.getSpeed() * -1, bola.getVelocidad().y });
		else
			bola.setVelocidad({ bola.getSpeed(), bola.getVelocidad().y });
	}

		
	float x() { return _paleta.getPosition().x; }
	float y() { return _paleta.getPosition().y; }
	float left() { return x() - _paleta.getOrigin().x; }
	float right() { return x() + _paleta.getOrigin().x; }
	float top() { return y() - _paleta.getOrigin().y; }
	float bottom() { return y() + _paleta.getOrigin().y; }

	
};

