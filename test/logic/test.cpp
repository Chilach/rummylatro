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
    Card c1({Suit::DIAMONDS, Suit::SPADES, Suit::HEARTS}, Rank::ACE, {Cmod::Wild});
    c1.show();
    //std::cout << "directorio del sprite de la carta" << std::endl;
    //std::cout << c1.getCardTextureDir() << std::endl;
    //std::cout << "directorios de los sprites de los palos" << std::endl;
    //for (const auto & dir : c1.getSuitTextureDirs()){
    //    std::cout << dir << std::endl;
    //}
    c1.orderGLSuits();
    c1.show();
    c1.orderLGSuits();
    c1.show();
    //std::cout << c1.cardDirBase;
    //c1.getSuitDirs();
    //for (const auto&mysuit: c1.getSuitDirs()){
    //    std::cout << mysuit <<std::endl;
    //}
    //c1.findRankDir();
    //c1.showRankDir();
    //std::cout << c1.getCardDir();
        
    //c1.populateSuitDir();
    //c1.getSuitDir();
    //for(const auto&mysuit: c1.getSuitDir()){
    //    std::cout << mysuit <<std::endl;
    //}
    return 0;                                                                   
}
