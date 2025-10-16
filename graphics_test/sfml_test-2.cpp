#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Draggable Card");
    window.setFramerateLimit(60);

    // Card background
    sf::RectangleShape card(sf::Vector2f(50, 70));
    card.setFillColor(sf::Color::White);
    card.setOutlineColor(sf::Color::Black);
    card.setOutlineThickness(2);
    card.setPosition(200, 200);

    // Load font
    sf::Font font;
    if (!font.loadFromFile("Iosevka-Bold.ttc")) {
        std::cout << "Font not found.\n";
        return -1;
    }

    // Rank text
    sf::Text rank("A", font, 20);
    rank.setFillColor(sf::Color::Black);
    rank.setPosition(card.getPosition().x + 10, card.getPosition().y + 10);

    // Heart sprite
    sf::Texture heartTexture;
    if (!heartTexture.loadFromFile("heart.png")) {
        std::cout << "Heart image not found.\n";
        return -1;
    }
    sf::Sprite heartSprite(heartTexture);
    heartSprite.setScale(0.05f, 0.05f);
    heartSprite.setPosition(card.getPosition().x + 20, card.getPosition().y + 35);

    // --- Variables for dragging ---
    bool isDragging = false;
    sf::Vector2f offset;

    // --- Main loop ---
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Mouse pressed
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
                if (card.getGlobalBounds().contains(mousePos)) {
                    isDragging = true;
                    offset = card.getPosition() - mousePos;
                }
            }

            // Mouse released
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                isDragging = false;
            }
        }

        // If dragging, update card position
        if (isDragging) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sf::Vector2f newPos(mousePos.x + offset.x, mousePos.y + offset.y);
            card.setPosition(newPos);
            rank.setPosition(newPos.x + 10, newPos.y + 10);
            heartSprite.setPosition(newPos.x + 20, newPos.y + 35);
        }

        window.clear(sf::Color(0, 100, 0));
        window.draw(card);
        window.draw(rank);
        window.draw(heartSprite);
        window.display();
    }

    return 0;
}
