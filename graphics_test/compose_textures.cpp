#include <SFML/Graphics.hpp>
#include "../Player.h"
#include "../Card.h"
#include "../Deck.h"
#include <iostream>

/*
- Implementar la parte gráfica de la carta
 */
using namespace sf;



int main() {
    RenderWindow window(VideoMode(800, 600), "Composited Card");

    Texture cardTex, rankTex, spadeTex;
    if (!cardTex.loadFromFile("/home/julian/juli/sem8/rummy-latro/art/try4/cart.png") ||
        !rankTex.loadFromFile("/home/julian/juli/sem8/rummy-latro/art/try4/A.png") ||
        !spadeTex.loadFromFile("/home/julian/juli/sem8/rummy-latro/art/try4/spades.png")) {
        std::cerr << "Failed to load textures\n";
        return -1;
    }

    //configure card sprite (base layer)
    Sprite card(cardTex);
    card.setScale(8.f, 8.f); // doubles width and height
    card.setPosition(200, 200);
    
    //configure rank sprite (another layer)
    Sprite rank(rankTex);
    rank.setScale(8.f, 8.f);
    rank.setPosition(card.getPosition() + Vector2f(20, 20));
    rank.setColor(sf::Color(0, 0, 0));

    //configure suit sprite (another layer)
    Sprite suit(spadeTex);
    suit.setScale(8.f, 8.f);
    suit.setPosition(card.getPosition() + Vector2f(20, 80));
    suit.setColor(sf::Color(0, 0, 0));

    while (window.isOpen()) {
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed)
                window.close();
        }

        window.clear(Color::Blue);
        window.draw(card);
        window.draw(rank);
        window.draw(suit);
        window.display();
    }
}
