#pragma once

#include "Deck.hpp"
#include "Tile.hpp"
#include <array>

class Game
{
public:
    Game();
    ~Game() = default;
    Game(const Game&) = delete;
    Game &operator=(const Game&) = delete;
    static bool clickInRange(sf::Event::MouseButtonEvent event, sf::IntRect rect);
    void reset();
    void gameEvent();
    void draw();
    void showLastCards();
    int start();

    void nextHand();

    void selectHand();
    void selectGoal(unsigned int pos);
    void selectPile(unsigned int pos, int y);

    bool isCardValid(unsigned int y, size_t x);
    
    void action(unsigned int x, unsigned int y);

    void handToPile(unsigned int x, unsigned int y);
    void pileToPile(unsigned int x, unsigned int y);

    bool isGameWon();

    static constexpr size_t npos = -1;
private:
    sf::RenderWindow mWindow;
    sf::Image mAppIcon;

    Tile mBackground;
    Tile mVoidCard;
    Tile mCardBack;
    Tile mSelectorUp;
    Tile mSelectorDown;
    Tile mRefreshIcon;
    Tile mWin;

    Deck mHand;
    std::vector<Deck> mPile;
    std::array<Deck, 4> mGoal;
    std::array<Tile, 4> mGoalPattern;

    Deck* mPtr;
    size_t mSelector;
    size_t mHandIndex;
};