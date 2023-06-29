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
	bool _seleccionado = false;
	int _limite;
	int _tam = 30;
	sf::Color _color = sf::Color::White;

	void logIngreso(int charIngresado)
	{
		if (charIngresado != BORRAR && charIngresado != ENTER && charIngresado != ESCAPE)
			_texto << (char)charIngresado;
		else if (charIngresado == BORRAR)
		{
			if (_texto.str().length() > 0)
			{
				BorrarUltimoChar();
			}
		}
		_cajaDeTexto.setString(_texto.str() + "_");
	}

	void BorrarUltimoChar()
	{
		std::string t = _texto.str();
		std::string newT = "";
		for (int i = 0; i < t.length() - 1; i++)
		{
			newT += t[i];
		}
		_texto.str("");
		_texto << newT;

		_cajaDeTexto.setString(_texto.str());
	}

public:
	CajaDeTexto(){}

	CajaDeTexto(bool seleccionado)
	{
		_limite = 8;
		_cajaDeTexto.setCharacterSize(_tam);
		_cajaDeTexto.setFillColor(_color);
		_seleccionado = seleccionado;
		if (_seleccionado)
			_cajaDeTexto.setString("_");
		else
			_cajaDeTexto.setString("");
	}

	void setFuente(sf::Font& fuente)
	{
		_cajaDeTexto.setFont(fuente);
	}

	void setPosition(sf::Vector2f pos)
	{
		_cajaDeTexto.setPosition(pos);
	}

	void setSeleccionado(bool sel)
	{
		_seleccionado = sel;
		if (!_seleccionado)
		{
			std::string t = _texto.str();
			std::string newT = "";
			for (int i = 0; i < t.length(); i++)
			{
				newT += t[i];
			}
			_cajaDeTexto.setString(newT);
		}
	}

	std::string getText()
	{
		return _texto.str();
	}

	sf::Text getDraw()
	{
		return _cajaDeTexto;
	}

	void escribir(sf::Event ingreso)
	{
		if (_seleccionado)
		{
			int ingresoChar = ingreso.text.unicode;
			if (ingresoChar >= 65 && ingresoChar <= 122 )
			{
				if (_texto.str().length() < _limite)
					logIngreso(ingresoChar);
			}
			else if (ingresoChar == BORRAR)
				logIngreso(ingresoChar);
			
			
		}
	}

};

