#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> // for std::shuffle
#include <random>    // for std::mt19937 and std::random_device (num aleatorios)
#include <SFML/Graphics.hpp>

sf::Color hexColor(unsigned int hex, uint8_t alpha = 255) {
    return sf::Color(
        (hex >> 16) & 0xFF,  // Red
        (hex >> 8)  & 0xFF,  // Green
        hex & 0xFF,          // Blue
        alpha
    );
}
//vamos a comentar todo el código pa ver que entiendo
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
//clase donde se definen constanstes que se usaran siempre
enum class Suit : uint8_t {SPADES, HEARTS, DIAMONDS, CLUBS, JOKERS};

std::string suitToString(Suit s){ //funcion helper para convertir enum a string
   switch(s){
      case Suit::SPADES: return "SPADES";
      case Suit::HEARTS: return "HEARTS";
      case Suit::DIAMONDS: return "DIAMONDS";
      case Suit::CLUBS: return "CLUBS";
      case Suit::JOKERS: return "JOKERS";
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
      case Rank::ACE: return "A";
      case Rank::TWO: return "2";
      case Rank::THREE: return "3";
      case Rank::FOUR: return "4";
      case Rank::FIVE: return "5";
      case Rank::SIX: return "6";
      case Rank::SEVEN: return "7";
      case Rank::EIGHT: return "8";
      case Rank::NINE: return "9";
      case Rank::TEN: return "10";
      case Rank::JACK: return "JACK";
      case Rank::QUEEN: return "QUEEN";
      case Rank::KING: return "KING";
      case Rank::JOKER: return "JOKER";
      default: return "Unknown";
   }
};

sf::Color suitToColor(Suit s){
   switch(s){
      case Suit::SPADES: return myColors::BLACK;
      case Suit::HEARTS: return myColors::RED;
      case Suit::DIAMONDS: return myColors::YELLOW;
      case Suit::CLUBS: return myColors::BLUE;
      case Suit::JOKERS: return myColors::MULTICOLOR;
      default: return myColors::WHITE;
   }
};



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



sf::Texture loadCardTexture(Card card){
   sf::Texture cardTex;
    if (!cardTex.loadFromFile(card.getCardTextureDir())){
        std::cerr << "Failed to load textures\n";
    }
    return cardTex;
}

sf::Texture loadRankTexture(Card card){
   sf::Texture rankTex;
    if (!rankTex.loadFromFile(card.getRankTextureDir())){
        std::cerr << "Failed to load textures\n";
    }
    return rankTex;
}

std::vector<sf::Texture> loadSuitTextures(Card card){
    std::vector<sf::Texture> suitTextures;
    for (const auto &dir : card.getSuitTextureDirs()){
       sf::Texture suitTex;
        if (!suitTex.loadFromFile(dir)){
            std::cerr << "Failed to load textures\n";
        }
        suitTextures.push_back(suitTex);
    }
    return suitTextures;
}
