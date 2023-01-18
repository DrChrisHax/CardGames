#pragma once

#include "Card.hpp"
#include <vector>
#include <iostream>

class Deck : public std::vector<Card>
{
public:
    enum State {Empty, Full};

    Deck(Deck::State state = Empty);
    Deck(const Deck& a);
    ~Deck() = default;
    void shuffle();

    Deck& operator=(const Deck &a);
private:
    bool isInDeck(std::array<int, 52> deck, int num, int max);
};

std::ostream& operator<<(std::ostream &output, const Deck &a);