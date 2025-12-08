#include <GCard.hpp>

std::unique_ptr<sf::RenderTexture> renderCard(Card& card, float scale, float posX, float posY) {

    // Load textures (these are local; that's OK)
    // without the orderGLSuits all what we have done is fucked, so we need to deal with that shit now
    card.orderGLSuits();
    GCard gCard = GCard(card, scale, posX, posY); //inicializa la carta grafica
    float myscale = gCard.getScale(); //crea una copia de la escala con la cual fue inicializada la carta
    //Texture rankTex = gCard.loadRankTexture();

    //loading sprites
    sf::Sprite cardSprite = gCard.getCardSprite(); //crea los sprites de las carta a graficar
    sf::Sprite rankSprite = gCard.getRankSprite();//crea los sprites del rank
    std::vector<sf::Sprite> suitSprites = gCard.getSuitSprites();//crea un vector con los sprites de las suits posibles

    // Create a render texture on the heap and return it via unique_ptr
    auto renderTex = std::make_unique<sf::RenderTexture>();
    unsigned int width  = gCard.getCardTextureSizeX() * myscale;//*8u
    unsigned int height = gCard.getCardTextureSizeY() * myscale;//*8u
                                                                //
    if (!renderTex->create(width, height)) {
        std::cerr << "Failed to create render texture\n";
        return nullptr; // indicate failure
    }

    // Clear to transparent and draw layers (positions here are local to the render texture)
    renderTex->clear(sf::Color::Transparent);
    // If you want rank/suits positioned relative to the card top-left inside renderTex,
    // use positions without posX/posY, e.g. rank at (10,10), suit offsets below:
    renderTex->draw(cardSprite);
    rankSprite.setColor( suitToColor( card.getSuits()[0] ) );
    renderTex->draw(rankSprite); // draw rank on top (adjusted to local coords)
                                 
    int k = 0;
    for(auto const &cardSuits : card.getSuits()){
        suitSprites[k].setPosition(10.f + k*70.f, 80.f);
        suitSprites[k].setColor(suitToColor(cardSuits));
        renderTex->draw(suitSprites[k]);
        k++;
    }

    renderTex->display();

    return renderTex;
}
