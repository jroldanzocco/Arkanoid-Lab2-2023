#pragma once
#include <iostream>
#include "Bloque.h"
#include "Bola.h"
class GeneradorDeMapas
{
private:
	sf::Texture* _txtBloques;
	std::vector<int> _mapa;
	std::vector<Bloque> _bloques;
	//Bloque* _bloques;
	const int _tamMapa = 160;;
	int _bloquesDestruidos;

	bool intersectan(Bola& bola, Bloque& bloque);

public:
	GeneradorDeMapas();

	void generarNivel(int nivel);

	

	void Update(Bola& bola);


	void Draw(sf::RenderWindow& ventana);

	

	void Colision(Bola& bola, Bloque& bloque);
	
	~GeneradorDeMapas();
};

