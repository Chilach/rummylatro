#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include <random>


int main(){
    //Deck TableDeck = Deck::createStandardDeck();
    //TableDeck.shuffleDeck();

    //std::cout << TableDeck.deckSize() << std::endl;
    //Player p1( "Alice", Deck(TableDeck.dealCards(5)) );
    //p1.showName();
    //p1.showDeck();
    //std::cout << TableDeck.deckSize() << std::endl;
    //std::cout << "--------------------" << std::endl;
    //Player p2( "Bob", Deck(TableDeck.dealCards(5)) );
    //p2.showName();
    //p2.showDeck();

    //std::cout << TableDeck.deckSize() << std::endl;
    //inicializacion de unas cartas para revisar la composicion
    Card c1({Suit::Hearts, Suit::Clubs}, Rank::ACE, {Cmod::Wild});
    c1.show();                                                                  
                                                                                
    return 0;                                                                   
}
