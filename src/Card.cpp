#include "Card.hpp"

Card::Card(Card::Suit suit, int value, const std::string &pathToTexture) : Tile(pathToTexture) {
    mColor = (suit == Heart || suit == Diamond) ? Red : Black;
    mSuit = suit;
    mValue = value;
}

Card::Card(const Card& a) : Tile(a.mPath) {
    mColor = a.mColor;
    mSuit = a.mSuit;
    mValue = a.mValue;
    mStatus = a.mStatus;
}

Card& Card::operator=(const Card &a) {
    if(&a == this) return *this;
    mColor = a.mColor;
    mSuit = a.mSuit;
    mValue = a.mValue;
    mStatus = a.mStatus;
    setTexture(a.mPath);
    return *this;
}

bool Card::operator==(const Card &a) const {
    return mValue == a.mValue;
}

bool Card::operator!=(const Card &a) const {
    return !(*this == a);
}
