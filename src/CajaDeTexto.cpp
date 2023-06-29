#include "CajaDeTexto.h"


CajaDeTexto::CajaDeTexto()
{
	_limite = 8;
	_cajaDeTexto.setCharacterSize(_tam);
	_cajaDeTexto.setFillColor(_color);
}

void CajaDeTexto::logIngreso(int charIngresado)
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

void CajaDeTexto::BorrarUltimoChar()
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

void CajaDeTexto::escribir(sf::Event ingreso)
{
	int ingresoChar = ingreso.text.unicode;
	if (ingresoChar >= 65 && ingresoChar <= 122)
	{
		if (_texto.str().length() < _limite)
			logIngreso(ingresoChar);
	}
	else if (ingresoChar == BORRAR)
		logIngreso(ingresoChar);
}