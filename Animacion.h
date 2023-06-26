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
	Animacion();
	Animacion(sf::Texture& textura, sf::Vector2u contadorImagen, float tiempoTransicion)
	{
		_finAnimacion = false;
		_contadorImagen = contadorImagen;
		_tiempoTransicion = tiempoTransicion;
		_tiempoTotal = 0.f;
		_imagenActual.x = 0;

		uvRect.width = textura.getSize().x / float(contadorImagen.x);
		uvRect.height = textura.getSize().y / float(contadorImagen.y);

	}

	void Update(int fila, float deltaTime)
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

	void Asignar(sf::Texture& textura, sf::Vector2u contadorImagen, float tiempoTransicion)
	{
		_contadorImagen = contadorImagen;
		_tiempoTransicion = tiempoTransicion;
		_tiempoTotal = 0.f;
		_imagenActual.x = 0;

		uvRect.width = textura.getSize().x / float(contadorImagen.x);
		uvRect.height = textura.getSize().y / float(contadorImagen.y);
	}

	

	sf::Vector2u getImagenActual() { return _imagenActual; }

	sf::IntRect uvRect;
	~Animacion();
};

