#include "Game.hpp"
#include <map>

std::map<int, Card::Suit> goalPlacementMap = {
    {0, Card::Spade  },
    {1, Card::Heart  },
    {2, Card::Club   },
    {3, Card::Diamond}
};

//void Game::switchSound()

void Game::nextHand() {
    if(mHandIndex == mHand.size() - 1) {
        mHandIndex = npos;
        return;
    }
    mHandIndex++;
    mPtr = nullptr;
}

void Game::selectHand() {
    mPtr = (mPtr || mHand.empty() || mHandIndex == npos) ? nullptr : &mHand;
}

void Game::selectGoal(unsigned int pos) {
    if(!mPtr)
        return;
    if(mPtr == &mHand) {
        if(mHand[mHandIndex].getValue() == mGoal[pos][mGoal[pos].size() - 1].getValue() + 1 && mHand[mHandIndex].getSuit() == goalPlacementMap[pos]) {
            mGoal[pos].push_back(mHand[mHandIndex]);
            mHand.erase(mHand.begin() + mHandIndex);
            if(mHandIndex > 0) 
                mHandIndex--;
            mPtr = nullptr;
            return;
        }
        return;
    }
    else {
        if(mPtr[0].size() - 1 != mSelector) return;
        if(mPtr[0][mSelector].getValue() == mGoal[pos][mGoal[pos].size() - 1].getValue() + 1) {
            if(mPtr[0][mSelector].getSuit() == goalPlacementMap[pos]) {
                mGoal[pos].push_back(mPtr[0][mSelector]);
                mPtr[0].pop_back();
                mPtr = nullptr;
                return;
            }
        }
    }
}

void Game::handToPile(unsigned int x, unsigned int y) {
    if(mHand[mHandIndex].getValue() == mPile[x][y].getValue() - 1 && mHand[mHandIndex].getColor() != mPile[x][y].getColor()) {
        mPile[x].push_back(mHand[mHandIndex]);
        mHand.erase(mHand.begin() + mHandIndex);
        if(mHandIndex > 0)
            mHandIndex--;
    }
    if(y == 0 && mPile[x].empty() && mHand[mHandIndex].getValue() == 13) {
        mPile[x].push_back(mHand[mHandIndex]);
        mHand.erase(mHand.begin() + mHandIndex);
        if(mHandIndex > 0)
            mHandIndex--;
    }
}

void Game::pileToPile(unsigned int x, unsigned int y) {
    if(!mPile[x].empty() && mPile[x].size() - 1 != y)
        return;
    if(mPtr[0][mSelector].getValue() == mPile[x][y].getValue() - 1 && mPtr[0][mSelector].getColor() != mPile[x][y].getColor()) {
        while(mSelector != mPtr[0].size()) {
            mPile[x].push_back(mPtr[0][mSelector]);
            mPtr[0].erase(mPtr[0].begin() + mSelector);
        }
    }
    if(y == 0 && mPile[x].empty() && mPtr[0][mSelector].getValue() == 13) {
        while(mSelector != mPtr[0].size()) {
            mPile[x].push_back(mPtr[0][mSelector]);
            mPtr[0].erase(mPtr[0].begin() + mSelector);
        }
    }
}

void Game::action(unsigned int x, unsigned int y) {
    if(!mPtr) {
        mPtr = &mPile[x];
        mSelector = y;
        return;
    }
    else if(mPtr == &mHand)
        handToPile(x, y);
    else
        pileToPile(x, y);
    mPtr = nullptr;
    mSelector = 0;
}

bool Game::isCardValid(unsigned int x, size_t y) {
    if(mPile[x].size() <= y && !mPtr)
        return false;
    if(mPile[x][y].getStatus())
        return true;
    return false;
}

void Game::selectPile(unsigned int pos, int y) {
    size_t card = 0;
    int i = 0;

    for(i = 350; card < mPile[pos].size(); i+= 40) {
        if(y > i && y < i + 40) {
            if(isCardValid(pos, card)) {
                action(pos, card);
                return;
            }
        }
        card++;
    }
    if(mPile[pos].empty() && y > 350 && y < 540) {
        if(isCardValid(pos, 0)) {
            action(pos, 0);
            return;
        }
    }
    card--;
    i -= 40;
    if( y > i && y < i + 190) {
        if(isCardValid(pos, card)) {
            action(pos, card);
            return;
        }
    }
}

void Game::gameEvent() {
    sf::Event event;
    while(mWindow.pollEvent(event)) {
        if(event.type == sf::Event::Resized) {
            int x = event.size.width;
            int y = event.size.height;
            if(event.size.width < 1400)
                x = 1400;
            if(event.size.height < 900)
                y = 900;
            mWindow.setSize(sf::Vector2u(x, y));
            mBackground.mSprite.setScale(static_cast<float>(x) / 1400, static_cast<float>(y) / 900);
            sf::FloatRect visibleArea(0, 0, x, y);
            mWindow.setView(sf::View(visibleArea));
        }
        if(event.type == sf::Event::Closed)
            mWindow.close();
        else if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            if(clickInRange(event.mouseButton, sf::IntRect(1300, 50, 70, 70)))
                reset();
            else if(clickInRange(event.mouseButton, sf::IntRect(850, 50, 140, 200)))
                selectHand();
            else if(clickInRange(event.mouseButton, sf::IntRect(1010, 50, 140, 200)))
                nextHand();
            else if(clickInRange(event.mouseButton, sf::IntRect(50, 50, 140, 200)))
                selectGoal(0);
            else if(clickInRange(event.mouseButton, sf::IntRect(210, 50, 140, 200)))
                selectGoal(1);
            else if(clickInRange(event.mouseButton, sf::IntRect(370, 50, 140, 200)))
                selectGoal(2);
            else if(clickInRange(event.mouseButton, sf::IntRect(530, 50, 140, 200)))
                selectGoal(3);
            else if(clickInRange(event.mouseButton, sf::IntRect(50, 50, 140, 2000)))
                selectPile(0, event.mouseButton.y);
            else if(clickInRange(event.mouseButton, sf::IntRect(210, 50, 140, 2000)))
                selectPile(1, event.mouseButton.y);
            else if(clickInRange(event.mouseButton, sf::IntRect(370, 50, 140, 2000)))
                selectPile(2, event.mouseButton.y);
            else if(clickInRange(event.mouseButton, sf::IntRect(530, 50, 140, 2000)))
                selectPile(3, event.mouseButton.y);
            else if(clickInRange(event.mouseButton, sf::IntRect(690, 50, 140, 2000)))
                selectPile(4, event.mouseButton.y);
            else if(clickInRange(event.mouseButton, sf::IntRect(850, 50, 140, 2000)))
                selectPile(5, event.mouseButton.y);
            else if(clickInRange(event.mouseButton, sf::IntRect(1010, 50, 140, 2000)))
                selectPile(6, event.mouseButton.y);
            else
                mPtr = nullptr;
        }
    }
}

