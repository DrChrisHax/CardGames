#include <SFML/Window.hpp>
#include "Tile.hpp"
#include "Card.hpp"
#include "Deck.hpp"
#include "Game.hpp"

int main(int argc, char **argv) {
    try {
        Game game;
        return game.start();
    }
    catch(...) {
        return 255;
    }
}