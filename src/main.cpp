//Chris Manlove 
#include <SFML/Graphics.hpp>
#include "card.hpp"

int main() {

    //Creates the Render Window
    //width, height, bitsPerPixel = 32
    //Title
    //Full Screen

    
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Card Games", sf::Style::Fullscreen);
    
    //Gets window dimensions
    //sf::Vector2u windowSize = window.getSize();
    //unsigned int windowX = windowSize.x;
    //unsigned int windowY = windowSize.y;

    //Runs program while window is open
    while (window.isOpen()) {

        //Checks events
        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::KeyPressed)
                window.close();
        }
    }




    return 0;
}