#include "Tile.hpp"

Tile::Tile(const std::string &path) {
    setTexture(path);
}

Tile::Tile(const Tile& a) {
    setTexture(a.mPath);
}

Tile& Tile::operator=(const Tile &a) {
    if(&a == this) return *this;
    setTexture(a.mPath);
    return *this;
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mSprite, states);
}

void Tile::setTexture(const std::string &path) {
    if(path.empty()) return;
    mPath = path;
    if(!mTexture.loadFromFile(path)) throw std::exception();
    mTexture.setSmooth(true);
    mSprite.setTexture(mTexture, true);
}

void Tile::setPosition(float x, float y) {
    mSprite.setPosition(x, y);
}