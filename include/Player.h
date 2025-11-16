#pragma once

#include "Card.h"
#include "Deck.h"

class Player{
private:
    std::string name_;
    Deck deck_; //cartas en la mano del jugador
    int score_; //puntaje del jugador
    
public:
    Player(std::string name, Deck deck) : name_(name), deck_(deck), score_(0) {}

    void showDeck() const {
        deck_.showDeck();
    }

    void showName() const {
        std::cout << "Player: " << name_ << std::endl;
    }

    void showScore() const {
        std::cout << "Score: " << score_ << std::endl;
    }

    void addScore(int points) {
        score_ += points;
    }

    int getScore() const {
        return score_;
    }

    std::string getName() const {
        return name_;
    }

    void setDeck(const Deck& deck) {
        deck_ = deck;
    }

    Deck& getDeck() {
        return deck_;
    }

    void addCard(const Card& card) {
        deck_.addCard(card);
    }
    void removeSpecificCard(Card card) {
        deck_.removeSpecificCard(card);
    }

};
