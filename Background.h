#pragma once
#include <SFML/Graphics.hpp>
#include <string>
enum IMG_BACK
{
	MENU,
	JUEGO
};

class Background
{
private:
	sf::Texture * _txtbackGround;
	sf::Sprite *_sprBackGround;
	IMG_BACK _imagen;

public:
	Background(IMG_BACK imagen)
	{
		_imagen = imagen;
		_txtbackGround = new sf::Texture[2];
		_txtbackGround[0].loadFromFile("resources/images/bg.png");
		_txtbackGround[1].loadFromFile("resources/images/bg2.jpg");
		_sprBackGround = new sf::Sprite[2];
		_sprBackGround[0].setTexture(_txtbackGround[0]);
		_sprBackGround[1].setTexture(_txtbackGround[1]);
	}

	sf::Sprite getDraw()
	{
		switch (_imagen)
		{
		case MENU:
			return _sprBackGround[0];
			break;
		case JUEGO:
			return _sprBackGround[1];
			break;
		default:
			return _sprBackGround[1];
			break;
		}
	}
	~Background()
	{
		delete[] _txtbackGround;
		delete[] _sprBackGround;
	}
};

