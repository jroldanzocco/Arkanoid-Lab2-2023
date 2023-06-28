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
	int _nivel;
	sf::Clock _reloj;
	sf::Event _evento;
	ESTADOS_GAMEPLAY _estado;
	int _eleccionMenu;
	Background *_fondo;
	Paleta paleta;

	sf::Font _fuentePuntos;
	sf::Text _textoPuntos[2];

	float deltaTime;

	sf::Texture prBorde;
	sf::Sprite sprborde;

	Bola pelotita;
	GeneradorDeMapas mapa;
	bool servido;
	
public:
	Gameplay();

	void Inicializacion();

	void Update();
	
	void Draw();
	void ReiniciarJuego();
	void ActualizarPuntos();
	
	~Gameplay();
};

