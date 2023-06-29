#include "Menu.h"


Menu::Menu()
{
	_txtLogo.loadFromFile("resources/images/menu/logo.png");
	_rectLogo.setTexture(&_txtLogo);
	_rectLogo.setPosition(200, 100);
	_rectLogo.setSize({ 400, 100 });
	_archPuntaje = new ArchivoPuntajes("leaderboard.dat");
	_estado = PRINCIPAL;
	_fondo = new Background(MENU);
	_botonSeleccionado = 0;
	_segundoBoton = 1;
	_tercerBoton = 2;
	_cuartoBoton = 3;
	_txtBotonGrande = new sf::Texture[4];
	_txtBotonChico = new sf::Texture[4];

	_txtBotonGrande[0].loadFromFile("resources/images/menu/play160.png");
	_txtBotonGrande[1].loadFromFile("resources/images/menu/puntos160.png");
	_txtBotonGrande[2].loadFromFile("resources/images/menu/about160.png");
	_txtBotonGrande[3].loadFromFile("resources/images/menu/salir160.png");


	_txtBotonChico[0].loadFromFile("resources/images/menu/play80.png");
	_txtBotonChico[1].loadFromFile("resources/images/menu/puntos80.png");
	_txtBotonChico[2].loadFromFile("resources/images/menu/about80.png");
	_txtBotonChico[3].loadFromFile("resources/images/menu/salir80.png");
	
	_botonFlecha[0].loadFromFile("resources/images/menu/flechaIzq.png");
	_botonFlecha[1].loadFromFile("resources/images/menu/flechaDer.png");

	_rectFlechas[0].setTexture(&_botonFlecha[0]);
	_rectFlechas[0].setPosition(200.f, 450.f);
	_rectFlechas[0].setSize({ 100, 100 });

	_rectFlechas[1].setTexture(&_botonFlecha[1]);
	_rectFlechas[1].setPosition(500.f, 450.f);
	_rectFlechas[1].setSize({ 100, 100 });

	_textoClasif[0].setFont(_fuenteVenus);
	_textoClasif[0].setPosition(150,90);
	_textoClasif[0].setCharacterSize(24);
	_textoClasif[0].setFillColor(sf::Color::Black);
	_textoClasif[0].setString("Nombre");
	_textoClasif[1].setFont(_fuenteVenus);
	_textoClasif[1].setPosition(400, 90);
	_textoClasif[1].setCharacterSize(24);
	_textoClasif[1].setFillColor(sf::Color::Black);
	_textoClasif[1].setString("Puntos");


	_rectBotones = new sf::RectangleShape[4];

	_txtTablaPos.loadFromFile("resources/images/menu/tabla.png");
	_rectTablaPos.setTexture(&_txtTablaPos);
	_rectTablaPos.setPosition(100, 50);
	_rectTablaPos.setOrigin(_rectTablaPos.getSize().x / 2.f, _rectTablaPos.getSize().y / 2.f);
	_rectTablaPos.setSize({ 600,500 });

	if (!_fuenteVenus.loadFromFile("resources/fonts/venus.ttf"))
		throw("No se pudo cargar la fuente");
	int posY = 120;
	for (int i = 0; i < 10; i++)
	{
		posiciones[i].setFont(_fuenteVenus);
		posiciones[i].setCharacterSize(21);
		posiciones[i].setFillColor(sf::Color::Black);
		posiciones[i].setStyle(sf::Text::Bold);
		posiciones[i].setPosition(150, posY);
		posY+= 40;
	}

	textoClasificacion.setFont(_fuenteVenus);

	_rectBotones[0].setTexture(&_txtBotonGrande[0]);
	_rectBotones[0].setSize({ 160, 160 });
	_rectBotones[0].setOrigin(_rectBotones[0].getSize().x / 2, _rectBotones[0].getSize().y / 2);
	_rectBotones[0].setPosition(400, 500);

	_rectBotones[1].setTexture(&_txtBotonChico[1]);
	_rectBotones[1].setSize({ 80, 80 });
	_rectBotones[1].setOrigin(_rectBotones[1].getSize().x / 2, _rectBotones[1].getSize().y / 2);
	_rectBotones[1].setPosition(250, 400);
	_rectBotones[1].setFillColor(sf::Color(255, 255, 255, 180));

	_rectBotones[2].setTexture(&_txtBotonChico[2]);
	_rectBotones[2].setSize({ 80, 80 });
	_rectBotones[2].setOrigin(_rectBotones[2].getSize().x / 2, _rectBotones[2].getSize().y / 2);
	_rectBotones[2].setPosition(400, 300);
	_rectBotones[2].setFillColor(sf::Color(255, 255, 255, 180));

	_rectBotones[3].setTexture(&_txtBotonChico[3]);
	_rectBotones[3].setSize({ 80, 80 });
	_rectBotones[3].setOrigin(_rectBotones[3].getSize().x / 2, _rectBotones[3].getSize().y / 2);
	_rectBotones[3].setPosition(550, 400);
	_rectBotones[3].setFillColor(sf::Color(255, 255, 255, 180));
}

int Menu::Update()
{
	switch (_estado)
	{
	case PRINCIPAL:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && _reloj.getElapsedTime().asMilliseconds() >= 300)
		{
			_botonSeleccionado--;
			_segundoBoton--;
			_tercerBoton--;
			_cuartoBoton--;
			if (_botonSeleccionado < 0)
			{
				_botonSeleccionado = 3;
			}
			if (_segundoBoton < 0)
			{
				_segundoBoton = 3;
			}
			if (_tercerBoton < 0)
			{
				_tercerBoton = 3;
			}
			if (_cuartoBoton < 0)
			{
				_cuartoBoton = 3;
			}

			_rectBotones[0].setTexture(&_txtBotonGrande[_botonSeleccionado]);
			_rectBotones[1].setTexture(&_txtBotonChico[_segundoBoton]);
			_rectBotones[2].setTexture(&_txtBotonChico[_tercerBoton]);
			_rectBotones[3].setTexture(&_txtBotonChico[_cuartoBoton]);
			_reloj.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && _reloj.getElapsedTime().asMilliseconds() >= 300)
		{
			_botonSeleccionado++;
			_segundoBoton++;
			_tercerBoton++;
			_cuartoBoton++;
			if (_botonSeleccionado > 3)
			{
				_botonSeleccionado = 0;
			}
			if (_segundoBoton > 3)
			{
				_segundoBoton = 0;
			}
			if (_tercerBoton > 3)
			{
				_tercerBoton = 0;
			}
			if (_cuartoBoton > 3)
			{
				_cuartoBoton = 0;
			}

			_rectBotones[0].setTexture(&_txtBotonGrande[_botonSeleccionado]);
			_rectBotones[1].setTexture(&_txtBotonChico[_segundoBoton]);
			_rectBotones[2].setTexture(&_txtBotonChico[_tercerBoton]);
			_rectBotones[3].setTexture(&_txtBotonChico[_cuartoBoton]);
			_reloj.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			switch (_botonSeleccionado)
			{
			case 0:
				return _botonSeleccionado;
				break;
			case 1:
				_estado = MEJOR_PUNTUACION;
				break;
			case 2:
				break;
			case 3:
				return 3;
				break;
			default:
				return -1;
				break;
			}
		}
		break;
	case MEJOR_PUNTUACION:
		
		generartablaPos();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			_estado = PRINCIPAL;
		}
		break;
	case CREDITOS:
		break;
	default:
		break;
	}
	return -1;
}

void Menu::Draw(sf::RenderWindow& ventana)
{
	
	ventana.draw(_fondo->getDraw());
	ventana.draw(_rectLogo);
	switch (_estado)
	{
	case PRINCIPAL:
		ventana.draw(_rectBotones[0]);
		ventana.draw(_rectBotones[1]);
		ventana.draw(_rectBotones[2]);
		ventana.draw(_rectBotones[3]);
		ventana.draw(_rectFlechas[0]);
		ventana.draw(_rectFlechas[1]);
		break;
	case MEJOR_PUNTUACION:
		ventana.draw(_rectTablaPos);
		ventana.draw(_textoClasif[0]);
		ventana.draw(_textoClasif[1]);
		for (int i = 0; i < 10; i++)
		{
			ventana.draw(posiciones[i]);
		}
		break;
	case CREDITOS:
		break;
	default:
		break;
	}
}

Menu::~Menu()
{
	delete _fondo;
	delete[] _txtBotonChico;
	delete[] _txtBotonGrande;
	delete[] _rectBotones;
}