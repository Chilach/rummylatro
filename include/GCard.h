#pragma once

#include "Card.h"

class GCard{
private:
   Card card_;
   float posX_;
   float posY_;

public:
   GCard(Card card, float posX, float posY) : card_(card), posX_(posX),  posY_(posY) {}

   ~GCard();

   //directorio de la carta
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
};
