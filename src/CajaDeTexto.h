#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>

#define BORRAR 8
#define ENTER 13
#define ESCAPE 27


class CajaDeTexto
{
private:
	sf::Text _cajaDeTexto;
	std::ostringstream _texto;
	int _limite;
	int _tam = 30;
	sf::Color _color = sf::Color::White;

	void logIngreso(int charIngresado);
	void BorrarUltimoChar();

public:
	CajaDeTexto();

	std::string getText() { return _texto.str(); }
	sf::Text getDraw() { return _cajaDeTexto; }
	void setFuente(sf::Font& fuente){_cajaDeTexto.setFont(fuente);}
	void setPosition(sf::Vector2f pos){_cajaDeTexto.setPosition(pos);}
	void escribir(sf::Event ingreso);

};

