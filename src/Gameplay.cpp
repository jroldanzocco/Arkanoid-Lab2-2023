#include "Gameplay.h"

Gameplay::Gameplay(float x, float y, std::string nombre)
{
	ventana = new sf::RenderWindow(sf::VideoMode(x,y), nombre);
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
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && _estado == NUEVO_JUEGO)
		{
			_estado = MENU_PRINCIPAL;
		}

		ventana->clear();
		if (_eleccionMenu == 0)
		{
			_nivel = 1;
			_estado = NUEVO_JUEGO;
			_eleccionMenu = -1;
			ReiniciarJuego();
		}
		Update();
		Draw();

		ventana->display();
	}

}

void Gameplay::Inicializacion()
{
	_eleccionMenu = -1;
	
	ventana->setFramerateLimit(60);
	_estado = MENU_PRINCIPAL;
	prBorde.loadFromFile("resources/images/borders.png");
	_fondo = new Background(JUEGO);
	sprborde.setTexture(prBorde);
	sprborde.setPosition(100, 0);
	if (!_fuentePuntos.loadFromFile("resources/fonts/pixel.ttf"))
		throw("No se pudo cargar la fuente");
	_textoPuntos[0].setFont(_fuentePuntos);
	_textoPuntos[0].setCharacterSize(24);
	_textoPuntos[0].setFillColor(sf::Color::Black);
	_textoPuntos[0].setStyle(sf::Text::Bold);
	_textoPuntos[0].setPosition(650, 230);
	_textoPuntos[1].setFont(_fuentePuntos);
	_textoPuntos[1].setCharacterSize(24);
	_textoPuntos[1].setFillColor(sf::Color::Black);
	_textoPuntos[1].setStyle(sf::Text::Bold);
	_textoPuntos[1].setPosition(650, 260);
}

void Gameplay::Update()
{
	switch (_estado)
	{
	case MENU_PRINCIPAL:
		_eleccionMenu = menuPrincipal.Update();
		break;
	case NUEVO_JUEGO:
		if (!servido) {
			pelotita.setPosition({ paleta.getPosition().x, (paleta.getPosition().y - paleta.getSize().y / 2.f - 20.f) });
			paleta.Update(pelotita);
			ActualizarPuntos();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				servido = true;
		}
		else {
		paleta.Update(pelotita);
		mapa.Update(pelotita);
		pelotita.Update();
		ActualizarPuntos();
		}
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
		ventana->draw(_textoPuntos[0]);
		ventana->draw(_textoPuntos[1]);
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


void Gameplay::ActualizarPuntos()
{
	_puntuacion.setPuntaje(mapa.getBloquesDestruidos());
	if (_puntuacion.getPuntaje() == 0)
		_textoPuntos[1].setString("0000");
	else if(_puntuacion.getPuntaje() > 0)
		_textoPuntos[1].setString("000" + std::to_string(_puntuacion.getPuntaje()));
	else if (_puntuacion.getPuntaje() > 10)
		_textoPuntos[1].setString("00" + std::to_string(_puntuacion.getPuntaje()));
	else if (_puntuacion.getPuntaje() > 100)
		_textoPuntos[1].setString("0" + std::to_string(_puntuacion.getPuntaje()));
	else
		_textoPuntos[1].setString(std::to_string(_puntuacion.getPuntaje()));
}

void Gameplay::ReiniciarJuego()
{
	mapa.generarNivel(_nivel);
	pelotita = Bola();
	paleta = Paleta();
	delete _fondo;
	_fondo = new Background(JUEGO);
	servido = false;
	_puntuacion.setPuntaje(0);
	_textoPuntos[0].setString("SCORE");
	
}





Gameplay::~Gameplay()
{
	delete ventana;
	delete _fondo;
}