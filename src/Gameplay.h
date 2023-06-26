#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bola.h"
#include "Background.h"
#include "Menu.h"
#include "Paleta.h"
#include "GeneradorDeMapas.h"
#include "Puntajes.h"
#include "Animacion.h"
enum ESTADOS_GAMEPLAY
{
	MENU_PRINCIPAL,
	NUEVO_JUEGO,
	JUEGO_EN_PAUSA,
	NIVEL_COMPLETADO,
	NIVEL_PERDIDO,
	PUNTUACION,
	SELECCION_PALETA,
	GAME_OVER,
	INGRESAR_NOMBRE
};


class Gameplay
{
private:
	Menu menuPrincipal;
	Puntajes _puntuacion;
	sf::RenderWindow * ventana;
	sf::Clock _reloj;
	sf::Event _evento;
	ESTADOS_GAMEPLAY _estado;
	int _eleccionMenu;
	Background *_fondo;
	Paleta paleta;

	float deltaTime;

	sf::Texture prBorde;
	sf::Sprite sprborde;

	Bola pelotita;
	GeneradorDeMapas mapa;
	
public:
	Gameplay()
	{
		
		Inicializacion();
		while (ventana->isOpen())
		{
			deltaTime = _reloj.restart().asSeconds();
			while (ventana->pollEvent(_evento))
			{
				if (_evento.type == sf::Event::Closed || _eleccionMenu == 3){
					ventana->close();
				exit(1);
				}
			}
			if (_eleccionMenu == 0)
				_estado = NUEVO_JUEGO;

			ventana->clear();
			
			Update();
			Draw();
			
			ventana->display();
		}
		
	}

	void Inicializacion()
	{
		
		_eleccionMenu = -1;
		_puntuacion.setPuntaje(0);
		ventana = new sf::RenderWindow(sf::VideoMode(800, 600), "Arkanoid");
		ventana->setFramerateLimit(60);
		_estado = MENU_PRINCIPAL;
		prBorde.loadFromFile("resources/images/borders.png");
		_fondo = new Background(JUEGO);
		sprborde.setTexture(prBorde);
		sprborde.setPosition(100, 0);
		mapa.generarNivel(1);
	}

	void Update()
	{
		switch (_estado)
		{
		case MENU_PRINCIPAL:
			_eleccionMenu = menuPrincipal.Update();
			break;
		case NUEVO_JUEGO:
			mapa.Update(pelotita);
			pelotita.Update();
			paleta.Update(pelotita);
			break;
		case NIVEL_COMPLETADO:
			break;
		case PUNTUACION:
			break;
		case SELECCION_PALETA:
			break;
		case GAME_OVER:
			break;
		case INGRESAR_NOMBRE:
			break;
		default:
			break;
		}
		
	}
	
	void Draw()
	{
		switch (_estado)
		{
		case MENU_PRINCIPAL:
			menuPrincipal.Draw(*ventana);
			break;
		case NUEVO_JUEGO: 
			ventana->draw(_fondo->getDraw());
			ventana->draw(sprborde);
			mapa.Draw(*ventana);
			ventana->draw(paleta.getDraw());
			ventana->draw(pelotita.getDraw());
			break;
		case NIVEL_COMPLETADO:
			break;
		case PUNTUACION:
			break;
		case SELECCION_PALETA:
			break;
		case GAME_OVER:
			break;
		case INGRESAR_NOMBRE:
			break;
		default:
			break;
		}
	}
	


	~Gameplay()
	{
		delete ventana;
		delete _fondo;
	}
};

