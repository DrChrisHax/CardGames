#ifndef CARD_HPP
#define CARD_HPP

struct card_t
{
    enum class suit_t : unsigned char
    {
        hearts,
        diamonds,
        clubs,
        spades
    };

    enum class rank_t : unsigned char
    {   
        ace     = 1,
        two     = 2,
        three   = 3,
        four    = 4,
        five    = 5,
        six     = 6,
        seven   = 7,
        eight   = 8,
        nine    = 9,
        ten     = 10,
        jack    = 11,
        queen   = 12,
        king    = 13
    };

    rank_t rank = rank_t::ace;
    suit_t suit = suit_t::spades;

    bool operator==(card_t& c)const{ 
        return rank == c.rank && suit == c.suit;
    }
};

#endif