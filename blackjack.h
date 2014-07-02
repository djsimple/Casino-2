#ifndef _H_BKJK
#define _H_BKJK
#include "deck.h"
#include "player.h"

using namespace std;
static const int playerCount = 2;

class BlackJack
{
public:
	BlackJack();
	BlackJack(int);
	~BlackJack();
	void Play(int&);
	void DealerDisplay(const Card*) const;
	void CountCards(const Player*);
	Deck GetDeck() const;
	void Reset();

private:

	int bjCount[playerCount];
	Player* person;
	Deck deck;

};

#endif
