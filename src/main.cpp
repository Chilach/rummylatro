#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "GCard.hpp"
#include "Card.hpp"
#include "Deck.hpp"
#include <iostream>

using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "Composited Card");
    //Este es un poco de texto de prueba para mostrar lo linda que es mi fuenteikj  

    //Card c1({Suit::DIAMONDS, Suit::SPADES, Suit::CLUBS, Suit::HEARTS}, Rank::ACE, {Cmod::Wild});
    //Card c1({Suit::DIAMONDS, Suit::SPADES, Suit::CLUBS}, Rank::ACE, {Cmod::Wild});
    //Card c1({Suit::DIAMONDS}, Rank::ACE, {Cmod::Wild});
    //Card c1({Suit::SPADES, Suit::DIAMONDS}, Rank::ACE, {Cmod::Wild});
    //Card c1({Suit::DIAMONDS, Suit::HEARTS}, Rank::ACE, {Cmod::Wild});
    Card c1({Suit::HEARTS, Suit::JOKERS}, Rank::ACE, {Cmod::Wild});

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
