#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Create the window
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML + Iosevka Test");
    window.setFramerateLimit(60);

    // Draw a simple card shape
    sf::RectangleShape card(sf::Vector2f(120.f, 180.f));
    card.setFillColor(sf::Color::White);
    card.setOutlineColor(sf::Color::Black);
    card.setOutlineThickness(3.f);
    card.setPosition(260.f, 150.f);

    // Load Iosevka font
    sf::Font font;
    if (!font.loadFromFile("Iosevka-Bold.ttc")) {
        std::cerr << "❌ Error: could not load font 'Iosevka-Bold.ttc'\n";
        return 1;
    }

    // Draw rank text (A)
    sf::Text rank("A", font, 36);
    rank.setFillColor(sf::Color::Black);
    rank.setPosition(card.getPosition().x + 12, card.getPosition().y + 12);

    // Draw suit text (♥)
    sf::Text suit("♥", font, 32);
    suit.setFillColor(sf::Color::Red);
    suit.setPosition(card.getPosition().x + 12, card.getPosition().y + 56);

    // Main loop
    while (window.isOpen()) {
        sf::Event ev;
        while (window.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(100, 150, 200)); // background
        window.draw(card);
        window.draw(rank);
        window.draw(suit);
        window.display();
    }

    return 0;
}
