#include <SFML/Graphics.hpp>
#include <iostream>
#include "src/Gameplay.h"
#include "src/CajaDeTexto.h"
int main()
{
    //Gameplay();

    CajaDeTexto cajaTexto(true);
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "prueba");
   
    sf::Font fuenteTexto;
    if (!fuenteTexto.loadFromFile("resources/fonts/venus.ttf"))
        throw "ERROR";
    cajaTexto.setFuente(fuenteTexto);
    cajaTexto.setPosition({ 400,300 });
    while (ventana.isOpen())
    {
        sf::Event evento;
    while (ventana.pollEvent(evento))
    {
       
        switch (evento.type)
        {
        case sf::Event::Closed:
            ventana.close(); 
        case sf::Event::TextEntered:
            cajaTexto.escribir(evento);
            std::cout << (char)evento.text.unicode << std::endl;
        }
    }
        
        ventana.clear();
        ventana.draw(cajaTexto.getDraw());
        ventana.display();
    
    }

    return 0;
}