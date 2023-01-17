#include "Deck.hpp"
#include <array>

Deck::Deck(Deck::State state) : std::vector<Card>() {
    if(state == Empty) return;

    this->reserve(52);

    this->emplace_back(Card::Spade, 1, "assets/Cards/1.png");
    this->emplace_back(Card::Spade, 2, "assets/Cards/2.png");
    this->emplace_back(Card::Spade, 3, "assets/Cards/3.png");
    this->emplace_back(Card::Spade, 4, "assets/Cards/4.png");
    this->emplace_back(Card::Spade, 5, "assets/Cards/5.png");
    this->emplace_back(Card::Spade, 6, "assets/Cards/6.png");
    this->emplace_back(Card::Spade, 7, "assets/Cards/7.png");
    this->emplace_back(Card::Spade, 8, "assets/Cards/8.png");
    this->emplace_back(Card::Spade, 9, "assets/Cards/9.png");
    this->emplace_back(Card::Spade, 10, "assets/Cards/10.png");
    this->emplace_back(Card::Spade, 11, "assets/Cards/11.png");
    this->emplace_back(Card::Spade, 12, "assets/Cards/12.png");
    this->emplace_back(Card::Spade, 13, "assets/Cards/13.png");

    this->emplace_back(Card::Heart, 1, "assets/Cards/14.png");
    this->emplace_back(Card::Heart, 2, "assets/Cards/15.png");
    this->emplace_back(Card::Heart, 3, "assets/Cards/16.png");
    this->emplace_back(Card::Heart, 4, "assets/Cards/17.png");
    this->emplace_back(Card::Heart, 5, "assets/Cards/18.png");
    this->emplace_back(Card::Heart, 6, "assets/Cards/19.png");
    this->emplace_back(Card::Heart, 7, "assets/Cards/20.png");
    this->emplace_back(Card::Heart, 8, "assets/Cards/21.png");
    this->emplace_back(Card::Heart, 9, "assets/Cards/22.png");
    this->emplace_back(Card::Heart, 10, "assets/Cards/23.png");
    this->emplace_back(Card::Heart, 11, "assets/Cards/24.png");
    this->emplace_back(Card::Heart, 12, "assets/Cards/25.png");
    this->emplace_back(Card::Heart, 13, "assets/Cards/26.png");

    this->emplace_back(Card::Club, 1, "assets/Cards/27.png");
    this->emplace_back(Card::Club, 2, "assets/Cards/28.png");
    this->emplace_back(Card::Club, 3, "assets/Cards/29.png");
    this->emplace_back(Card::Club, 4, "assets/Cards/30.png");
    this->emplace_back(Card::Club, 5, "assets/Cards/31.png");
    this->emplace_back(Card::Club, 6, "assets/Cards/32.png");
    this->emplace_back(Card::Club, 7, "assets/Cards/33.png");
    this->emplace_back(Card::Club, 8, "assets/Cards/34.png");
    this->emplace_back(Card::Club, 9, "assets/Cards/35.png");
    this->emplace_back(Card::Club, 10, "assets/Cards/36.png");
    this->emplace_back(Card::Club, 11, "assets/Cards/37.png");
    this->emplace_back(Card::Club, 12, "assets/Cards/38.png");
    this->emplace_back(Card::Club, 13, "assets/Cards/39.png");

    this->emplace_back(Card::Diamond, 1, "assets/Cards/40.png");
    this->emplace_back(Card::Diamond, 2, "assets/Cards/41.png");
    this->emplace_back(Card::Diamond, 3, "assets/Cards/42.png");
    this->emplace_back(Card::Diamond, 4, "assets/Cards/43.png");
    this->emplace_back(Card::Diamond, 5, "assets/Cards/44.png");
    this->emplace_back(Card::Diamond, 6, "assets/Cards/45.png");
    this->emplace_back(Card::Diamond, 7, "assets/Cards/46.png");
    this->emplace_back(Card::Diamond, 8, "assets/Cards/47.png");
    this->emplace_back(Card::Diamond, 9, "assets/Cards/48.png");
    this->emplace_back(Card::Diamond, 10, "assets/Cards/49.png");
    this->emplace_back(Card::Diamond, 11, "assets/Cards/50.png");
    this->emplace_back(Card::Diamond, 12, "assets/Cards/51.png");
    this->emplace_back(Card::Diamond, 13, "assets/Cards/52.png");
}

Deck::Dec(const Deck& a) : std::vector<Card>(a) {
    *this = a;
}

bool Deck::isInDeck(std::array<int, 52> deck, int num, int max) {
    for(int i = 0; i < max; i++) {
        if(deck[i] == num) return true;
    }
    return false;
}

//TODO Implement Fisher-Yates Shuffle
void Deck::shuffle() {
    Deck temp;
    srand(time(NULL));
    int num = 0;
    int i = 0;
    std::array<int, 52> deck;
    while(i != 52) {
        num = (rand() % 52);
        if(!isInDeck(deck, num, i)) {
            deck[i] = num;
            i++;
        }
    }
    for(i = 0; i < 52; i++) {
        temp.push_back(this->at(deck[i]));
    }
    *this = temp;
}

Deck& Deck::Operator=(const Deck &a) {
    this->clear();
    for(size_t i = 0; i < a.size(); i++)
        this->push_back(a[i]);
    return this;
}