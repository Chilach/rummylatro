#include "Deck.hpp"
#include "Player.hpp"
#include "GCard.hpp"
#include <vector>

class GRack{
private:
    Player player_;
    //std::vector<Card> cards_;
    sf::Texture rackTexture_;

public:
    GRack(Player player) : player_(player) {
        loadRackTexture();
    };

   void loadRackTexture() {
       // Load card texture
       if (!rackTexture_.loadFromFile(getRackTextureDir())) {
           std::cerr << "❌ Failed to load rack texture\n";
       } else {
           std::cout << "✅ Card texture loaded\n";
       }

    }
std::string getRackTextureDir() const {
    return "assets/racks/RACK.png";
   };
};
