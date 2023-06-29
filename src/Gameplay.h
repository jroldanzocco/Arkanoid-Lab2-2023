#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bola.h"
#include "Background.h"
#include "Menu.h"
#include "Paleta.h"
#include "GeneradorDeMapas.h"
#include "Puntajes.h"
#include "ArchivoPuntajes.h"
#include "CajaDeTexto.h"

enum ESTADOS_GAMEPLAY
{
	MENU_PRINCIPAL,
	NUEVO_JUEGO,
	NIVEL_COMPLETADO,
	DERROTA
};


class Gameplay
{
private:
	sf::RenderWindow * _ventana;
	Menu _menuPrincipal;
	Background* _fondo;
	Paleta _paleta;
	Bola _bola;
	GeneradorDeMapas _mapa;
	ArchivoPuntajes* _archPuntos;
	Puntajes _puntuacion;
	CajaDeTexto _ingresoNombre;
	ESTADOS_GAMEPLAY _estado;
	
	sf::Clock _reloj;
	sf::Event _evento;

	sf::Font _fuenteVenus;
	sf::Font _fuentePuntos;
	sf::Text _textoPuntos[2];
	sf::RectangleShape _rectScore;

	sf::Texture _texturasVictODerr[2];
	sf::RectangleShape _rectVictODerr;
	sf::Text _textoDerrota;

	int _eleccionMenu;
	int _nivel;
	int _vidas;
	bool _servir;
	
	sf::Texture _txtVidas;
	sf::RectangleShape _rectVidas;

	sf::Texture prBorde;
	sf::Sprite sprborde;
	
public:
	Gameplay(unsigned int x, unsigned int y, std::string nombre);

	void inicializacion();

	void Update();
	void gestionarTextos();
	void Draw();
	void reiniciarJuego();
	void actualizarPuntos();
	
	bool ComprobarGuardado();
	
	void registrarPuntaje();

	void sortPuntajes(Puntajes arr[], int n);


	~Gameplay();
};

