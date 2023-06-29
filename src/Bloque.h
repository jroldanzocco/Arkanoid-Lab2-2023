#pragma once
#include <SFML/Graphics.hpp>

#include "Bola.h"



class Bloque
{
private:
    sf::RectangleShape _bloque;
	bool _destruido;
public:
	Bloque(sf::Vector2f& posicion, sf::Texture& txtBloque);
	void setColor(sf::Color& color) { _bloque.setFillColor(color); }
	void setDestruido(bool destruido) { _destruido = destruido; }
	bool getDestruido() { return _destruido; }

	sf::RectangleShape getDraw(){return _bloque;}

	float x() { return _bloque.getPosition().x; }
	float y() { return _bloque.getPosition().y; }
	float left() { return x() - _bloque.getOrigin().x; }
	float right() { return x() + _bloque.getOrigin().x; }
	float top() { return y() - _bloque.getOrigin().y; }
	float bottom() { return y() + _bloque.getOrigin().y; }

};

