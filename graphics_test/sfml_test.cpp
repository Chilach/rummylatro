#include <SFML/Graphics.hpp>
#include <iostream>

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
    RenderWindow window(VideoMode(800, 600), "Draggable Card (responsive)");
    window.setFramerateLimit(60);

    // Card background (50x70 as example)
    RectangleShape card(Vector2f(50.f, 70.f));
    card.setFillColor(Colors::White);
    card.setOutlineColor(Colors::Black);
    card.setOutlineThickness(2.f);
    card.setPosition(200.f, 200.f);

    // Load font (adjust path as needed)
    Font font;
    if (!font.loadFromFile("Iosevka-Bold.ttc")) {
        std::cerr << "Font not found\n";
        return -1;
    }

    // Rank text
    Text rank("A", font, 20);
    rank.setFillColor(Colors::Black);
    rank.setPosition(card.getPosition().x + 8.f, card.getPosition().y + 6.f);

    // Heart texture & sprite (50x50 sprite assumed)
    Texture heartTex;
    if (!heartTex.loadFromFile("heart.png")) {
        std::cerr << "Heart image not found\n";
        return -1;
    }
    // If your heart.png is 50x50, you can scale to fit card if needed:
    Sprite heart(heartTex);
    // compute scale so heart fits inside card (optional)
    float scaleX = (30.f / heartTex.getSize().x);
    float scaleY = (30.f / heartTex.getSize().y);
    heart.setScale(scaleX, scaleY);
    heart.setPosition(card.getPosition().x + 10.f, card.getPosition().y + 30.f);

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

                if (card.getGlobalBounds().contains(worldPos)) {
                    isDragging = true;
                    dragOffset = card.getPosition() - worldPos;
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
            card.setPosition(newCardPos);
            rank.setPosition(newCardPos.x + 8.f, newCardPos.y + 6.f);
            heart.setPosition(newCardPos.x + 10.f, newCardPos.y + 30.f);
        }

        window.clear(Colors::Green);
        window.draw(card);
        window.draw(rank);
        window.draw(heart);
        window.display();
    }

    return 0;
}
