#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "GCard.hpp"
#include "Card.hpp"
#include "Deck.hpp"
#include <iostream>

using namespace sf;

int main() {
    
    //ahora vamos a ver como hacer los Deck y los jugadores


    //NOW WE HAVE TO CREATE THE COMPLETE DECK 
    Deck tabledeck = Deck::createStandardDeck(); 
    //TABLEDECK.showDeck();
    std::cout << "Deck size: " << tabledeck.deckSize() << std::endl;
    Player julian("julian", tabledeck.dealCards(5));
    std::cout << julian.getName() << std::endl;
    julian.showDeck();
    Player ella("ella", tabledeck.dealCards(5));
    std::cout << ella.getName() << std::endl;
    ella.showDeck();

}
