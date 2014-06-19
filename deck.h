#ifndef _DECK_H
#define _DECK_H

using namespace std;

static const int deckSize = 52;
enum CardSuit { Spade, Heart, Diamond, Club };

class Card
{
public:
	void SetSuit(int);
	void SetValue(int);
	int GetValue() const;
	CardSuit GetSuit() const;
protected:
	int value;
	CardSuit suit;

};

class Deck
{

public:
	Deck(); 
	Deck(int);
	~Deck();
	Card GetCard();
	int GetSize() const;
	Card* GetDeck() const;
	Deck& operator=(const Deck&);
	void Shuffle();
	void DisplayCard(const Card) const;
	void DisplaySuit(CardSuit) const;
	void DrawMiddle(const int, const int) const;
	void DrawEdge(const int) const;
	void HandDisplay(const int, Card*) const;

protected:
	int currentSize;
	Card* deck;
	
};
#endif

