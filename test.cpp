#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include <random>



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

    std::vector<Card> myStandardCards;
    std::vector<Cmod> mod = {Cmod::None};
    
    for (int i = 0; i < 2; ++i){
        for (int value = 1; value <= 13; ++value) {
            myStandardCards.push_back(Card({Suit::Hearts, Suit::Clubs, Suit::Diamonds, Suit::Spades}, static_cast<Rank>(value), mod));
            myStandardCards.push_back(Card({Suit::Diamonds, Suit::Clubs, Suit::Diamonds, Suit::Spades}, static_cast<Rank>(value), mod));
            myStandardCards.push_back(Card({Suit::Clubs, Suit::Clubs, Suit::Diamonds, Suit::Spades}, static_cast<Rank>(value), mod));
            myStandardCards.push_back(Card({Suit::Spades, Suit::Clubs, Suit::Diamonds, Suit::Spades}, static_cast<Rank>(value), mod));
            }
        myStandardCards.push_back(Card({Suit::Jokers}, Rank::JOKER, mod));
        }
    std::cout << "Standard deck size should be 54: " << myStandardCards.size() << std::endl;
    //add this chunck of code to Deck.h
    return 0;
}
