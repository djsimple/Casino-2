#include <iostream>
#include <cstring>
#include "blackjack.h"

using namespace std;


int main()
{
	BlackJack blackjack;
	char decision;
	int money = 500;
	bool gamble = true;
	while (gamble && money > 0)
	{
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
			money = blackjack.Play(money);
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

