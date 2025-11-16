#include "Card.h"

sf::Color hexColor(unsigned int hex, uint8_t alpha) {
    return sf::Color(
        (hex >> 16) & 0xFF,  // Red
        (hex >> 8)  & 0xFF,  // Green
        hex & 0xFF,          // Blue
        alpha
    );
}

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

sf::Texture loadCardTexture(Card card){
   sf::Texture cardTex;
    if (!cardTex.loadFromFile(card.getCardTextureDir())){
        std::cerr << "Failed to load textures\n";
    }
    return cardTex;
}

sf::Texture loadRankTexture(Card card){
   sf::Texture rankTex;
    if ( !rankTex.loadFromFile( card.getRankTextureDir() ) ){
        std::cerr << "Failed to load textures\n";
    }
    return rankTex;
}

std::vector<sf::Texture> loadSuitTextures(Card& card){
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
