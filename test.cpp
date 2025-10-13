#include <string>
#include "Card.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> 
#include <random>    

class Deck {
private:
    std::vector<Card> cards_;

public:
    Deck(std::vector<Card> cards) : cards_(cards) {}

    void showDeck() const {
        for (const auto& card : cards_) {
            card.show();
        }
    }

    void shuffleDeck() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(cards_.begin(), cards_.end(), g);
    }

    //seters
    void addCard(const Card& card) {
        cards_.push_back(card);
    }

    void removeCard(int index) {
        if (index >= 0 && index < cards_.size()) {
            cards_.erase(cards_.begin() + index);
        }
    }

    //add a fuction to remove specifically a card lets say an ace of spades
    //void removeSpecificCard(const Card& card) {
    //    auto it = std::find_if(cards_.begin(), cards_.end(), [&card](const Card& c) {
    //        return c.getRank() == card.getRank() && c.getSuit() == card.getSuit() && c.getCmod() == card.getCmod();
    //    });
    //    if (it != cards_.end()) {
    //        cards_.erase(it);
    //    }
    //}

    int deckSize() const {
        return cards_.size();
    }

    int deckNorm() const {
        int norm = 0;
        for (const auto& card : cards_) {
            norm += card.getNorm();
        }
        return norm;
    }
};

int main(){
    std::vector<Suit> suits = {Suit::Hearts, Suit::Diamonds};
    std::vector<Card> myDeck; 
    Card c1({Suit::Hearts, Suit::Clubs}, Rank::ACE, {Cmod::Wild});
    Card c2({Suit::Diamonds, Suit::Clubs}, Rank::ACE, {Cmod::Green, Cmod::Magenta});
    Card c3(suits, Rank::KING, {Cmod::None});
    myDeck.push_back(c1); myDeck.push_back(c2); myDeck.push_back(c3);
    Deck deck(myDeck);
    std::cout << "Deck inicial:" << std::endl;
    deck.showDeck();
    deck.shuffleDeck();
    //falta agregar una función para eliminar una carta específica
    //myDeck.removeSpecificCard(c2);
    //eliminar una carta
    std::cout << "Deck despues de barajar:" << std::endl;
    //deck.removeCard(1);
    //std::cout << "Deck despues de remover la segunda carta:" << std::endl;
    //deck.showDeck();


//hay que tener en cuenta que quien hace las acciones sobre el deck es el player...
//falta construir la locgica sobre los players
    return 0;
}

//int main(){
//   std::vector<Suit> suits = {Suit::Hearts, Suit::Diamonds};
//   std::vector<Card> Deck; 
//   Card c1({Suit::Hearts, Suit::Clubs}, Rank::ACE, {Cmod::Wild});
//   Card c2({Suit::Diamonds, Suit::Clubs}, Rank::ACE, {Cmod::Green, Cmod::Magenta});
//   Deck.push_back(c1); Deck.push_back(c2);
//   for (const auto& card : Deck) {
//      card.show();
//   }
//   Deck[0].addSuit(Suit::Spades);
//   std::cout << "modificacion de la primera carta" << std::endl;
//   Deck[0].show();
//}
