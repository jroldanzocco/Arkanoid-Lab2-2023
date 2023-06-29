#include "Gameplay.h"

Gameplay::Gameplay(unsigned int x, unsigned int y, std::string nombre)
{
	_ventana = new sf::RenderWindow(sf::VideoMode(x,y), nombre);
	Inicializacion();
	while (_ventana->isOpen())
	{
		while (_ventana->pollEvent(_evento))
		{
			if (_evento.type == sf::Event::Closed || _eleccionMenu == 3) {
				_ventana->close();
				exit(1);
			}
		}
		_ventana->clear();
		Update();
		Draw();
		_ventana->display();
	}

}

void Gameplay::Inicializacion()
{
	_eleccionMenu = -1;
	
	_ventana->setFramerateLimit(60);
	_estado = MENU_PRINCIPAL;
	prBorde.loadFromFile("resources/images/borders.png");
	_fondo = new Background(JUEGO);
	sprborde.setTexture(prBorde);
	sprborde.setPosition(100, 0);
	gestionarTextos();
	_txtVidas.loadFromFile("resources/images/vidas.png");
	_rectVidas.setPosition(650,100);
	_rectVidas.setTexture(&_txtVidas);
	_rectVidas.setSize({117.f, 34.f});
	
}

void Gameplay::Update()
{
	switch (_estado)
	{
	case MENU_PRINCIPAL:
		_eleccionMenu = _menuPrincipal.Update();

		if (_eleccionMenu == 0)
		{
			_nivel = 1;
			_estado = NUEVO_JUEGO;
			_vidas = 3;
			_eleccionMenu = -1;
			ReiniciarJuego();
		}
		break;
	case NUEVO_JUEGO:
		if (!_servir) {
			_bola.setPosition({ paleta.getPosition().x, (paleta.getPosition().y - paleta.getSize().y / 2.f - 20.f) });
			paleta.Update(_bola);
			ActualizarPuntos();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				_servir = true;
			}		
		}
		else {
		paleta.Update(_bola);
		_mapa.Update(_bola);
		_bola.Update();
		ActualizarPuntos();
		if (_bola.getVelocidad().x == 0 && _bola.getVelocidad().y == 0)
		{
			_vidas--;
			_servir = false;
			_bola.setVelocidad({ 0.f, _bola.getSpeed() * -1 });
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			_estado = MENU_PRINCIPAL;
		}
		if (_vidas == 3)
			_rectVidas.setTextureRect(sf::IntRect(0, 0, 795, 230));
		else if(_vidas == 2)
			_rectVidas.setTextureRect(sf::IntRect(265, 0, 795, 230));
		else if (_vidas == 1)
			_rectVidas.setTextureRect(sf::IntRect(530, 0, 795, 230));
		else
			_rectVidas.setTextureRect(sf::IntRect(795, 0, 795, 230));
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
		_menuPrincipal.Draw(*_ventana);
		break;
	case NUEVO_JUEGO:
		_ventana->draw(_fondo->getDraw());
		_ventana->draw(sprborde);
		_mapa.Draw(*_ventana);
		_ventana->draw(paleta.getDraw());
		_ventana->draw(_bola.getDraw());
		_ventana->draw(_textoPuntos[0]);
		_ventana->draw(_textoPuntos[1]);
		_ventana->draw(_rectVidas);
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
	_puntuacion.setPuntaje(_mapa.getBloquesDestruidos() * 50);
	if (_puntuacion.getPuntaje() == 0)
		_textoPuntos[1].setString("00000");
	else if(_puntuacion.getPuntaje() < 10)
		_textoPuntos[1].setString("0000" + std::to_string(_puntuacion.getPuntaje()));
	else if (_puntuacion.getPuntaje() < 100)
		_textoPuntos[1].setString("000" + std::to_string(_puntuacion.getPuntaje()));
	else if (_puntuacion.getPuntaje() < 1000)
		_textoPuntos[1].setString("00" + std::to_string(_puntuacion.getPuntaje()));
	else if (_puntuacion.getPuntaje() < 10000)
		_textoPuntos[1].setString("0" + std::to_string(_puntuacion.getPuntaje()));
	else 
		_textoPuntos[1].setString(std::to_string(_puntuacion.getPuntaje()));
}

void Gameplay::ReiniciarJuego()
{
	_mapa.generarNivel(_nivel);
	_rectVidas.setTextureRect(sf::IntRect(0, 0, 795, 230));
	_bola = Bola();
	paleta = Paleta();
	delete _fondo;
	_fondo = new Background(JUEGO);
	_servir = false;
	_puntuacion.setPuntaje(0);
	_textoPuntos[0].setString("SCORE");
	
}

void Gameplay::gestionarTextos()
{
	if (!_fuentePuntos.loadFromFile("resources/fonts/pixel.ttf"))
		throw("No se pudo cargar la fuente");
	_textoPuntos[0].setFont(_fuentePuntos);
	_textoPuntos[0].setCharacterSize(24);
	_textoPuntos[0].setFillColor(sf::Color::Blue);
	_textoPuntos[0].setStyle(sf::Text::Bold);
	_textoPuntos[0].setPosition(650, 230);
	_textoPuntos[1].setFont(_fuentePuntos);
	_textoPuntos[1].setCharacterSize(24);
	_textoPuntos[1].setFillColor(sf::Color::Red);
	_textoPuntos[1].setStyle(sf::Text::Bold);
	_textoPuntos[1].setPosition(650, 260);
}

Gameplay::~Gameplay()
{
	delete _ventana;
	delete _fondo;
}