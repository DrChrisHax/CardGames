#include "Gmae.hpp"
#include <map>

std::map<int Card::Suit> goalPlacementMap = {
    {0, Card::Spade  },
    {1, Card::Heart  },
    {2, Card::Club   },
    {3, Card::Diamond}
}