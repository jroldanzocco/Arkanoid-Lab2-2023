#pragma once
#include <SFML/Graphics.hpp>

class Animacion
{
private:
	sf::Vector2u _contadorImagen;
	sf::Vector2u _imagenActual;

	float _tiempoTotal;
	float _tiempoTransicion;
	bool _finAnimacion;
public:
	Animacion(sf::Texture& textura, sf::Vector2u contadorImagen, float tiempoTransicion);

	void Update(int fila, float deltaTime);

	sf::Vector2u getImagenActual() { return _imagenActual; }

	sf::IntRect uvRect;
};

