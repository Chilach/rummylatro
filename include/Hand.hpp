#pragma once

#include "Card.h"
#include <vector>
#include <memory>

namespace rummy_latro {

class Hand {
public:
    Hand();
    ~Hand() = default;
    
    // Card management
    void addCard(std::shared_ptr<Card> card);
    bool removeCard(const Card& card);
    bool hasCard(const Card& card) const;
    
    // Hand operations
    void clear();
    void sortByValue();
    void sortBySuit();
    
    // Hand evaluation
    bool isEmpty() const { return cards_.empty(); }
    size_t size() const { return cards_.size(); }
    
    // Accessors
    // std::string toString() const;
    const std::vector<std::shared_ptr<Card>>& getCards() const { return cards_; }
    std::vector<std::shared_ptr<Card>>& getCards() { return cards_; }
    
    // Hand analysis
    struct HandAnalysis {
        bool hasRun;
        bool hasSet;
        bool hasFlush;
        int pairs;
        int threeOfAKind;
        int fourOfAKind;
        int totalValue;
        double averageValue;
    };
    
    HandAnalysis analyze() const;
    
    // Melds (groups of cards that can be played)
    std::vector<std::vector<std::shared_ptr<Card>>> findRuns() const;
    std::vector<std::vector<std::shared_ptr<Card>>> findSets() const;
    std::vector<std::vector<std::shared_ptr<Card>>> findMelds() const;
    
    // Special hand types
    bool isRun(const std::vector<std::shared_ptr<Card>>& cards) const;
    bool isSet(const std::vector<std::shared_ptr<Card>>& cards) const;
    bool isFlush(const std::vector<std::shared_ptr<Card>>& cards) const;
    
private:
    std::vector<std::shared_ptr<Card>> cards_;
    
    // Helper functions
    bool isConsecutive(const std::vector<std::shared_ptr<Card>>& cards) const;
    bool isSameRank(const std::vector<std::shared_ptr<Card>>& cards) const;
    bool isSameSuit(const std::vector<std::shared_ptr<Card>>& cards) const;
    
    // Sorting helpers
    static bool compareByValue(const std::shared_ptr<Card>& a, const std::shared_ptr<Card>& b);
    static bool compareBySuit(const std::shared_ptr<Card>& a, const std::shared_ptr<Card>& b);
};

} // namespace rummy_latro
