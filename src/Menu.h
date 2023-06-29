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
	sf::Text _textPlay;
	int _botonSeleccionado, _segundoBoton, _tercerBoton, _cuartoBoton;
	sf::Texture* _txtBotonGrande;
	sf::Texture* _txtBotonChico;
	sf::RectangleShape* _sprBotones;
	ESTADOS_MENU _estado;
public:
	Menu();

	void Draw(sf::RenderWindow& ventana);
	int Update();

	~Menu();
};

