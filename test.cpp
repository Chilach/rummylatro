#include <string>
#include <iostream>
#include <vector>
#include <memory>

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
   Suit suit_;
   Rank rank_;
   std::string modifier_;
   
   void showMod() const{
      if (modifier_ != "")
         std::cout << " " << modifier_;
      else
         std::cout << "none";
   }
   void showCard() const {
      std::cout << suitToString(suit_) << " " << rankToString(rank_) <<std::endl;
   }
public:
   Card(Suit suit, Rank rank, std::string modifier="") : suit_(suit), rank_(rank), modifier_(modifier) {}

  void show() const {
      showCard();
      std::cout << "with modifier: ";
      showMod();
      std::cout << std::endl;
   }

    Suit getSuit() const { return suit_; }
    Rank getRank() const { return rank_; }
    const std::string& getModifier() const { return modifier_; }

    // setters (mutators)
    void setSuit(const Suit& s) { suit_ = s; }
    void setRank(const Rank& r) { rank_ = r; }
    void setModifier(const std::string& m) { modifier_ = m; }
};

int main(){
   std::vector<Card> deck;
   //para generar todo el deck (la bolsa) hay que iterar varias veces.
   for (int r = 1; r <= 13; ++r){
      for (int i = 0; i <=1; ++i){
         deck.emplace_back(Suit::Hearts,   static_cast<Rank>(r));
         deck.emplace_back(Suit::Diamonds, static_cast<Rank>(r));
         deck.emplace_back(Suit::Clubs,    static_cast<Rank>(r));
         deck.emplace_back(Suit::Spades,   static_cast<Rank>(r));
      }
}
   deck.emplace_back(Suit::Jokers, Rank::JOKER);
   deck.emplace_back(Suit::Jokers, Rank::JOKER);
   std::cout << "Deck size: " << deck.size() << std::endl;
   /*ahora que sabemos como se ve el deck podemos convertirlo en un clase para luego definir métodos y atributos de modo que el juego ya puede empezar a tomar forma, hay que investigar un poco sobre patrones de desarrollo o lo que sea, no importa */
}
