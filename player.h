#ifndef _H_PLAYER
#define _H_PLAYER
#include "deck.h"

using namespace std;

class Player
{
public:
	Player();
	Player(int);
	~Player();
	Player& operator= (const Player&);
	void DrawCard(int, Deck&);
	void AddCard(Card);
	Card* GetHand() const;
	int CardsInHand() const;

private:
	int cards;
	Card* hand;

};

#endif