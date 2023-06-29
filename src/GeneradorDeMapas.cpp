#include "GeneradorDeMapas.h"

GeneradorDeMapas::GeneradorDeMapas()
{
	_bloquesDestruidos = 0;
	_txtBloques = new sf::Texture[10];
	_txtBloques[0].loadFromFile("resources/images/bloques/amarillo.png");
	_txtBloques[1].loadFromFile("resources/images/bloques/azul.png");
	_txtBloques[2].loadFromFile("resources/images/bloques/blanco.png");
	_txtBloques[3].loadFromFile("resources/images/bloques/celeste.png");
	_txtBloques[4].loadFromFile("resources/images/bloques/gris.png");
	_txtBloques[5].loadFromFile("resources/images/bloques/marron.png");
	_txtBloques[6].loadFromFile("resources/images/bloques/negro.png");
	_txtBloques[7].loadFromFile("resources/images/bloques/rojo.png");
	_txtBloques[8].loadFromFile("resources/images/bloques/rosa-suave.png");
	_txtBloques[9].loadFromFile("resources/images/bloques/verde.png");
}

void GeneradorDeMapas::generarNivel(int nivel)
{
	_bloquesDestruidos = 0;
	switch (nivel)
	{
	case 1:
		_mapa = {
				0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,
				5,0,5,0,0,6,0,7,0,0,
				5,0,5,0,0,6,0,7,0,0,
				5,0,5,0,0,6,0,7,0,0,
				5,0,5,0,0,6,0,7,0,0,
				5,0,5,0,0,6,0,7,0,0,
				5,0,5,0,0,6,0,7,0,0,
				5,0,5,0,0,6,0,7,0,0,
				5,3,5,3,0,6,0,7,3,8,
				0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0
		};
		break;
	case 2:
		_mapa = {
				0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,
				7,7,7,7,7,7,7,7,7,7,
				6,6,6,6,6,6,6,6,6,6,
				5,5,5,5,5,5,5,5,5,5,
				4,4,4,4,4,4,4,4,4,4,
				3,3,3,3,3,3,3,3,3,3,
				0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0
		};
		break;
	default:
		break;
	}

	sf::Vector2f posBloques{ 150.f,50.f };

	for (int i = 0; i < _mapa.size(); i++)
	{

		if (i % 10 == 0 && i != 0)
		{
			posBloques.y += 22.f;
			posBloques.x = 150.f;
		}
		switch (_mapa[i])
		{
		case 1:
			_bloques.push_back(Bloque(posBloques, _txtBloques[6]));
			break;
		case 2:
			_bloques.push_back(Bloque(posBloques, _txtBloques[2]));
			break;
		case 3:
			_bloques.push_back(Bloque(posBloques, _txtBloques[9]));
			break;
		case 4:
			_bloques.push_back(Bloque(posBloques, _txtBloques[8]));
			break;
		case 5:
			_bloques.push_back(Bloque(posBloques, _txtBloques[7]));
			break;
		case 6:
			_bloques.push_back(Bloque(posBloques, _txtBloques[1]));
			break;
		case 7:
			_bloques.push_back(Bloque(posBloques, _txtBloques[0]));
			break;
		case 8:
			_bloques.push_back(Bloque(posBloques, _txtBloques[5]));
			break;
		case 9:
			_bloques.push_back(Bloque(posBloques, _txtBloques[4]));
			break;
		case 10:
			_bloques.push_back(Bloque(posBloques, _txtBloques[3]));
			break;
		case 0:
			break;
		default:
			break;
		}
		posBloques.x += 44.f;
	}
}

void GeneradorDeMapas::Update(Bola& bola)
{
	for (int i = 0; i < _bloques.size(); i++)
	{
		Colision(bola, _bloques[i]);
		if (_bloques[i].getDestruido())
		{
			_bloquesDestruidos += 1;
			_bloques.erase(_bloques.begin() + i);
			
		}
	}
}


void GeneradorDeMapas::Draw(sf::RenderWindow& ventana)
{
	for (int i = 0; i < _bloques.size(); i++)
	{
		ventana.draw(_bloques[i].getDraw());
	}

}

bool GeneradorDeMapas::intersectan(Bola& bola, Bloque& bloque)
{
	return	bola.right() >= bloque.left() && bola.left() <= bloque.right()
		&& bola.bottom() >= bloque.top() && bola.top() <= bloque.bottom();
}

void GeneradorDeMapas::Colision(Bola& bola, Bloque& bloque)
{
	if (!intersectan(bola, bloque)) return;

	bloque.setDestruido(true);

	float overLeft = bola.right() - bloque.left();
	float overRight = bloque.right() - bola.left();
	float overTop = bola.bottom() - bloque.top();
	float overBottom = bloque.bottom() - bola.top();

	bool bolaDesdeIzq(abs(overLeft) < abs(overRight));
	bool bolaDesdeArriba(abs(overTop) < abs(overBottom));

	float minOverLapX, minOverLapY;

	if (bolaDesdeIzq)
		minOverLapX = overLeft;
	else
		minOverLapX = overRight;

	if (bolaDesdeArriba)
		minOverLapY = overTop;
	else
		minOverLapY = overBottom;

	if (abs(minOverLapX) < abs(minOverLapY))
	{
		if (bolaDesdeIzq)
			bola.setVelocidad({ bola.getSpeed() * -1,bola.getVelocidad().y });
		else
			bola.setVelocidad({ bola.getSpeed(),bola.getVelocidad().y });
	}
	else
	{
		if (bolaDesdeArriba)
			bola.setVelocidad({ bola.getVelocidad().x, bola.getSpeed() * -1 });
		else
			bola.setVelocidad({ bola.getVelocidad().x, bola.getSpeed() });
	}
}

GeneradorDeMapas::~GeneradorDeMapas()
{
	delete[] _txtBloques;
}