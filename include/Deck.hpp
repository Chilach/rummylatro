#pragma once

#include "Card.hpp"
#include <vector>
#include <memory>
#include <random>

const unsigned int seed = 12345; // the "run" seed

class Deck {

private:
    std::vector<Card> cards_;

public:
    Deck(std::vector<Card> cards) : cards_(cards) {}

    void showDeck() const {
        for (const auto& card : cards_) {
            card.show();
        }
    }

    const std::vector<Card>& getCards() const {
        return cards_;
    }

    void shuffleDeck() {
        //std::random_device rd;
        std::mt19937 g(seed);
        std::shuffle(cards_.begin(), cards_.end(), g);
    }

    //seters
    void addCard(const Card& card) {
        cards_.push_back(card);
    }

    void removeCard(int index) {
        if (index >= 0 && index < cards_.size()) {
            cards_.erase(cards_.begin() + index);
        }
    }

    //add a fuction to remove specifically a card lets say an ace of spades
    void removeSpecificCard(const Card& card) {
        auto it = std::find_if(cards_.begin(), cards_.end(), [&card](const Card& c) {
            return c.getRank() == card.getRank() && c.getSuits() == card.getSuits() && c.getCmod() == card.getCmod();
        });
        if (it != cards_.end()) {
            cards_.erase(it);
        }
    }

    int deckSize() const {
        return cards_.size();
    }

    int deckNorm() const {
        int norm = 0;
        for (const auto& card : cards_) {
            norm += card.getNorm();
        }
        return norm;
    }

    static Deck createStandardDeck() {
        std::vector<Card> myCards;
        std::vector<Cmod> mod = {Cmod::None};

        for (int i = 0; i < 2; ++i){
            for (int value = 1; value <= 13; ++value) {
                myCards.push_back(Card({Suit::HEARTS}  , static_cast<Rank>(value)));
                myCards.push_back(Card({Suit::DIAMONDS}, static_cast<Rank>(value)));
                myCards.push_back(Card({Suit::CLUBS}   , static_cast<Rank>(value)));
                myCards.push_back(Card({Suit::SPADES}  , static_cast<Rank>(value)));
                }
            myCards.push_back(Card({Suit::JOKERS}, Rank::JOKER));
            myCards.push_back(Card({Suit::JOKERS}, Rank::JOKER));
            }
        Deck deck(myCards);
        return deck;
    }

    std::vector<Card> dealCards(int n) {
    // Make sure we don’t take more cards than exist
    if (n > cards_.size()) n = cards_.size();
    // Copy the first n cards
    std::vector<Card> dealt;
    dealt.insert(dealt.end(), cards_.begin(), cards_.begin() + n);
    for (const auto& card : dealt) {
        removeSpecificCard(card);
    }

    return dealt;
}
};
