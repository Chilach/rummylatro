#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "GCard.hpp"
#include "Card.hpp"
#include "Deck.hpp"
#include <iostream>

using namespace sf;

std::unique_ptr<sf::RenderTexture> RenderCard(Card& card, float scale, float posX, float posY) {

    // Load textures (these are local; that's OK)
    // without the orderGLSuits all what we have done is fucked, so we need to deal with that shit now
    card.orderGLSuits();
    GCard gCard = GCard(card, scale, posX, posY); //inicializa la carta grafica
    float myscale = gCard.getScale(); //crea una copia de la escala con la cual fue inicializada la carta
    //Texture rankTex = gCard.loadRankTexture();

    //loading sprites
    sf::Sprite cardSprite = gCard.getCardSprite(); //crea los sprites de las carta a graficar
    sf::Sprite rankSprite = gCard.getRankSprite();//crea los sprites del rank
    std::vector<Sprite> suitSprites = gCard.getSuitSprites();//crea un vector con los sprites de las suits posibles

    // Create a render texture on the heap and return it via unique_ptr
    auto renderTex = std::make_unique<RenderTexture>();
    unsigned int width  = gCard.getCardTextureSizeX() * myscale;//*8u
    unsigned int height = gCard.getCardTextureSizeY() * myscale;//*8u
                                                                //
    if (!renderTex->create(width, height)) {
        std::cerr << "Failed to create render texture\n";
        return nullptr; // indicate failure
    }

    // Clear to transparent and draw layers (positions here are local to the render texture)
    renderTex->clear(Color::Transparent);
    // If you want rank/suits positioned relative to the card top-left inside renderTex,
    // use positions without posX/posY, e.g. rank at (10,10), suit offsets below:
    renderTex->draw(cardSprite);
    rankSprite.setColor( suitToColor( card.getSuits()[0] ) );
    renderTex->draw(rankSprite); // draw rank on top (adjusted to local coords)
                                 
    int k = 0;
    for(auto const &cardSuits : card.getSuits()){
        suitSprites[k].setPosition(10.f + k*70.f, 80.f);
        suitSprites[k].setColor(suitToColor(cardSuits));
        renderTex->draw(suitSprites[k]);
        k++;
    }

    //for (auto &cardsuits : card.getSuits()){
    //    Sprite &s = suitSprites[static_cast<std::size_t>(cardsuits)];
    //    // Example positions; adjust as needed
    //    if (cardsuits == Suit::SPADES) {
    //        s.setPosition(10.f, 80.f);
    //        s.setColor(suitToColor(cardsuits));
    //    } else if (cardsuits == Suit::HEARTS) {
    //        s.setPosition(70.f, 80.f);
    //        s.setColor(suitToColor(cardsuits));
    //    } else if (cardsuits == Suit::DIAMONDS) {    //        s.setPosition(130.f, 80.f);
    //        s.setColor(suitToColor(cardsuits));
    //    } else if (cardsuits == Suit::CLUBS) {
    //        s.setPosition(190.f, 80.f);
    //        s.setColor(suitToColor(cardsuits));
    //    }
    //    renderTex->draw(s);
    //}
    // finalize the render texture — this makes its texture usable via getTexture()
    renderTex->display();

    // return ownership to caller
    return renderTex;
}

int main() {
    RenderWindow window(VideoMode(800, 600), "Composited Card");
    //Este es un poco de texto de prueba para mostrar lo linda que es mi fuenteikj  

    //Card c1({Suit::DIAMONDS, Suit::SPADES, Suit::CLUBS, Suit::HEARTS}, Rank::ACE, {Cmod::Wild});
    //Card c1({Suit::DIAMONDS, Suit::SPADES, Suit::CLUBS}, Rank::ACE, {Cmod::Wild});
    //Card c1({Suit::DIAMONDS}, Rank::ACE, {Cmod::Wild});
    Card c1({Suit::SPADES, Suit::DIAMONDS}, Rank::ACE, {Cmod::Wild});
    //jCard c1({Suit::DIAMONDS, Suit::HEARTS}, Rank::ACE, {Cmod::Wild});
    //Card c1({Suit::HEARTS}, Rank::ACE, {Cmod::Wild});

    auto renderTex = RenderCard(c1, 8.f, 0.f, 0.f);
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
        window.display();
    }
}
