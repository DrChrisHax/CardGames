#include <SFML/Window.hpp>
#include "Tile.hpp"
#include "Card.hpp"
#include "Deck.hpp"
#include "Game.hpp"

int main(int argc, char **argv) {
    sf::Window window(sf::VideoMode(800, 600), "Solitaire");

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;  
}