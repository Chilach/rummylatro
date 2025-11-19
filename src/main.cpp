#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "GCard.hpp"
#include "Card.hpp"
#include "Deck.hpp"
#include <iostream>

//NOW LETS MAKE THE FUNCTION I NEED TO RENDER THE DIFFERENT TYPES OF POSSIBLE LOOKS ON THE Card
    // draw suit sprites positioned relative to the card
//void drawCard(){
//    for (auto &cardsuits : card.getSuits()){
//        Sprite &s = suitSprites[static_cast<std::size_t>(cardsuits)];
//        // Example positions; adjust as needed
//        if (cardsuits == Suit::SPADES) {
//            s.setPosition(10.f, 80.f);
//            s.setColor(suitToColor(cardsuits));
//        } else if (cardsuits == Suit::HEARTS) {
//            s.setPosition(70.f, 80.f);
//            s.setColor(suitToColor(cardsuits));
//        } else if (cardsuits == Suit::DIAMONDS) {
//            s.setPosition(130.f, 80.f);
//            s.setColor(suitToColor(cardsuits));
//        } else if (cardsuits == Suit::CLUBS) {
//            s.setPosition(190.f, 80.f);
//            s.setColor(suitToColor(cardsuits));
//        }
//        renderTex->draw(s);
//}

using namespace sf;

std::unique_ptr<sf::RenderTexture> RenderCard(Card& card, float scale, float posX, float posY) {

    // Load textures (these are local; that's OK)
    card.orderGLSuits();
    GCard gCard = GCard(card, scale, posX, posY);
    float myscale = gCard.getScale();
    Texture cardTex = gCard.loadCardTexture();
    Texture rankTex = gCard.loadRankTexture();
	std::vector<Texture> suitTextures = gCard.loadSuitTextures();

    // Create sprites from those textures
    Sprite cardSprite(cardTex);
    cardSprite.setScale(myscale, myscale);
    cardSprite.setPosition(gCard.getPosX(), gCard.getPosY()); // optional: place the baked card origin
   //cardSprite.setColor(suitToColor(card.getFirstSuit()));

    Sprite rankSprite(rankTex);
    rankSprite.setScale(myscale, myscale);
    rankSprite.setPosition(gCard.getPosX() + 20.f, gCard.getPosY() + 20.f);
    rankSprite.setColor(suitToColor(card.getFirstSuit()));
    std::vector<Sprite> suitSprites;
    suitSprites.reserve(suitTextures.size());
    for (const auto &tex : suitTextures) {
        Sprite s(tex);
        s.setScale(myscale, myscale);
        suitSprites.push_back(s);
    }

    // Create a render texture on the heap and return it via unique_ptr
    auto renderTex = std::make_unique<RenderTexture>();
    unsigned int width  = cardTex.getSize().x * myscale;//*8u
    unsigned int height = cardTex.getSize().y * myscale;//*8u
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
    renderTex->draw(rankSprite);

    // draw suit sprites positioned relative to the card
    for (auto &cardsuits : card.getSuits()){
        Sprite &s = suitSprites[static_cast<std::size_t>(cardsuits)];
        // Example positions; adjust as needed
        if (cardsuits == Suit::SPADES) {
            s.setPosition(10.f, 80.f);
            s.setColor(suitToColor(cardsuits));
        } else if (cardsuits == Suit::HEARTS) {
            s.setPosition(70.f, 80.f);
            s.setColor(suitToColor(cardsuits));
        } else if (cardsuits == Suit::DIAMONDS) {
            s.setPosition(130.f, 80.f);
            s.setColor(suitToColor(cardsuits));
        } else if (cardsuits == Suit::CLUBS) {
            s.setPosition(190.f, 80.f);
            s.setColor(suitToColor(cardsuits));
        }
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
