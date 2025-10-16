#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main() {
    // Create the window
    RenderWindow window(VideoMode(640, 480), "SFML + Iosevka Test"); //bas, altura
    window.setFramerateLimit(60);//define los fps

    // Draw a simple card shape
    RectangleShape card(Vector2f(120.f, 180.f));
    card.setFillColor(Color::White);
    card.setOutlineColor(Color::Black);
    card.setOutlineThickness(3.f);
    card.setPosition(260.f, 150.f);

    // Load Iosevka font
    Font font;
    if (!font.loadFromFile("Iosevka-Bold.ttc")) {
        std::cerr << "❌ Error: could not load font 'Iosevka-Bold.ttc'\n";
        return 1;
    }

    // Draw rank text (A)
    Text rank("A", font, 36);
    rank.setFillColor(Color::Black);
    rank.setPosition(card.getPosition().x + 12, card.getPosition().y + 12);

    // Draw suit text (♥)
    //Text suit("HEARTS", font, 32);
    //suit.setFillColor(Color::Red);
    //suit.setPosition(card.getPosition().x + 12, card.getPosition().y + 56);
    //
    //// ----------------------------------------------------
    // Load and draw the HEART image instead of text
    // ----------------------------------------------------
    Texture heartTexture;
    if (!heartTexture.loadFromFile("heart.png")) {
        std::cerr << "❌ Error: could not load texture 'heart.png'\n";
        // Optionally, fall back to text or just exit
        // For now, let's exit if the required texture isn't found
        return 1;
    }

    // Create a sprite from the texture
    Sprite heartSprite(heartTexture);

    // Set the position for the sprite (similar to where the text was)
    // You might need to adjust the position and scale based on your image size
    float spriteX = card.getPosition().x + 5.f;
    float spriteY = card.getPosition().y + 56.f; // The original suit text Y position
    heartSprite.setPosition(spriteX, spriteY);

    // Optional: Scale the sprite if your heart.png is too large or too small
     heartSprite.setScale(2.f, 2.f); // Example: half size
    // ----------------------------------------------------

    // Main loop
    while (window.isOpen()) {
        Event ev;
        while (window.pollEvent(ev)) {
            if (ev.type == Event::Closed)
                window.close();
        }

        window.clear(Color(100, 150, 200)); // background
        window.draw(card);
        window.draw(rank);
        window.draw(heartSprite);;
        window.display();
    }

    return 0;
}
