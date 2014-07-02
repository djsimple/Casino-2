#include <iostream>
#include <string>
#include <time.h>
#include "blackjack.h"

using namespace std;


int main()
{
	BlackJack blackjack;
	string loseMsg[10] =
	{
		"You sell your kidneys to a shady dude!", //0
		"You find some money while crying on the toilet!",
		"You looked through your stuff and found more money!",
		"You sold your kids!",
		"You mortgage your house!",
		"You turn in an FBI most wanted man in the lobby!",
		"You discover a briefcase of money in the elevator!",
		"You found some chips that were dropped!", //7
		"You steal some cash from a tip bucket by the beer bin!",
		"You passed go! Time to collect!"// 9
	};

	char decision;
	int money = 500;
	bool gamble = true;
	srand(time(NULL));
	while (gamble)
	{
		if (money <= 0)
		{
			int random;
			random = rand() % 10;
			money = 500;
			cout << loseMsg[random] << endl << "+ $" << money << endl;


		}
		cout << "--------------" << endl;
		cout << "Gambling Arena" << endl;
		cout << "--------------" << endl;
		cout << "Current : $" << money << endl;
		cout << "1 for BlackJack: Open Bid" << endl;
		cout << "X for eXit" << endl << endl;
		cout << "Menu Selection : ";
		cin >> decision;
		switch (toupper(decision))
		{
		case '1':
			blackjack.Play(money);
			break;
		case 'X':
			gamble = false;
			break;
		default:
			cout << endl << "!Invalid Selection!"  << endl;
			break;
		}
	}

	return 0;
}

