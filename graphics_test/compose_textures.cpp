#include <SFML/Graphics.hpp>
#include "../Player.h"
#include "../Card.h"
#include "../Deck.h"
#include <iostream>

/*
- Implementar la parte gráfica de la carta
 */
using namespace sf;

//class GCard {
//private:
//public:
//};
//
Texture loadCardTexture(Card card){
    Texture cardTex;
    if (!cardTex.loadFromFile(card.getCardTextureDir())){
        std::cerr << "Failed to load textures\n";
    }
    return cardTex;
}

Texture loadRankTexture(Card card){
    Texture rankTex;
    if (!rankTex.loadFromFile(card.getRankTextureDir())){
        std::cerr << "Failed to load textures\n";
    }
    return rankTex;
}

std::vector<Texture> loadSuitTextures(Card card){
    std::vector<Texture> suitTextures;
    for (const auto &dir : card.getSuitTextureDirs()){
        Texture suitTex;
        if (!suitTex.loadFromFile(dir)){
            std::cerr << "Failed to load textures\n";
        }
        suitTextures.push_back(suitTex);
    }
    return suitTextures;
}



int main() {
    RenderWindow window(VideoMode(800, 600), "Composited Card");

    Card c1({Suit::SPADES, Suit::HEARTS}, Rank::ACE, {Cmod::Wild});

    Texture cardTex, rankTex;
    cardTex = loadCardTexture(c1);
    rankTex = loadRankTexture(c1);
    std::vector<Texture> suitTextures = loadSuitTextures(c1);
    //if (!cardTex.loadFromFile("/home/julian/juli/sem8/rummy-latro/art/card/card.png") ||
    //    !rankTex.loadFromFile("/home/julian/juli/sem8/rummy-latro/art/rank/A.png") ||
    //    !spadeTex.loadFromFile("/home/julian/juli/sem8/rummy-latro/art/suit/SPADES.png")) {
    //    std::cerr << "Failed to load textures\n";
    //    return -1;
    //}

    ////configure card sprite (base layer)
    Sprite card(cardTex);
    card.setScale(8.f, 8.f); // doubles width and height
    //card.setPosition(200, 200);
    //
    ////configure rank sprite (another layer)
    Sprite rank(rankTex);
    //rank.setScale(8.f, 8.f);
    //rank.setPosition(card.getPosition() + Vector2f(20, 20));
    //rank.setColor(sf::Color(0, 0, 0));

    ////configure suit sprite (another layer)
    std::vector<Sprite> suits;
    for (const auto &tex : suitTextures){
        Sprite suit(tex);
        suits.push_back(suit);
    }
    //suit.setScale(8.f, 8.f);
    //suit.setPosition(card.getPosition() + Vector2f(20, 80));
    //suit.setColor(sf::Color(0, 0, 0));
    
    //ahora vamos a hacer los mismo pero con renderTex
    RenderTexture renderTex;
    if (!renderTex.create(cardTex.getSize().x * 8, cardTex.getSize().y * 8)) {
        std::cerr << "Failed to create render texture\n";
        return -1;
    }
    rank.setScale(8.f, 8.f);
    rank.setPosition(10, 10);
    rank.setColor(sf::Color(0, 0, 0));

    for(int i=0; i<suits.size(); i++){
        Sprite &suit = suits[i];
        suit.setScale(8.f, 8.f);
        suit.setPosition(10+ i*60, 80); // adjust position for each suit
        suit.setColor(sf::Color(0, 0, 0));
        if (i>0){
            suit.setColor(sf::Color(255, 0, 0));
        }
        renderTex.draw(suit);
    }
    //suit.setScale(8.f, 8.f);
    //suit.setPosition(10, 80);
    //suit.setColor(sf::Color(0, 0, 0));

    renderTex.clear(Color::Transparent);
    renderTex.draw(card);
    renderTex.draw(rank);
    for(const auto &suit : suits){
        renderTex.draw(suit);
    }
    //renderTex.draw(suit);
    renderTex.display();

    Sprite composedCard(renderTex.getTexture());

    while (window.isOpen()) {
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed)
                window.close();
        }

        window.clear(Color::Blue);
        window.draw(composedCard);
        //window.draw(card);
        //window.draw(rank);
        //window.draw(suit);
        window.display();
    }
}
