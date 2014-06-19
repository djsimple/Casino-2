#include "deck.h"
#include <string>
#include <time.h>
#include <iomanip>
#include <iostream>
using namespace std;


// BUILDING A CARD DECK W/ SHUFFLE
Deck::Deck() : currentSize(deckSize)
{
	deck = new Card[deckSize];
	for (int i = 0; i < 52; i++)
	{
		deck[i].SetSuit(i % 4);
		deck[i].SetValue(i % 13 + 1);
	}

	Shuffle();
}

Deck::Deck(int size)
{
	deck = new Card[size];
	currentSize = size;
}

Deck::~Deck()
{
	delete[] deck;
}

Deck& Deck::operator= (const Deck& update)
{
	if (this != &update)
	{
		delete[] deck;
		currentSize = update.currentSize;
		deck = new Card[currentSize];
		for (int i = 0; i < currentSize; i++)
		{
			deck[i] = update.deck[i];
		}

	}
	return *this;
}

void Deck::Shuffle()
{
	srand(time(NULL));
	Card temp;
	int random;
	for (int i = 0; i < currentSize; i++)
	{
		random = rand() % (currentSize - 1);
		temp = deck[i];
		deck[i] = deck[random];
		deck[random] = temp;

	}
}

void Card::SetSuit(int card)
{
	if (card == Spade)
	{
		suit = Spade;
	}
	else if (card == Heart)
	{
		suit = Heart;
	}
	else if (card == Diamond)
	{
		suit = Diamond;
	}
	else if (card == Club)
	{
		suit = Club;
	}
}

void Card::SetValue(int card)
{
	value = card;
}

int Card::GetValue() const
{
	return value;
}

CardSuit Card::GetSuit() const
{
	return suit;
}

int Deck::GetSize() const
{
	return currentSize;
}

void Deck::DisplayCard(const Card card) const
{
	string CardValues[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	cout << setw(2) << right << CardValues[card.GetValue() - 1];
	DisplaySuit(card.GetSuit());
}

void Deck::DisplaySuit(CardSuit suit) const
{
	if (suit == Spade)
	{
		cout << " SPD";
	}
	else if (suit == Diamond)
	{
		cout << " DMD";
	}
	else if (suit == Heart)
	{
		cout << " HRT";
	}
	else if (suit == Club)
	{
		cout << " CLB";
	}
}

void Deck::HandDisplay(const int n, Card* card) const
{
	int rows = n / 5 + 1; // number of rows
	int diff;
	for (int z = 0; z < rows; z++){
		if (z + 1 < rows)
		{
			diff = 5;
		}
		else
		{
			diff = n % 5;
		}
		cout << endl;
		DrawEdge(diff);
		DrawMiddle(2, diff);
		for (int i = 0; i < diff; i++){
			cout << "| ";
			DisplayCard(card[i + (z * 5)]);
			cout << "  |" << "  ";
		}
		cout << endl;
		DrawMiddle(3, diff);
		DrawEdge(diff);
		cout << endl;
	}
}

void Deck::DrawMiddle(const int count, const int n) const
{
	for (int j = 0; j < count; j++){
		for (int i = 0; i < n; i++){
			cout << "|         |" << "  ";
		}
		cout << endl;
	}
}

void Deck::DrawEdge(const int n) const
{
	for (int i = 0; i < n; i++){
		cout << "|---------|" << "  ";
	}
	cout << endl;
}

Card Deck::GetCard()
{
	Card draw = deck[0];
	currentSize--;
	Deck tempDeck(currentSize);
	for (int i = 0; i < currentSize; i++)
	{
		tempDeck.deck[i] = deck[i + 1];
	};
	*this = tempDeck;
	return draw;
}

Card* Deck::GetDeck() const
{
	return deck;
}

