#include "Animacion.h"

Animacion::Animacion(sf::Texture& textura, sf::Vector2u contadorImagen, float tiempoTransicion)
{
	_finAnimacion = false;
	_contadorImagen = contadorImagen;
	_tiempoTransicion = tiempoTransicion;
	_tiempoTotal = 0.f;
	_imagenActual.x = 0;

	uvRect.width = textura.getSize().x / float(contadorImagen.x);
	uvRect.height = textura.getSize().y / float(contadorImagen.y);

}

void Animacion::Update(int fila, float deltaTime)
{
	_imagenActual.y = fila;
	_tiempoTotal += deltaTime;

	if (_tiempoTotal >= _tiempoTransicion)
	{
		_tiempoTotal -= _tiempoTransicion;
		_imagenActual.x++;

		if (_imagenActual.x >= _contadorImagen.x)
		{
			_imagenActual.x = 0;

		}
	}
	uvRect.left = _imagenActual.x * uvRect.width;
	uvRect.top = _imagenActual.y * uvRect.height;
}