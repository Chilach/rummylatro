#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "GCard.hpp"
#include "Card.hpp"
#include "Deck.hpp"
#include "GRack.hpp"
#include <iostream>

//std::unique_ptr<sf::RenderTexture> renderRack(Player player, float scale, float posX, float posY) {
////std::unique_ptr<sf::RenderTexture> renderRack(Card& card, float scale, float posX, float posY) {
//
//    // Load textures (these are local; that's OK)
//    // without the orderGLSuits all what we have done is fucked, so we need to deal with that shit now
//    Deck playerDeck = player.getDeck();
//    for(auto & card : playerDeck){
//        //everyCard.orderGLSuits();
//    }
//    card.orderGLSuits();
//    std::vector<GCar> gCards = GCard(card, scale, posX, posY); //inicializa la carta grafica
//    float myscale = gCard.getScale(); //crea una copia de la escala con la cual fue inicializada la carta
//    //Texture rankTex = gCard.loadRankTexture();
//
//    //loading sprites
//    sf::Sprite cardSprite = gCard.getCardSprite(); //crea los sprites de las carta a graficar
//    sf::Sprite rankSprite = gCard.getRankSprite();//crea los sprites del rank
//    std::vector<sf::Sprite> suitSprites = gCard.getSuitSprites();//crea un vector con los sprites de las suits posibles
//
//    // Create a render texture on the heap and return it via unique_ptr
//    auto renderTex = std::make_unique<sf::RenderTexture>();
//    unsigned int width  = gCard.getCardTextureSizeX() * myscale;//*8u
//    unsigned int height = gCard.getCardTextureSizeY() * myscale;//*8u
//                                                                //
//    if (!renderTex->create(width, height)) {
//        std::cerr << "Failed to create render texture\n";
//        return nullptr; // indicate failure
//    }
//
//    // Clear to transparent and draw layers (positions here are local to the render texture)
//    renderTex->clear(sf::Color::Transparent);
//    // If you want rank/suits positioned relative to the card top-left inside renderTex,
//    // use positions without posX/posY, e.g. rank at (10,10), suit offsets below:
//    renderTex->draw(cardSprite);
//    rankSprite.setColor( suitToColor( card.getSuits()[0] ) );
//    renderTex->draw(rankSprite); // draw rank on top (adjusted to local coords)
//                                 
//    int k = 0;
//    for(auto const &cardSuits : card.getSuits()){
//        suitSprites[k].setPosition(10.f + k*70.f, 80.f);
//        suitSprites[k].setColor(suitToColor(cardSuits));
//        renderTex->draw(suitSprites[k]);
//        k++;
//    }
//
//    renderTex->display();
//
//    return renderTex;
//}

//using namespace sf;

int main() {

    //ahora vamos a ver como hacer los Deck y los jugadores
    //NOW WE HAVE TO CREATE THE COMPLETE DECK 
    
    Deck tabledeck = Deck::createStandardDeck(); 
    tabledeck.shuffleDeck();
    //TABLEDECK.showDeck();
    std::cout << "Deck size: " << tabledeck.deckSize() << std::endl;
    Player julian("julian", tabledeck.dealCards(14));
    std::cout << julian.getName() << std::endl;
    julian.showDeck();
    Player ella("ella", tabledeck.dealCards(14));
    std::cout << ella.getName() << std::endl;
    ella.showDeck();

    Deck playerDeck = julian.getDeck();
    playerDeck.showDeck();
    for(auto & card : playerDeck.getCards()){
        card.showCard();

        //everyCard.orderGLSuits();
    }


    //sf::RenderWindow window(sf::VideoMode(800, 600), "Composited Card");
    ////Este es un poco de texto de prueba para mostrar lo linda que es mi fuenteikj  

    ////Card c1({Suit::DIAMONDS, Suit::HEARTS}, Rank::ACE, {Cmod::Wild});
    //Card c1({Suit::HEARTS, Suit::JOKERS}, Rank::ACE, {Cmod::Wild});

    //auto renderTex = renderCard(c1, 8.f, 0.f, 0.f);
    //sf::Sprite bakedCardSprite(renderTex->getTexture());
    //bakedCardSprite.setPosition(100.f, 100.f);

    //while (window.isOpen()) {
    //    sf::Event e;

    //    //EVENT TO CLOSE THE WINDOW
    //    while (window.pollEvent(e)) {
    //        if (e.type == sf::Event::Closed)
    //            window.close();
    //    }

    //    //EVENT TO RESIZE
    //    if (e.type == sf::Event::Resized) {
    //    // Get the new window size
    //    sf::Vector2u newSize = window.getSize();
    //    //std::cout << "Window resized to: " << newSize.x << "x" << newSize.y << "\n";
    //    
    //    // Update the view to match the new window size
    //    // This prevents stretching and maintains proper aspect ratio
    //    sf::View view(sf::FloatRect(0.f, 0.f, 
    //                               (float)newSize.x, (float)newSize.y));
    //    window.setView(view);
    //    
    //    // Optional: Reposition sprites relative to new window size
    //    // bakedCardSprite.setPosition(newSize.x / 2.f, newSize.y / 2.f);
    //        }

    //    window.clear(hexColor(0x1d1d1d));
    //    window.draw(bakedCardSprite);
    //    window.display();
    //}
}
