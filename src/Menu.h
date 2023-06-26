#pragma once
#include <SFML/Graphics.hpp>
#include "Background.h"

enum ESTADOS_MENU
{
	PRINCIPAL,
	MEJOR_PUNTUACION,
	CREDITOS
};


class Menu
{
private:
	Background * _fondo;
	//sf::Event _evento;
	//sf::Font _fuente;
	sf::Text _textPlay;
	int _botonSeleccionado, _segundoBoton, _tercerBoton, _cuartoBoton;
	sf::Texture* _txtBotonGrande;
	sf::Texture* _txtBotonChico;
	sf::RectangleShape* _sprBotones;
	ESTADOS_MENU _estado;
public:
	Menu()
	{
		_estado = PRINCIPAL;

		_botonSeleccionado = 0;
		_segundoBoton = 1;
		_tercerBoton = 2;
		_cuartoBoton = 3;
		_txtBotonGrande = new sf::Texture[4];
		_txtBotonChico = new sf::Texture[4];

		_txtBotonGrande[0].loadFromFile("resources/images/menu/play160.png");
		_txtBotonGrande[1].loadFromFile("resources/images/menu/puntos160.png");
		_txtBotonGrande[2].loadFromFile("resources/images/menu/about160.png");
		_txtBotonGrande[3].loadFromFile("resources/images/menu/salir160.png");


		_txtBotonChico[0].loadFromFile("resources/images/menu/play80.png");
		_txtBotonChico[1].loadFromFile("resources/images/menu/puntos80.png");
		_txtBotonChico[2].loadFromFile("resources/images/menu/about80.png");
		_txtBotonChico[3].loadFromFile("resources/images/menu/salir80.png");

		
		_sprBotones = new sf::RectangleShape[4];
		
		
		_sprBotones[0].setTexture(&_txtBotonGrande[0]);
		_sprBotones[0].setSize({ 160, 160 });
		_sprBotones[0].setOrigin(_sprBotones[0].getSize().x / 2, _sprBotones[0].getSize().y / 2);
		_sprBotones[0].setPosition(400, 500);

		_sprBotones[1].setTexture(&_txtBotonChico[1]);
		_sprBotones[1].setSize({ 80, 80 });
		_sprBotones[1].setOrigin(_sprBotones[1].getSize().x / 2, _sprBotones[1].getSize().y / 2);
		_sprBotones[1].setPosition(250, 400);
		_sprBotones[1].setFillColor(sf::Color(255, 255, 255, 180));

		_sprBotones[2].setTexture(&_txtBotonChico[2]);
		_sprBotones[2].setSize({ 80, 80 });
		_sprBotones[2].setOrigin(_sprBotones[2].getSize().x / 2, _sprBotones[2].getSize().y / 2);
		_sprBotones[2].setPosition(400, 300);
		_sprBotones[2].setFillColor(sf::Color(255, 255, 255, 180));

		_sprBotones[3].setTexture(&_txtBotonChico[3]);
		_sprBotones[3].setSize({ 80, 80 });
		_sprBotones[3].setOrigin(_sprBotones[3].getSize().x / 2, _sprBotones[3].getSize().y / 2);
		_sprBotones[3].setPosition(550, 400);
		_sprBotones[3].setFillColor(sf::Color(255, 255, 255, 180));
	}

	void Draw(sf::RenderWindow& ventana)
	{
		_fondo = new Background(MENU);
		ventana.draw(_fondo->getDraw());
		switch (_estado)
		{
		case PRINCIPAL:
			ventana.draw(_sprBotones[0]);
			ventana.draw(_sprBotones[1]);
			ventana.draw(_sprBotones[2]);
			ventana.draw(_sprBotones[3]);
			break;
		case MEJOR_PUNTUACION:
			break;
		case CREDITOS:
			break;
		default:
			break;
		}
		
	}
	int Update()
	{
		switch (_estado)
		{
		case PRINCIPAL:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				_botonSeleccionado--;
				_segundoBoton--;
				_tercerBoton--;
				_cuartoBoton--;
				if (_botonSeleccionado < 0)
				{
					_botonSeleccionado = 3;
				}
				if (_segundoBoton < 0)
				{
					_segundoBoton = 3;
				}
				if (_tercerBoton < 0)
				{
					_tercerBoton = 3;
				}
				if (_cuartoBoton < 0)
				{
					_cuartoBoton = 3;
				}

				_sprBotones[0].setTexture(&_txtBotonGrande[_botonSeleccionado]);
				_sprBotones[1].setTexture(&_txtBotonChico[_segundoBoton]);
				_sprBotones[2].setTexture(&_txtBotonChico[_tercerBoton]);
				_sprBotones[3].setTexture(&_txtBotonChico[_cuartoBoton]);
				sf::sleep(sf::milliseconds(100));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				_botonSeleccionado++;
				_segundoBoton++;
				_tercerBoton++;
				_cuartoBoton++;
				if (_botonSeleccionado > 3)
				{
					_botonSeleccionado = 0;
				}
				if (_segundoBoton > 3)
				{
					_segundoBoton = 0;
				}
				if (_tercerBoton > 3)
				{
					_tercerBoton = 0;
				}
				if (_cuartoBoton > 3)
				{
					_cuartoBoton = 0;
				}

				_sprBotones[0].setTexture(&_txtBotonGrande[_botonSeleccionado]);
				_sprBotones[1].setTexture(&_txtBotonChico[_segundoBoton]);
				_sprBotones[2].setTexture(&_txtBotonChico[_tercerBoton]);
				_sprBotones[3].setTexture(&_txtBotonChico[_cuartoBoton]);
				sf::sleep(sf::milliseconds(100));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				switch (_botonSeleccionado)
				{
				case 0:
					return _botonSeleccionado;
					break;
				case 1:
					return _botonSeleccionado;
					break;
				case 2:
					return _botonSeleccionado;
					break;
				case 3:
					return 3;
					break;
				default:
					return -1;
					break;
				}
			}
				break;
		case MEJOR_PUNTUACION:
			break;
		case CREDITOS:
			break;
		default:
			break;
		}	
		return -1;
	}
	~Menu()
	{
		delete _fondo;
		delete _txtBotonChico;
		delete _txtBotonGrande;
	}
};

