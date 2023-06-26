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

	void ManejarEstado();

	bool intersectan(Bola& bola);


public:
	Paleta();

	sf::Vector2f getPosition() { return _paleta.getPosition(); }
	sf::Vector2f getSize() { return _size; }
	int getVida() { return _vida; }
	void setVida(int vida) { _vida = vida; }
	void setVelocidad(float velocidad) { _speed = velocidad; }
	void setEstado(ESTADOS_PALETA estado) { _estado = estado; }
	sf::RectangleShape getDraw(){return _paleta;}
	
	void Update(Bola& bola);

	void Colision(Bola& bola);

		
	float x() { return _paleta.getPosition().x; }
	float y() { return _paleta.getPosition().y; }
	float left() { return x() - _paleta.getOrigin().x; }
	float right() { return x() + _paleta.getOrigin().x; }
	float top() { return y() - _paleta.getOrigin().y; }
	float bottom() { return y() + _paleta.getOrigin().y; }

	
};

