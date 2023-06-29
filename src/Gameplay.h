#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bola.h"
#include "Background.h"
#include "Menu.h"
#include "Paleta.h"
#include "GeneradorDeMapas.h"
#include "Puntajes.h"

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
	sf::RenderWindow * _ventana;
	Menu _menuPrincipal;
	Background* _fondo;
	Paleta paleta;
	Bola _bola;
	GeneradorDeMapas _mapa;
	Puntajes _puntuacion;
	ESTADOS_GAMEPLAY _estado;
	
	sf::Clock _reloj;
	sf::Event _evento;

	sf::Font _fuentePuntos;
	sf::Text _textoPuntos[2];

	int _eleccionMenu;
	int _nivel;
	int _vidas;
	bool _servir;
	

	sf::Texture prBorde;
	sf::Sprite sprborde;
	
public:
	Gameplay(unsigned int x, unsigned int y, std::string nombre);

	void Inicializacion();

	void Update();
	void gestionarTextos();
	void Draw();
	void ReiniciarJuego();
	void ActualizarPuntos();
	
	~Gameplay();
};

