#include "../../src/Deck.h"
#include "../../src/Card.h"
#include "../../src/Player.h"
#include "../../src/Hand.h"
#include <iostream>

#include <random>


int main(){

    Card c1({Suit::DIAMONDS, Suit::SPADES, Suit::HEARTS}, Rank::ACE, {Cmod::Wild});

    c1.show();
    c1.orderGLSuits();
    c1.show();
    c1.orderLGSuits();
    c1.show();
    std::cout << c1.getCardTextureDir() << std::endl;

   return 0;                                                                   
}
