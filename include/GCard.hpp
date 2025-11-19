#pragma once

#include "Card.hpp"

class GCard{
private:
   Card& card_;
   float scale_;
   float posX_;
   float posY_;

public:
   GCard(Card& card, float scale, float posX, float posY) : card_(card), scale_(scale), posX_(posX),  posY_(posY) {}
   //GCard(Card& card): card_(card) {}

   //~GCard();
   
   //POSITION GETTERS
   float getPosX() { return posX_; }
   float getPosY() { return posY_; }
   float getScale(){ return scale_; }

   //GETTERS FOR GRAPHIC PART OF THE CARD
   std::string getCardTextureDir() const {
      return "assets/cards/card.png";
   }

   std::string getRankTextureDir() const {
      return "assets/rank/" + rankToString(card_.getRank()) + ".png";
   }

   std::vector<std::string> getSuitTextureDirs() const {
      std::vector<std::string> suitDirs;
      for (const auto& s : card_.getSuits()) {
         suitDirs.push_back("assets/suits/" + suitToString(s) + ".png");
      }
      return suitDirs;
   }

   sf::Texture loadCardTexture(){
   sf::Texture cardTex;
    if (!cardTex.loadFromFile(card_.getCardTextureDir())){
        std::cerr << "Failed to load textures\n";
    }
    return cardTex;
}

sf::Texture loadRankTexture(){
   sf::Texture rankTex;
    if ( !rankTex.loadFromFile( card_.getRankTextureDir() ) ){
        std::cerr << "Failed to load textures\n";
    }
    return rankTex;
}

std::vector<sf::Texture> loadSuitTextures(){
    std::vector<sf::Texture> suitTextures;
    for (const auto &dir : card_.getSuitTextureDirs()){
       sf::Texture suitTex;
        if (!suitTex.loadFromFile(dir)){
            std::cerr << "Failed to load textures\n";
        }
        suitTextures.push_back(suitTex);
    }
    return suitTextures;
}
};
