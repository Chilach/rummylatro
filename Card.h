#pragma once

#include <string>
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
    const std::vector<Cmod>& getCmod() const { return modifier_; }

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

    int getNorm() const {
        if (rank_ == Rank::JOKER) return 0;
        if (rank_ == Rank::ACE) return 1;
        if (rank_ == Rank::JACK) return 10;
        if (rank_ == Rank::QUEEN) return 10;
        if (rank_ == Rank::KING) return 10;
        return static_cast<int>(rank_);
    }

    std::string rank(){
      switch(rank_){
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

};
