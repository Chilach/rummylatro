#include "Deck.h"
#include "Card.h"
#include "Player.h"


int main(){
    //creo un deck de prueba con apenas tres cartas
    //---------------------------------------
    std::vector<Suit> suits = {Suit::Hearts, Suit::Diamonds};
    std::vector<Card> myDeck; 
    Card c1({Suit::Hearts, Suit::Clubs}, Rank::ACE, {Cmod::Wild});
    Card c2({Suit::Diamonds, Suit::Clubs}, Rank::ACE, {Cmod::Green, Cmod::Magenta});
    Card c3(suits, Rank::KING, {Cmod::None});
    myDeck.push_back(c1); myDeck.push_back(c2); myDeck.push_back(c3);
    Deck deck(myDeck);
    //---------------------------------------
    //creo un jugador de prueba
    Player p1("Alice", deck);
    //p1.getDeck().shuffleDeck();
    //un ejemplo de uso de todo lo que hemos hecho asta ahora
    p1.showDeck();
    p1.removeSpecificCard(c2);
    std::cout << "After removing a card: " << std::endl;
    p1.showDeck();
    //otra forma de hacerlo
    p1.getDeck().removeSpecificCard(c1);
    std::cout << "After removing a card: " << std::endl;
    p1.showDeck();


//hay que tener en cuenta que quien hace las acciones sobre el deck es el player...
//falta construir la locgica sobre los players
    return 0;
}
