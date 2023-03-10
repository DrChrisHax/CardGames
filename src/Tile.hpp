#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Tile : public sf::Drawable
{
public:
    Tile() = default;
    explicit Tile(const std::string &path);
    Tile(const Tile& a);
    ~Tile() override = default;
    Tile& operator=(const Tile &a);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void setTexture(const std::string &path);
    void setPosition(float x, float y);
    sf::Texture mTexture;
    sf::Sprite mSprite;
    std::string mPath;
};