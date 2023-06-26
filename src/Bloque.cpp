#include "Bloque.h"

Bloque::Bloque(sf::Vector2f& posicion, sf::Texture& txtBloque)
{
	_destruido = false;
	_bloque.setSize({ 44.f, 22.f });
	_bloque.setOrigin(_bloque.getSize().x / 2.f, _bloque.getSize().y / 2.f);
	_bloque.setPosition(posicion);
	_bloque.setTexture(&txtBloque);
}
