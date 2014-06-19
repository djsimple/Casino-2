#include "player.h"

using namespace std;

Player::Player()
{
	cards = 0;
	hand = new Card[cards];
}

Player::Player(int card)
{
	cards = card;
	hand = new Card[cards];
}

Player::~Player()
{
	delete[] hand;
}

void Player::DrawCard(int draw, Deck &deck)
{
	int newAmount;
	if (deck.GetSize() > draw)
	{
		newAmount = cards + draw;
	}
	else
	{
		newAmount = cards + deck.GetSize();
	}
	while (newAmount > cards)
	{
		AddCard(deck.GetCard());
	}
}

Player& Player::operator= (const Player& update)
{
	if (this != &update)
	{
		delete[] hand;
		cards = update.cards;
		hand = new Card[cards];
		for (int i = 0; i < cards; i++)
		{
			hand[i] = update.hand[i];
		}
	}
	return *this;
}

void Player::AddCard(Card draw)
{
	cards++;
	Player temp(cards);
	for (int i = 0; i < cards; i++)
	{
		temp.hand[i] = hand[i];
	}
	temp.hand[cards - 1] = draw;
	*this = temp;
}

int Player::CardsInHand() const
{
	return cards;
}

Card* Player::GetHand() const
{
	return hand;
}