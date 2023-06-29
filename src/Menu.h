#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ArchivoPuntajes.h"
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
	ArchivoPuntajes *_archPuntaje;
	Background * _fondo;
	sf::Text _textPlay;
	int _botonSeleccionado, _segundoBoton, _tercerBoton, _cuartoBoton;
	sf::Texture* _txtBotonGrande;
	sf::Texture* _txtBotonChico;
	sf::Texture _botonFlecha[2];
	sf::Texture _txtTablaPos;
	sf::RectangleShape _rectTablaPos;
	sf::RectangleShape _rectFlechas[2];
	sf::RectangleShape* _rectBotones;
	ESTADOS_MENU _estado;
	sf::Clock _reloj;


	sf::Font _fuenteVenus;
	sf::Text textoClasificacion;
	sf::Text posiciones[10];
public:
	Menu();

	void Draw(sf::RenderWindow& ventana);
	void Update(int &eleccion);
	void generartablaPos()
	{
		int cantReg = _archPuntaje->contarRegistros();
		Puntajes punt[10];
		std::string s;
		for (int i = 0; i < 10; i++)
		{
			punt[i] = _archPuntaje->leerRegistro(i);
			s = punt[i].getNombre();
			posiciones[i].setString(s + "\t" + std::to_string(punt[i].getPuntaje()));

		}
		
	}
	~Menu();
};

