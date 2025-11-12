# Cards Documentation

## Preliminaries
**1. The Rank**
We define the `Rank` of a card with the following code:
```cpp
enum class Rank {
	ACE = 1,
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	JACK = 11,
	QUEEN = 12,
	KING = 13,
	JOKER = 0
};

```
**2. The Suit**
As we did with `Rank` we do with `Suits`
```cpp
enum class Suit : uint8_t {Hearts, Diamonds, Clubs, Spades, Jokers};
```
It is self explanatory.

## The `Card` class

The `Card` class is the main object in the project, to be constructed it uses three arguments for being initialized:
- Rank rank_;
- std::vector<Suit> suit_;
- std::string modifier_;

The `modifier_` is where the Jokers will act, this is the "powers" that happen in the game.

### The Methods
!!! Note:
	The methods appear in an order without importance.

<!--esto es un template -->

## 🧩 Attributes

| Name | Type | Description |
|------|------|-------------|
| `_cards` | `list[Card]` | Internal list of cards currently in the deck |
| `_discard_pile` | `list[Card]` | Tracks discarded cards |

---

## ⚙️ Constructors

| Signature | Description |
|------------|-------------|
| `Deck()` | Creates and initializes a full deck of 52 cards. |

---

## 🧮 Methods

### ▶️ `shuffle() -> None`
**Description:**  
Randomly shuffles the deck.

**Example:**
```python
deck = Deck()
deck.shuffle()
