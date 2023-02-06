#include "Deck.hpp"
#include <array>

Deck::Deck(Deck::State state) : std::vector<Card>() {
    if(state == Empty) return;

    this->reserve(52);

    this->emplace_back(Card::Spade, 1, "assets/Cards/1.bmp");
    this->emplace_back(Card::Spade, 2, "assets/Cards/2.bmp");
    this->emplace_back(Card::Spade, 3, "assets/Cards/3.bmp");
    this->emplace_back(Card::Spade, 4, "assets/Cards/4.bmp");
    this->emplace_back(Card::Spade, 5, "assets/Cards/5.bmp");
    this->emplace_back(Card::Spade, 6, "assets/Cards/6.bmp");
    this->emplace_back(Card::Spade, 7, "assets/Cards/7.bmp");
    this->emplace_back(Card::Spade, 8, "assets/Cards/8.bmp");
    this->emplace_back(Card::Spade, 9, "assets/Cards/9.bmp");
    this->emplace_back(Card::Spade, 10, "assets/Cards/10.bmp");
    this->emplace_back(Card::Spade, 11, "assets/Cards/11.bmp");
    this->emplace_back(Card::Spade, 12, "assets/Cards/12.bmp");
    this->emplace_back(Card::Spade, 13, "assets/Cards/13.bmp");

    this->emplace_back(Card::Heart, 1, "assets/Cards/14.bmp");
    this->emplace_back(Card::Heart, 2, "assets/Cards/15.bmp");
    this->emplace_back(Card::Heart, 3, "assets/Cards/16.bmp");
    this->emplace_back(Card::Heart, 4, "assets/Cards/17.bmp");
    this->emplace_back(Card::Heart, 5, "assets/Cards/18.bmp");
    this->emplace_back(Card::Heart, 6, "assets/Cards/19.bmp");
    this->emplace_back(Card::Heart, 7, "assets/Cards/20.bmp");
    this->emplace_back(Card::Heart, 8, "assets/Cards/21.bmp");
    this->emplace_back(Card::Heart, 9, "assets/Cards/22.bmp");
    this->emplace_back(Card::Heart, 10, "assets/Cards/23.bmp");
    this->emplace_back(Card::Heart, 11, "assets/Cards/24.bmp");
    this->emplace_back(Card::Heart, 12, "assets/Cards/25.bmp");
    this->emplace_back(Card::Heart, 13, "assets/Cards/26.bmp");

    this->emplace_back(Card::Club, 1, "assets/Cards/27.bmp");
    this->emplace_back(Card::Club, 2, "assets/Cards/28.bmp");
    this->emplace_back(Card::Club, 3, "assets/Cards/29.bmp");
    this->emplace_back(Card::Club, 4, "assets/Cards/30.bmp");
    this->emplace_back(Card::Club, 5, "assets/Cards/31.bmp");
    this->emplace_back(Card::Club, 6, "assets/Cards/32.bmp");
    this->emplace_back(Card::Club, 7, "assets/Cards/33.bmp");
    this->emplace_back(Card::Club, 8, "assets/Cards/34.bmp");
    this->emplace_back(Card::Club, 9, "assets/Cards/35.bmp");
    this->emplace_back(Card::Club, 10, "assets/Cards/36.bmp");
    this->emplace_back(Card::Club, 11, "assets/Cards/37.bmp");
    this->emplace_back(Card::Club, 12, "assets/Cards/38.bmp");
    this->emplace_back(Card::Club, 13, "assets/Cards/39.bmp");

    this->emplace_back(Card::Diamond, 1, "assets/Cards/40.bmp");
    this->emplace_back(Card::Diamond, 2, "assets/Cards/41.bmp");
    this->emplace_back(Card::Diamond, 3, "assets/Cards/42.bmp");
    this->emplace_back(Card::Diamond, 4, "assets/Cards/43.bmp");
    this->emplace_back(Card::Diamond, 5, "assets/Cards/44.bmp");
    this->emplace_back(Card::Diamond, 6, "assets/Cards/45.bmp");
    this->emplace_back(Card::Diamond, 7, "assets/Cards/46.bmp");
    this->emplace_back(Card::Diamond, 8, "assets/Cards/47.bmp");
    this->emplace_back(Card::Diamond, 9, "assets/Cards/48.bmp");
    this->emplace_back(Card::Diamond, 10, "assets/Cards/49.bmp");
    this->emplace_back(Card::Diamond, 11, "assets/Cards/50.bmp");
    this->emplace_back(Card::Diamond, 12, "assets/Cards/51.bmp");
    this->emplace_back(Card::Diamond, 13, "assets/Cards/52.bmp");
}

Deck::Deck(const Deck& a) : std::vector<Card>(a) {
    *this = a;
}

bool Deck::isInDeck(std::array<int, 52> deck, int num, int max) {
    for(int i = 0; i < max; i++) {
        if(deck[i] == num) return true;
    }
    return false;
}

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

Deck& Deck::operator=(const Deck &a) {
    this->clear();
    for(size_t i = 0; i < a.size(); i++)
        this->push_back(a[i]);
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Deck &a) {
    for(size_t i = 0; i < a.size(); i++)
        out << "Card : " << a[i].getSuit() << " | value : " << a[i].getValue() << "\n";
    return out;
}