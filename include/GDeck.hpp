#include "Deck.hpp"
#include "GCard.hpp"
#include <vector>

class GDeck {
private:
    std::vector<GCard> gcards_;

public:
    GDeck(std::vector<GCard> gcards) : gcards_(gcards) {};



};
