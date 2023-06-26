#include "Gameplay.h"

Gameplay::Gameplay()
{

	Inicializacion();
	while (ventana->isOpen())
	{
		deltaTime = _reloj.restart().asSeconds();
		while (ventana->pollEvent(_evento))
		{
			if (_evento.type == sf::Event::Closed || _eleccionMenu == 3) {
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

void Gameplay::Inicializacion()
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

void Gameplay::Update()
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

void Gameplay::Draw()
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

Gameplay::~Gameplay()
{
	delete ventana;
	delete _fondo;
}