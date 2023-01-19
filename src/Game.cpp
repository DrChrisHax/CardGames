#include "Game.hpp"

Game::Game() : mHand(Deck::Full), mPtr(nullptr), mSelector(0), mHandIndex(npos) {
    mWindow.create(sf::VideoMode(1400, 900), "Solitaire");
    mWindow.setFramerateLimit(60);
    mWindow.setKeyRepeatEnabled(false);

    //TODO
    //mAppIcon.loadFromFile("PATH");
    //mWindow.setIcon(mAppIcon.getSize().x, mApIcon.getSize().y, mAppIcon.getPixelsPtr());

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    mWindow.setPosition(sf::Vector2i(desktop.width / 2 - mWindow.getSize().x/2, desktop.height/2 - mWindow.getSize().y/2));

    mBackground.setTexture("assets/background.jpeg");
    mVoidCard.setTexture("assets/noCard.bmp");
    mGoalPattern[0].setTexture("assets/Cards/goalSpades.bmp");
    mGoalPattern[1].setTexture("assets/Cards/goalHearts.bmp");
    mGoalPattern[2].setTexture("assets/Cards/goalClubs.bmp");
    mGoalPattern[3].setTexture("assets/Cards/goalDiamonds.bmp");
    mCardBack.setTexture("assets/Cards/cardBack.bmp");
    mSelectorUp.setTexture("assets/selectorUp.bmp");
    mSelectorDown.setTexture("assets/selectorDown.bmp");
    mRefreshIcon.setTexture("assets/refresh.bmp");

    //win image needed

    this->reset();
}

int Game::start() {
    while(mWindow.isOpen()) {
        gameEvent();
        this->showLastCards();
        mWindow.clear(sf::Color::Black);
        this->draw();
        mWindow.display();
    }
    return 0;
}

bool Game::isGameWon() {
    for(int i = 0; i < 4; i++) {
        if(mGoal[i][mGoal[i].size() - 1].getValue() != 13)
            return false;
    }
    return true;
}

void Game::draw() {
    float rectX = 50.0f;
    float rectY = 50.0f;

    mWindow.draw(mBackground);

    for(int i = 0; i < 4; i++) {
        mGoalPattern[i].setPosition(rectX, rectY);
        mWindow.draw(mGoalPmPile[i][j].setPosition(rectX, rectY);attern[i]);
        mGoal[i][mGoal[i].size() - 1].setPosition(rectX, rectY);
        mWindow.draw(mGoal[i][mGoal[i].size() - 1]);
        rectX += 160; 
    }
    rectX += 160;
    if(!mHand.empty() && mHandIndex != npos) {
        mHand[mHandIndex].setPosition(rectX, rectY);
        mWindow.draw(mHand[mHandIndex]);
    }
    rectX += 160;
    mVoidCard.setPosition(rectX, rectY);
    mWindow.draw(mVoidCard);
    if(!mHand.empty()) {
        if(mHandIndex < mHand.size() - 1 || mHandIndex == npos) {
            mCardBack.setPosition(rectX, rectY);
            mWindow.draw(mCardBack);
        }
    }
    rectX = 50;
    rectY = 350;
    for(int i = 0; i < 7; i++) {
        mVoidCard.setPosition(rectX, rectY);
        mWindow.draw(mVoidCard);
        for(size_t j = 0; j < mPile[i].size(); j++) {
            if(mPile[i][j].getStatus()) {mPile[i][j].setPosition(rectX, rectY);
                mPile[i][j].setPosition(rectX, rectY);
                mWindow.draw(mPile[i][j]);
            }
            else {
                mCardBack.setPosition(rectX, rectY);
                mWindow.draw(mCardBack);
            }
            rectY += 40;
        }
        rectX += 160;
        rectY = 350;
    }
    if(mPtr == nullptr) {}
    else if(mPtr == &mHand) {
        rectX = 850;
        rectY = 50;
        mSelectorUp.setPosition(rectX, rectY);
        mWindow.draw(mSelectorUp);
        rectY += 160;
        mSelectorDown.setPosition(rectX, rectY);
        mWindow.draw(mSelectorDown);
    }
    else {
        int i = 0;
        for(i = 0; i < 7; i++) {
            if(&mPile[i] == mPtr)
                break;
        }
        rectX = 50 + (160 * i);
        rectY = 350 + (40 * mSelector);
        mSelectorUp.setPosition(rectX, rectY);
        mWindow.draw(mSelectorUp);
        rectY += 160 + (40 * (mPtr[0].size() - (mSelector + 1)));
        mSelectorDown.setPosition(rectX, rectY);
        mWindow.draw(mSelectorDown);
    }
    if(isGameWon()) {
        mWin.setPosition(350, 350);
        mWindow.draw(mWin);
    }

    rectX = 1350;
    rectY = 50;
    mRefreshIcon.setPosition(rectX, rectY);
    mWindow.draw(mRefreshIcon);
}

void Game::reset() {
    mPtr = nullptr;
    mSelector = 0;
    mHandIndex = npos;
    Deck temp(Deck::Full);
    mHand = temp;

    mHand.shuffle();

    mPile.clear();
    mGoal[0].clear();
    mGoal[1].clear();
    mGoal[2].clear();
    mGoal[3].clear();

    int max = 1;
    
    for(int i = 0; i < 7; i++, max++) {
        mPile.emplace_back(Deck::Empty);
        for(int j = 0; j < max; j++){
            mPile[i].push_back(mHand[mHand.size() - 1]);
            mHand.pop_back();
        }
        mPile[i][mPile[i].size() - 1].setStatus(true);
    }
    mGoal[0].emplace_back(Card::Spade, 0, "assets/noCard.bmp");
    mGoal[1].emplace_back(Card::Heart, 0, "assets/noCard.bmp");
    mGoal[2].emplace_back(Card::Club, 0, "assets/noCard.bmp");
    mGoal[3].emplace_back(Card::Diamond, 0, "assets/noCard.bmp");
}

bool Game::clickInRange(sf::Event::MouseButtonEvent event, sf::IntRect rect) {
    return rect.contains(event.x, event.y);
}

void Game::showLastCards() {
    for(auto &deck : mPile) {
        if(!deck.empty()) {
            deck[deck.size() - 1].setStatus(true);
        }
    }
}


