#include <string>
#include "newCard.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> // for std::shuffle
#include <random>    // for std::mt19937 and std::random_device (num aleatorios)

int main(){
   std::vector<Suit> suits = {Suit::Hearts, Suit::Diamonds};
   std::vector<Card> Deck; 
   Card c1({Suit::Hearts, Suit::Clubs}, Rank::ACE, {Cmod::Wild});
   Card c2({Suit::Diamonds, Suit::Clubs}, Rank::ACE, {Cmod::Green, Cmod::Magenta});
   Deck.push_back(c1); Deck.push_back(c2);
   for (const auto& card : Deck) {
      card.show();
   }
   Deck[0].addSuit(Suit::Spades);
   std::cout << "modificacion de la primera carta" << std::endl;
   Deck[0].show();
}
