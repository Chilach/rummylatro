#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> // for std::shuffle
#include <random>    // for std::mt19937 and std::random_device (num aleatorios)
#include <SFML/Graphics.hpp>

enum class Suit : uint8_t {SPADES, HEARTS, DIAMONDS, CLUBS, JOKERS};

//clase donde se definen constanstes que se usaran siempre


//los colores en rummy son amarillo, azul, rojo, negro
//Navy = azul + negro
//Wine = red + negro
enum class Cmod {None, Wild, Green, Orange, Brown, Magenta, Navy, Wine};

std::string cmodToString(Cmod c);

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

std::string rankToString(Rank r);
sf::Color suitToColor(Suit s);
sf::Color hexColor(unsigned int hex, uint8_t alpha = 255);
std::string suitToString(Suit s); //funcion helper para convertir enum a string

namespace myColors {
    const sf::Color WHITE = hexColor(0xeeeeee);
    const sf::Color BLACK = hexColor(0x1c1c1c);
    const sf::Color RED = hexColor(0xd70000);
    const sf::Color BLUE = hexColor(0x0087af);
    const sf::Color YELLOW = hexColor(0xffaf00);
    const sf::Color MULTICOLOR = hexColor(0xffc0cb);
    const sf::Color GREEN = hexColor(0x00afaf);
    const sf::Color CREAM = hexColor(0xFFF5E1);
}

class Card{
private:
   std::vector<Suit> suit_;
   Rank rank_;
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
   Card(std::vector<Suit> suit, Rank rank, std::vector<Cmod> modifier={Cmod::None}) : suit_(suit), rank_(rank),  modifier_(modifier) {}

   int numSuits() const {
      return suit_.size();
   }
   
   //directorio de la carta
   std::string getCardTextureDir() const {
      return "assets/cards/card.png";
   }

   std::string getRankTextureDir() const {
      return "assets/rank/" + rankToString(rank_) + ".png";
   }

   std::vector<std::string> getSuitTextureDirs() const {
      std::vector<std::string> suitDirs;
      for (const auto& s : suit_) {
         suitDirs.push_back("assets/suits/" + suitToString(s) + ".png");
      }
      return suitDirs;
   }

   void show() const {
       showCard();
       std::cout << "with modifier: ";
       showMod();
       std::cout << std::endl;
    }

    std::vector<Suit> getSuits() const { return suit_; }
    Rank getRank() const { return rank_; }
    const std::vector<Cmod>& getCmod() const { return modifier_; }

    // setters (mutators)
    void setSuits(const std::vector<Suit>& suits) { suit_ = suits; }
    void setRank(const Rank& r) { rank_ = r; }
    void setModifier(const std::vector<Cmod>& m) { modifier_ = m; }
   //me retorna el suit mas alto
    Suit getFirstSuit() const {
        if (!suit_.empty()) {
            return suit_.front();
        }
        throw std::runtime_error("No suits available");
    }

    void orderGLSuits() {
    std::sort(suit_.begin(), suit_.end(), [](Suit a, Suit b) {
        return static_cast<uint8_t>(a) < static_cast<uint8_t>(b);
    });
    }

    void orderLGSuits() {
    std::sort(suit_.begin(), suit_.end(), [](Suit a, Suit b) {
        return static_cast<uint8_t>(a) > static_cast<uint8_t>(b);
    });
    }

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
   
    //esto arregla in error que no quise entender
    friend void swap(Card& a, Card& b) noexcept {
    using std::swap;
    swap(a.rank_, b.rank_);
    swap(a.suit_, b.suit_);
    //swap(a.cmod_, b.cmod_);
    //swap(a.isJoker_, b.isJoker_);
}
};

//---------------------------------------------------------------
//---------------------------------------------------------------
//estas funciones las debemos acomodar dentro de la clase Card
//---------------------------------------------------------------
//---------------------------------------------------------------

std::vector<sf::Texture> loadSuitTextures(Card& card);
sf::Texture loadCardTexture(Card card);
sf::Texture loadRankTexture(Card card);
