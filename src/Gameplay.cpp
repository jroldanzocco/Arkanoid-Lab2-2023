#include "Gameplay.h"

Gameplay::Gameplay(unsigned int x, unsigned int y, std::string nombre)
{
	_ventana = new sf::RenderWindow(sf::VideoMode(x,y), nombre);
	inicializacion();
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

void Gameplay::inicializacion()
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
	_rectVidas.setPosition(630, 100);
	_rectVidas.setTexture(&_txtVidas);
	_rectVidas.setSize({ 117.f, 34.f });
	_texturasVictODerr[0].loadFromFile("resources/images/derrota.png");
	_texturasVictODerr[1].loadFromFile("resources/images/victoria.png");
	_rectVictODerr.setPosition(400, 300);
	_rectVictODerr.setSize({500.f, 300.f});
	_rectVictODerr.setOrigin({ _rectVictODerr.getSize().x / 2.f, _rectVictODerr.getSize().y / 2.f });
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
			reiniciarJuego();
		}
		break;
	case NUEVO_JUEGO:
		if (!_servir) {
			_bola.setPosition({ _paleta.getPosition().x, (_paleta.getPosition().y - _paleta.getSize().y / 2.f - 20.f) });
			_paleta.Update(_bola);
			actualizarPuntos();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				_servir = true;
			}		
		}
		else {
		_paleta.Update(_bola);
		_mapa.Update(_bola);
		_bola.Update();
		actualizarPuntos();
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
		if (_vidas == 0)
		{
			_estado = DERROTA;
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
		//derrota(true);
		break;
	case NIVEL_COMPLETADO:
		break;
	case DERROTA:
		_rectVictODerr.setTexture(&_texturasVictODerr[0]);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			_estado = MENU_PRINCIPAL;
			
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
		_ventana->draw(_paleta.getDraw());
		_ventana->draw(_bola.getDraw());
		_ventana->draw(_rectScore);
		_ventana->draw(_textoPuntos[0]);
		_ventana->draw(_textoPuntos[1]);
		_ventana->draw(_rectVidas);
		break;
	case NIVEL_COMPLETADO:
		break;
	case DERROTA:
		_ventana->draw(_fondo->getDraw());
		_ventana->draw(_rectVictODerr);
		_ventana->draw(_textoDerrota);
		break;
	default:
		break;
	}
}


void Gameplay::actualizarPuntos()
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

void Gameplay::reiniciarJuego()
{
	_mapa.generarNivel(_nivel);
	_rectVidas.setTextureRect(sf::IntRect(0, 0, 795, 230));
	_bola = Bola();
	_paleta = Paleta();
	delete _fondo;
	_fondo = new Background(JUEGO);
	_servir = false;
	_textoPuntos[0].setString("SCORE");
	if(_nivel == 1)
		_puntuacion.setPuntaje(0);
	
}

void Gameplay::gestionarTextos()
{
	_rectScore.setPosition(620, 17);
	_rectScore.setFillColor(sf::Color::Black);
	_rectScore.setSize({ 140, 60 });
	if (!_fuentePuntos.loadFromFile("resources/fonts/pixel.ttf"))
		throw("No se pudo cargar la fuente");
	_textoPuntos[0].setFont(_fuentePuntos);
	_textoPuntos[0].setCharacterSize(24);
	_textoPuntos[0].setFillColor(sf::Color::White);
	_textoPuntos[0].setStyle(sf::Text::Bold);
	_textoPuntos[0].setPosition(630, 18);
	_textoPuntos[1].setFont(_fuentePuntos);
	_textoPuntos[1].setCharacterSize(24);
	_textoPuntos[1].setFillColor(sf::Color::White);
	_textoPuntos[1].setStyle(sf::Text::Bold);
	_textoPuntos[1].setPosition(630, 48);

	if (!_fuenteVenus.loadFromFile("resources/fonts/venus.ttf"))
		throw("No se pudo cargar la fuente");
	_textoDerrota.setFillColor(sf::Color::White);
	_textoDerrota.setStyle(sf::Text::Bold);
	_textoDerrota.setFont(_fuenteVenus);
	_textoDerrota.setCharacterSize(10);
	_textoDerrota.setPosition(220, 385);
	_textoDerrota.setString("Ingresa tu nombre y presiona ENTER");
}

Gameplay::~Gameplay()
{
	delete _ventana;
	delete _fondo;
}