#include <string>
#include "newCard.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> // for std::shuffle
#include <random>    // for std::mt19937 and std::random_device (num aleatorios)

//vamos a comentar todo el código pa ver que entiendo

//clase donde se definen constanstes que se usaran siempre
enum class Suit : uint8_t {Hearts, Diamonds, Clubs, Spades, Jokers};

std::string suitToString(Suit s){ //funcion helper para convertir enum a string
   switch(s){
      case Suit::Hearts: return "Hearts";
      case Suit::Diamonds: return "Diamonds";
      case Suit::Clubs: return "Clubs";
      case Suit::Spades: return "Spades";
      case Suit::Jokers: return "Jokers";
      default: return "Unknown";
   }
};
//los colores en rummy son amarillo, azul, rojo, negro
//Navy = azul + negro
//Wine = red + negro
enum class Cmod {None, Wild, Green, Orange, Brown, Magenta, Navy, Wine};

std::string cmodToString(Cmod c){
   switch(c){
      case Cmod::None: return "None";
      case Cmod::Wild: return "Wild";
      case Cmod::Green: return "Green";
      case Cmod::Orange: return "Orange";
      case Cmod::Brown: return "Brown";
      case Cmod::Magenta: return "Magenta";
      case Cmod::Navy: return "Navy";
      case Cmod::Wine: return "Wine";
      default: return "Unknown";
   }
};

enum class Rank {
    ACE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 11,
    QUEEN = 12,
    KING = 13,
    JOKER = 0
};

std::string rankToString(Rank r){
   switch(r){
      case Rank::ACE: return "Ace";
      case Rank::TWO: return "2";
      case Rank::THREE: return "3";
      case Rank::FOUR: return "4";
      case Rank::FIVE: return "5";
      case Rank::SIX: return "6";
      case Rank::SEVEN: return "7";
      case Rank::EIGHT: return "8";
      case Rank::NINE: return "9";
      case Rank::TEN: return "10";
      case Rank::JACK: return "Jack";
      case Rank::QUEEN: return "Queen";
      case Rank::KING: return "King";
      case Rank::JOKER: return "Joker";
      default: return "Unknown";
   }
};

class Card{
private:
   Rank rank_;
   std::vector<Suit> suit_;
   std::vector<Cmod> modifier_;
   
   void showMod() const{
      if (modifier_[0] != Cmod::None)
         //std::cout << " " << modifier_;
         for(const auto&mod : modifier_){
            std::cout << cmodToString(mod) << ", ";
         }
      
      else
         std::cout << cmodToString(Cmod::None);
   }
   void showCard() const {
      std::cout << rankToString(rank_);
      for(int i = 0; i < suit_.size(); ++i){
      std::cout  << " of " << suitToString(suit_[i]) << ", ";
      }
   }
public:
   Card(std::vector<Suit> suit, Rank rank, std::vector<Cmod> modifier={Cmod::None}) : rank_(rank), suit_(suit),  modifier_(modifier) {}

  void show() const {
      showCard();
      std::cout << "with modifier: ";
      showMod();
      std::cout << std::endl;
   }
    std::vector<Suit> getSuit() const { return suit_; }
    Rank getRank() const { return rank_; }
    const std::vector<Cmod>& getModifier() const { return modifier_; }

    // setters (mutators)
    void setSuits(const std::vector<Suit>& suits) { suit_ = suits; }
    void setRank(const Rank& r) { rank_ = r; }
    void setModifier(const std::vector<Cmod>& m) { modifier_ = m; }

    void addSuit(Suit s) { suit_.push_back(s); }

    bool removeSuit(Suit s) {
        auto it = std::find(suit_.begin(), suit_.end(), s);
        if (it != suit_.end()) { suit_.erase(it); return true; }
        return false;
    }
    
    void clearSuits() { suit_.clear(); }
};

class Card_Mod{
private:
   std::string name_;
   std::string description_;
public:
   Card_Mod(std::string name, std::string description) : name_(name), description_(description) {}
   void show() const {
      std::cout << "Modifier: " << name_ << ", Description: " << description_ << std::endl;
   }
   const std::string& getName() const { return name_; }
   const std::string& getDescription() const { return description_; }

   void setName(const std::string& name) { name_ = name; }
   void setDescription(const std::string& description) { description_ = description; }
};


//class Deck{
//private:
//public:
//};
//ahora nos encargamos de hacer un Deck
//este es uno metodo que cambia el valor del deck en la dirección e memoria asignada
void shuffleDeck(std::vector<Card>& deck) {
    std::random_device rd;                      // seed
    std::mt19937 g(rd());                       // random number generator
    std::shuffle(deck.begin(), deck.end(), g);  // shuffle in place
}
//NOTAPERSONAL: hay que ver como hacer que el shuffle sea un metodo de la clase Deck
//este otro metodo crea una copia del deck y la baraja, devolviendo la copia barajada
//

//std::vector<Card> shuffleDeck(std::vector<Card> deck) {
//    // deck is passed by VALUE -> we get a copy of the original
//    // lo siguiente es equivalente a: shuffleDeck(deck);
//    std::random_device rd;          // seed
//    std::mt19937 g(rd());           // random number generator
//
//    std::shuffle(deck.begin(), deck.end(), g);  // shuffle the copy
//
//    return deck; // return the shuffled copy
//}


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
