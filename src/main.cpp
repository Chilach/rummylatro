#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "GCard.hpp"
#include "Card.hpp"
#include "Deck.hpp"
#include <iostream>

//using namespace sf;

int main() {

    //ahora vamos a ver como hacer los Deck y los jugadores
    //NOW WE HAVE TO CREATE THE COMPLETE DECK 
    
    //Deck tabledeck = Deck::createStandardDeck(); 
    //tabledeck.shuffleDeck();
    ////TABLEDECK.showDeck();
    //std::cout << "Deck size: " << tabledeck.deckSize() << std::endl;
    //Player julian("julian", tabledeck.dealCards(14));
    //std::cout << julian.getName() << std::endl;
    //julian.showDeck();
    //Player ella("ella", tabledeck.dealCards(14));
    //std::cout << ella.getName() << std::endl;
    //ella.showDeck();

    sf::RenderWindow window(sf::VideoMode(800, 600), "Composited Card");
    //Este es un poco de texto de prueba para mostrar lo linda que es mi fuenteikj  

    //Card c1({Suit::DIAMONDS, Suit::HEARTS}, Rank::ACE, {Cmod::Wild});
    Card c1({Suit::HEARTS, Suit::JOKERS}, Rank::ACE, {Cmod::Wild});

    auto renderTex = RenderCard(c1, 8.f, 0.f, 0.f);
    sf::Sprite bakedCardSprite(renderTex->getTexture());
    bakedCardSprite.setPosition(100.f, 100.f);

    while (window.isOpen()) {
        sf::Event e;

        //EVENT TO CLOSE THE WINDOW
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();
        }

        //EVENT TO RESIZE
        if (e.type == sf::Event::Resized) {
        // Get the new window size
        sf::Vector2u newSize = window.getSize();
        std::cout << "Window resized to: " << newSize.x << "x" << newSize.y << "\n";
        
        // Update the view to match the new window size
        // This prevents stretching and maintains proper aspect ratio
        sf::View view(sf::FloatRect(0.f, 0.f, 
                                   (float)newSize.x, (float)newSize.y));
        window.setView(view);
        
        // Optional: Reposition sprites relative to new window size
        // bakedCardSprite.setPosition(newSize.x / 2.f, newSize.y / 2.f);
            }

        window.clear(hexColor(0x1d1d1d));
        window.draw(bakedCardSprite);
        window.display();
    }
}
