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
	Background(IMG_BACK imagen);

	sf::Sprite getDraw();

	~Background();
};

