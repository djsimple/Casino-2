#include <iostream>
#include "blackjack.h"

using namespace std;

BlackJack::BlackJack() : person(0)
{
	Reset();

}
void BlackJack::Reset()
{
	delete[] person;
	memset(bjCount, 0, 2);
	person = new Player[playerCount];
	//deck.HandDisplay(deck.GetSize(), deck.GetDeck());
	// person[0] is dealer
	person[1].DrawCard(2, deck);

	// person[1] is player 1
	person[0].DrawCard(2, deck);
}

BlackJack::~BlackJack()
{
	delete[] person;
}

int BlackJack::Play(const int winnings)
{
	int money = winnings; //money win
	bool dealerWins = false; //dealer auto-win
	bool blackJack = false; //player auto-win blackJack
	bool inPlay = true;
	bool goodSelection; // error checking
	int bet;
	char decision; // char input
	while (inPlay)
	{
		Reset();// reset game
		cout << endl;
		cout << "--------------" << endl;
		cout << "BlackJack-Open" << endl;
		cout << "--------------" << endl;

		cout << "How much do you want to bet?" << endl;
		cout << "Current Balance : $" << money << endl;
		cout << endl << "Amount : $";

		cin >> bet;
		while (bet <= 0 || bet > money)
		{
			cout << "Invalid amount, Try Again" << endl;
			cout << "Amount : $";
			cin >> bet;
		}

		CountCards(person);
		cout << endl << "Dealer Hand" << endl;
		DealerDisplay(person[0].GetHand());

		cout << endl << "Your Hand : " << bjCount[1] << endl;
		deck.HandDisplay(person[1].CardsInHand(), person[1].GetHand());

		if (bjCount[0] == 21)
		{
			cout << "DEALER BLACKJACK!!";
			dealerWins = true;
		}
		else if (bjCount[1] == 21)
		{
			cout << "BLACKJACK!!" << endl;
			cout << endl << "Dealer Hand : " << bjCount[0] << endl;
			deck.HandDisplay(person[0].CardsInHand(), person[0].GetHand());
			blackJack = true;
		}

		goodSelection = false;
		while (!goodSelection && !dealerWins && !blackJack)
		{

			cout << "Hit or Stay? (H/S)";
			cin >> decision;
			if (toupper(decision) == 'H')
			{
				cout << endl << "Dealer Hand" << endl;
				DealerDisplay(person[0].GetHand());
				person[1].DrawCard(1, deck);
				CountCards(person);
				cout << endl << "Your Hand : " << bjCount[1] << endl;
				deck.HandDisplay(person[1].CardsInHand(), person[1].GetHand());
				if (bjCount[1] > 21)
				{
					cout << endl << "You BUSTED!";
					dealerWins = true;
					goodSelection = true;
				}
			}
			else if (toupper(decision) == 'S')
			{
				while (bjCount[0] <= 16)
				{
					person[0].DrawCard(1, deck);
					CountCards(person);
				}

				cout << endl << "Dealer Hand : " << bjCount[0] << endl;
				deck.HandDisplay(person[0].CardsInHand(), person[0].GetHand());
				if (bjCount[0] > 21)
				{
					cout << endl << "DEALER BUSTED!";
				}
				goodSelection = true;
			}
			else
			{
				cout << endl << "!Invalid Selection!" << endl;
			}
		}

		if (bjCount[0] >= bjCount[1] && bjCount[0] <= 21 || dealerWins)
		{
			money -= bet;
			cout << endl << "THE DEALER WINS!";
			cout << endl << "You lost: $" << bet << endl;
		}
		else if (bjCount[1] <= 21)
		{
			money += bet;
			cout << endl << "You Win : $" << bet << endl;
		}
		if (money == 0)
		{
			cout << endl;
			cout << "Current Balance : $" << money << endl;
			cout << "YOU'RE BROKE!!!" << endl;
			cout << "BYE!" << endl;
			cout << endl;
			return money;
		}

		dealerWins = false;
		blackJack = false;
		goodSelection = false;

		while (!goodSelection)
		{
			cout << "Do you want to continue (Y/N)?" << endl;
			cout << "Selection : ";
			cin >> decision;
			if (toupper(decision) == 'Y')
			{
				goodSelection = true;
			}
			else if (toupper(decision) == 'N' || toupper(decision) == 'X')
			{
				goodSelection = true;
				inPlay = false;
			}
			else
			{
				cout << endl << "!Invalid Selection!" << endl;
			}

		}
	}
	cout << "You finished with: " << money << endl;
	return money;
}
void BlackJack::DealerDisplay(const Card* dealer) const
{
	cout << endl;
	cout << "|---------|" << "  " << "|---------|" << endl;
	cout << "|         |" << "  " << "|  X   X  |" << endl;
	cout << "|         |" << "  " << "|    X    |" << endl;
	cout << "| ";
	deck.DisplayCard(dealer[0]);
	cout << "  |" << "  " << "|  X   X  |" << endl;
	cout << "|         |" << "  " << "|  X   X  |" << endl;
	cout << "|         |" << "  " << "|    X    |" << endl;
	cout << "|         |" << "  " << "|  X   X  |" << endl;
	cout << "|---------|" << "  " << "|---------|" << endl;
	cout << endl;

}

void BlackJack::CountCards(const Player* person)
{
	int addition;
	int count;
	int aceCount;

	for (int j = 0; j < playerCount; j++)
	{
		addition = 0;
		count = 0;
		aceCount = 0;
		int total = person[j].CardsInHand();
		cout << endl;
		for (int i = 0; i < total; i++)
		{
			addition = person[j].GetHand()[i].GetValue();

			if (addition == 1)
			{
				aceCount++;
				addition = 11;
			}
			else if (addition > 10)
			{
				addition = 10;
			}
			count += addition;
		}

		while (count > 21 && aceCount > 0)
		{
			count -= 10;
			--aceCount;
		}

		bjCount[j] = count;
	}

}
Deck BlackJack::GetDeck() const
{
	return deck;
}