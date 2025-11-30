#pragma once

#include "Card.hpp"

class GCard{
private:
   Card& card_;
   float scale_;
   float posX_;
   float posY_;

   // These persist as long as the GCard object exists
   sf::Texture cardTexture_;
   sf::Texture rankTexture_;
   std::vector<sf::Texture> suitTextures_;

public:
   GCard(Card& card, float scale, float posX, float posY) : card_(card), scale_(scale), posX_(posX),  posY_(posY) {

      loadAllTextures();
   }
   //GCard(Card& card): card_(card) {}

   //~GCard();
   //LOAD ALL THE TEXTURES
   void loadAllTextures() {
       // Load card texture
       if (!cardTexture_.loadFromFile(getCardTextureDir())) {
           std::cerr << "❌ Failed to load card texture\n";
       } else {
           std::cout << "✅ Card texture loaded\n";
       }
       
       // Load rank texture
       if (!rankTexture_.loadFromFile(getRankTextureDir())) {
           std::cerr << "❌ Failed to load rank texture\n";
       } else {
           std::cout << "✅ Rank texture loaded\n";
       }
       
       // Load suit textures
       for (const auto &dir : getSuitTextureDirs()) {
           sf::Texture suitTex;
           if (!suitTex.loadFromFile(dir)) {
               std::cerr << "❌ Failed to load suit texture: " << dir << "\n";
           } else {
               std::cout << "✅ Suit texture loaded: " << dir << "\n";
           }
           suitTextures_.push_back(suitTex);
       }
   }

   float getCardTextureSizeX() const {
      return  cardTexture_.getSize().x;
   }

   float getCardTextureSizeY() const{
      return cardTexture_.getSize().y;
   }

sf::Sprite getCardSprite() {
   sf::Sprite sprite(cardTexture_);  // Use member texture (stays alive)
   sprite.setScale(scale_, scale_);
   sprite.setPosition(posX_, posY_);
   return sprite;
   }

sf:: Sprite getRankSprite(){
   sf::Sprite sprite(rankTexture_);
   sprite.setScale(scale_,scale_);
   sprite.setPosition(posX_ + 20.f, posY_ + 20.f);
   sprite.setColor(suitToColor(card_.getFirstSuit()));
   return sprite;
}
   
   //POSITION GETTERS
   float& getPosX() { return posX_; }
   float& getPosY() { return posY_; }
   float& getScale(){ return scale_; }

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
        std::cerr << "❌ Failed to load card texture from: " << card_.getCardTextureDir() << std::endl;
    } else {
        std::cout << "✅ Successfully loaded card texture\n";
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
   //
   //cardSprite.setScale(myscale, myscale);
   //cardSprite.setPosition(gCard.getPosX(), gCard.getPosY()); // optional: place the baked card origin
   //
   //cardSprite.setColor(suitToColor(card.getFirstSuit()));
   //
//sf::Sprite cardSprite(sf::Texture cardTex){
//   //sf::Texture cardTex = loadCardTexture();
//   sf::Sprite cardSprite(cardTex);
//   cardSprite.setScale(scale_, scale_);
//   cardSprite.setPosition(posX_, posY_);
//   return cardSprite;
//}
//sf::Sprite loadCardSprite(sf::Texture cardTex){
//sf::Sprite loadCardSprite(){ 
//   sf::Texture cardTex = loadCardTexture();
//   //unsigned int width  = cardTex.getSize().x * scale_;//*8u
//   //unsigned int height = cardTex.getSize().y * scale_;//*8u
//    // Create sprites from those textures
//    sf::Sprite cardSprite(cardTex);
//    cardSprite.setScale(scale_, scale_);
//    cardSprite.setPosition(posX_, posY_); // optional: place the baked card origin
//    //cardSprite.setColor(suitToColor(card.getFirstSuit()));
//   
//   return cardSprite;
//}
//std::vector<unsigned int> cardSize() {
//    unsigned int width  = cardTex.getSize().x * scale_;
//    unsigned int height = cardTex.getSize().y * scale_;
//    
//    return std::vector<unsigned int> {width, height};
//}
};
