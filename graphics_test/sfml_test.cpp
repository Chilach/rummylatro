#include <SFML/Graphics.hpp>
//#include <"../Player.h">
#include "../Card.h"
#include "../Deck.h"
#include <iostream>

//class PlayerElements {
//private:
//    Player player_;
//public:
//    PlayerElements(const Player& player) : player_(player) {}
//};

using namespace sf;

Color hexColor(unsigned int hex, uint8_t alpha = 255) {
    return Color(
        (hex >> 16) & 0xFF,  // Red
        (hex >> 8)  & 0xFF,  // Green
        hex & 0xFF,          // Blue
        alpha
    );
}

namespace Colors {
    const sf::Color White = hexColor(0xeeeeee);
    const sf::Color Black = hexColor(0x1c1c1c);
    const sf::Color Green = hexColor(0x00afaf);
    const sf::Color Cream     = hexColor(0xFFF5E1);
}

int main() {

    Deck TableDeck = Deck::createStandardDeck();
    //TableDeck.shuffleDeck();
    //std::cout << TableDeck.deckSize() << std::endl;
    //Player p1("Alice", Deck(TableDeck.dealCards(5)) );
        
    RenderWindow window(VideoMode(800, 600), "Draggable Card (responsive)");
    window.setFramerateLimit(60);



    Texture a_spadesTex;
    if (!a_spadesTex.loadFromFile("/home/julian/juli/sem8/rummy-latro/art/try2/a_spades.png")) {
        std::cerr << "Heart image not found\n";
        return -1;
    }
    // If your heart.png is 50x50, you can scale to fit card if needed:
    Sprite a_spades(a_spadesTex);
    a_spades.setScale(8.f, 8.f); // doubles width and height
                                 
    Font font;
    if (!font.loadFromFile("Iosevka-Bold.ttc")) {
        std::cerr << "Font not found\n";
        return -1;
    }

    // Rank text
    //Text p1name(p1.getName(), font, 20);
    //p1name.setFillColor(Colors::Black);
    //p1name.setPosition(a_spades.getPosition().x + 8.f, a_spades.getPosition().y + 6.f);


    // compute scale so heart fits inside card (optional)

    bool isDragging = false;
    Vector2f dragOffset; // world-space offset between card pos and click

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            // --- handle window resize: update the view so world coords match window pixels ---
            if (event.type == Event::Resized) {
                // Set a new view with top-left at (0,0) and size equal to new window size
                FloatRect visibleArea(0.f, 0.f, static_cast<float>(event.size.width),
                                                    static_cast<float>(event.size.height));
                window.setView(View(visibleArea));
                // (Optional) You may want to reposition UI elements relative to new size here
            }

            // Mouse pressed: convert event pixel coords to world coords for hit test
            if (event.type == Event::MouseButtonPressed &&
                event.mouseButton.button == Mouse::Left)
            {
                // convert the pixel coordinates of the event to world coords
                Vector2i pixelPos(event.mouseButton.x, event.mouseButton.y);
                Vector2f worldPos = window.mapPixelToCoords(pixelPos);

                if (a_spades.getGlobalBounds().contains(worldPos)) {
                    isDragging = true;
                    dragOffset = a_spades.getPosition() - worldPos;
                }
            }

            // Mouse released
            if (event.type == Event::MouseButtonReleased &&
                event.mouseButton.button == Mouse::Left)
            {
                isDragging = false;
            }
        } // end pollEvent loop

        // If dragging: get current mouse pixel coords and map to world coords
        if (isDragging) {
            Vector2i mousePixelPos = Mouse::getPosition(window);
            Vector2f mouseWorldPos = window.mapPixelToCoords(mousePixelPos);
            Vector2f newCardPos = mouseWorldPos + dragOffset;
            a_spades.setPosition(newCardPos.x, newCardPos.y);
        }

        window.clear(Colors::Green);
        window.draw(a_spades);
        //window.draw(p1name);
        window.display();
    }

    return 0;
}
