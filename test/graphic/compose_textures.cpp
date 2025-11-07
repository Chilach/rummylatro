#include <SFML/Graphics.hpp>
#include "../Player.h"
#include "../Card.h"
#include "../Deck.h"
#include <iostream>

/*
- Implementar la parte gráfica de la carta
 */
using namespace sf;

//std::unique_ptr<sf::RenderTexture> RenderCard(Card card, float posX, float posY){
//    Texture cardTex, rankTex;
//    cardTex = loadCardTexture(card);
//    rankTex = loadRankTexture(card);
//    card.orderGLSuits();
//    std::vector<Texture> suitTextures = loadSuitTextures(card);
//    Sprite cardSprite(cardTex);
//    cardSprite.setScale(8.f, 8.f); // doubles width and height
//    Sprite rankSprite(rankTex);
//    rankSprite.setScale(8.f, 8.f);
//    rankSprite.setPosition(10, 10);
//    std::vector<Sprite> suitSprites;
//    for (const auto &tex : suitTextures){
//        Sprite suit(tex);
//        suitSprites.push_back(suit);
//    }
//    RenderTexture renderTex;
//    if (!renderTex.create(cardTex.getSize().x * 8, cardTex.getSize().y * 8)) {
//        std::cerr << "Failed to create render texture\n";
//    }
//    for(int i=0; i<suitSprites.size(); i++){
//        Sprite &suit = suitSprites[i];
//        suit.setScale(8.f, 8.f);
//        suit.setPosition(10+ i*60, 80); // adjust position for each suit
//        suit.setColor(sf::Color(0, 0, 0));
//        if (i>0){
//            suit.setColor(sf::Color(255, 0, 0));
//        }
//        renderTex.draw(suit);
//    }
//
//    renderTex.clear(Color::Transparent);
//    renderTex.draw(cardSprite);
//    renderTex.draw(rankSprite);
//    for(const auto &suit : suitSprites){
//        renderTex.draw(suit);
//    }
//    //renderTex.draw(suit);
//    //renderTex.display();
//    renderTex->display();
//    return renderTex;
//}
std::unique_ptr<sf::RenderTexture> RenderCard(Card& card, float posX, float posY) {

    // Load textures (these are local; that's OK)
    card.orderGLSuits();
    Texture cardTex = loadCardTexture(card);
    Texture rankTex = loadRankTexture(card);
    std::vector<Texture> suitTextures = loadSuitTextures(card);

    // Create sprites from those textures
    Sprite cardSprite(cardTex);
    cardSprite.setScale(8.f, 8.f);
    cardSprite.setPosition(posX, posY); // optional: place the baked card origin
    //cardSprite.setColor(suitToColor(card.getFirstSuit()));

    Sprite rankSprite(rankTex);
    rankSprite.setScale(8.f, 8.f);
    rankSprite.setPosition(posX + 10.f, posY + 10.f);
    rankSprite.setColor(suitToColor(card.getFirstSuit()));
    std::vector<Sprite> suitSprites;
    suitSprites.reserve(suitTextures.size());
    for (const auto &tex : suitTextures) {
        Sprite s(tex);
        s.setScale(8.f, 8.f);
        suitSprites.push_back(s);
    }

    // Create a render texture on the heap and return it via unique_ptr
    auto renderTex = std::make_unique<RenderTexture>();
    unsigned int width  = cardTex.getSize().x * 8u;
    unsigned int height = cardTex.getSize().y * 8u;
    if (!renderTex->create(width, height)) {
        std::cerr << "Failed to create render texture\n";
        return nullptr; // indicate failure
    }

    // Clear to transparent and draw layers (positions here are local to the render texture)
    renderTex->clear(Color::Transparent);

    // If you want rank/suits positioned relative to the card top-left inside renderTex,
    // use positions without posX/posY, e.g. rank at (10,10), suit offsets below:
    renderTex->draw(cardSprite);

    // draw rank on top (adjusted to local coords)
    rankSprite.setPosition(10.f, 10.f);
    renderTex->draw(rankSprite);

    // draw suit sprites positioned relative to the card
    for (std::size_t i = 0; i < suitSprites.size(); ++i) {
        Sprite &s = suitSprites[i];
        s.setPosition(10.f + static_cast<float>(i) * 60.f, 80.f); // adjust as needed
        // black for first, red for others (example)
        s.setColor((i > 0) ? Color(255,0,0) : Color(0,0,0));
        renderTex->draw(s);
    }

    // finalize the render texture — this makes its texture usable via getTexture()
    renderTex->display();

    // return ownership to caller
    return renderTex;
}

int main() {
    RenderWindow window(VideoMode(800, 600), "Composited Card");

    Card c1({Suit::DIAMONDS, Suit::SPADES, Suit::CLUBS, Suit::HEARTS}, Rank::ACE, {Cmod::Wild});

    //Texture cardTex, rankTex;
    //cardTex = loadCardTexture(c1);
    //rankTex = loadRankTexture(c1);
    //std::vector<Texture> suitTextures = loadSuitTextures(c1);
    //Sprite card(cardTex);
    //card.setScale(8.f, 8.f); // doubles width and height
    //Sprite rank(rankTex);
    //std::vector<Sprite> suits;
    //for (const auto &tex : suitTextures){
    //    Sprite suit(tex);
    //    suits.push_back(suit);
    //}
    //RenderTexture renderTex;
    //if (!renderTex.create(cardTex.getSize().x * 8, cardTex.getSize().y * 8)) {
    //    std::cerr << "Failed to create render texture\n";
    //    return -1;
    //}
    //rank.setScale(8.f, 8.f);
    //rank.setPosition(10, 10);
    //rank.setColor(sf::Color(0, 0, 0));
    //for(int i=0; i<suits.size(); i++){
    //    Sprite &suit = suits[i];
    //    suit.setScale(8.f, 8.f);
    //    suit.setPosition(10+ i*60, 80); // adjust position for each suit
    //    suit.setColor(sf::Color(0, 0, 0));
    //    if (i>0){
    //        suit.setColor(sf::Color(255, 0, 0));
    //    }
    //    renderTex.draw(suit);
    //}
    ////suit.setScale(8.f, 8.f);
    ////suit.setPosition(10, 80);
    ////suit.setColor(sf::Color(0, 0, 0));

    //renderTex.clear(Color::Transparent);
    //renderTex.draw(card);
    //renderTex.draw(rank);
    //for(const auto &suit : suits){
    //    renderTex.draw(suit);
    //}
    ////renderTex.draw(suit);
    //renderTex.display();
    auto renderTex = RenderCard(c1, 0.f, 0.f);
    sf::Sprite bakedCardSprite(renderTex->getTexture());
    bakedCardSprite.setPosition(100.f, 100.f);

    while (window.isOpen()) {
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed)
                window.close();
        }

        window.clear(Color::Blue);
        window.draw(bakedCardSprite);
        //window.draw(card);
        //window.draw(rank);
        //window.draw(suit);
        window.display();
    }
}
