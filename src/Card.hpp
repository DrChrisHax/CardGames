#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Tile.hpp"

class Card : public Tile
{
public:
    enum Color {Red, Black};
    enum Suit {Spade, Heart, Club, Diamond};

    Card(Card::Suit suit, int value, const std::string &pathToTexture);
    Card(const Card& a);
    ~Card() override = default;

    Card::Color getColor() const {return mColor;};
    Card::Suit getSuit() const {return mSuit;};
    int getValue() const {return mValue;};
    bool getStatus() const {return mStatus;};

    void setColor(Card::Color color) {mColor = color;};
    void setSuit(Card::Suit suit) {mSuit = suit;};
    void setValue(int value) {mValue = value;};
    void setStatus(bool status) {mStatus = status;};

    Card& operator=(const Card &a);
    bool operator==(const Card &a) const;
    bool operator!=(const Card &a) const;
private:
    Card::Color mColor;
    Card::Suit mSuit;
    int mValue;
    bool mStatus = false;
};