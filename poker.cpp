//TODO: integrate into game, written code was used for a programming competition question
//refactor a LOT xD

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int chartonum(char x);
int checkflush(const vector<string>& p);
int checkstraight( const vector<string>& p);
int four(const vector<string>& p);
int three(const vector<string>& p);
vector<int> two(const vector<string>& p);
void checkWin(bool p1, bool p2);

int chartonum(char x)
{
	if (x == 'A')
	{
		return 14;
	}
	else if (x == 'K')
	{
		return 13;
	}
	else if (x == 'Q')
	{
		return 12;
	}
	else if (x == 'J')
	{
		return 11;
	}
	else if (x == 'T')
	{
		return 10;
	}
	else
	{
		return x - '0';
	}
}

int checkflush( const vector<string>& p)
{
	char card = p[0][1];
	int maxCard = p[0][0] - '0';

	for (int i = 1; i < 5; i++)
	{
		if (p[i][1] != card) return -1;
		maxCard = max(maxCard, chartonum(p[i][0]));
	}
	return maxCard;
}
int checkstraight( const vector<string>& p)
{
	vector<int> nums;
	for (int i = 0; i < 5; i++)
	{
		nums.push_back(chartonum(p[i][0]));
	}
	sort(nums.begin(), nums.end());
	int num = nums[0];
	//cout << "straight numbers" << endl;
	//cout << num << endl;
	for (int i = 1; i < 5; i++)
	{
	//	cout << nums[i] << endl;
		if (num + 1 != nums[i]) return -1;
		num++;
	}
	return nums[4];
}
int four(const vector<string>& p)
{
	unordered_map<char, int> matches;
	for (int i = 0; i < 5; i++)
	{
		char val = p[i][0];
		if (matches.find(val) == matches.end())
		{
			matches[val] = 0;
		}
		matches[val]++;
	}
	if (matches.size() != 2) return -1;
	for (auto it = matches.begin(); it != matches.end(); ++it)
	{
		if (it->second == 4)
		{
			return chartonum(it->first);
		}
	}
	return -1;
}
int three(const vector<string>& p)
{
	unordered_map<char, int> matches;
	
	for (int i = 0; i < 5; i++)
	{
		char val = p[i][0];
		if (matches.find(val) == matches.end())
		{
			matches[val] = 0;
		}
		matches[val]++;
	}
	for (auto it = matches.begin(); it != matches.end(); ++it)
	{
		if (it->second == 3)
		{
			return chartonum(it->first);
		}
	}
	return -1;
}
vector<int> two(const vector<string>& p)
{
	unordered_map<char, int> matches;
	vector<int> result;
	for (int i = 0; i < 5; i++)
	{
		char val = p[i][0];
		if (matches.find(val) == matches.end())
		{
			matches[val] = 0;
		}
		matches[val]++;
	}
	for (auto it = matches.begin(); it != matches.end(); ++it)
	{
		if (it->second == 2)
		{
			result.push_back(chartonum(it->first));
		}
	}
	return result;
}

void checkWin(bool p1, bool p2)
{
	if (p1)
	{
		cout << "PLAYER 1" << endl;
		return;
	}
	if (p2)
	{
		cout << "PLAYER 2" << endl;
		return;
	}
	cout << "TIE" << endl;
}
void highestwinner(const vector<string>& a, const vector<string>& b)
{
	vector<int> p1, p2;
	for (int i = 0; i < 5; i++)
	{
		p1.push_back(chartonum(a[i][0]));
		p2.push_back(chartonum(b[i][0]));
	}
	sort(p1.begin(), p1.end());
	sort(p2.begin(), p2.end());
	for (int i = 0; i < 5; i++)
	{
		if (p1[4 - i] != p2[4 - i])
		{
			if (p1[4 - i] > p2[4 - i])
			{
				checkWin(true, false);
				return;
			}
			else
			{
				checkWin(false, true);
				return;
			}
		}
	}
	checkWin(false, false);
}


int main()
{
	int round;
	string input;
	cin >> round;
	cin.ignore();
	for (int i = 0; i < round; i++)
	{
		vector<string> player1, player2;
		for (int j = 0; j < 5; j++)
		{
			string next;
			cin >> next;
			player1.push_back(next);
		}
		for (int j = 0; j < 5; j++)
		{
			string next;
			cin >> next;
			player2.push_back(next);
		}
		int p1straight = checkstraight(player1), p2straight = checkstraight(player2);
		int p1flush = checkflush(player1), p2flush = checkflush(player2);
		int p1four = four(player1), p2four = four(player2);
		int p1three = three(player1), p2three = three(player2);
		vector<int> p1pair = two(player1), p2pair = two(player2);

		
		if ((p1straight > -1 && p1flush > -1) || (p2straight > -1 && p2flush > -1))
		{
			checkWin(p1straight > p2straight, p2straight > p1straight);
			continue;
		}
		else if (p1four > -1 || p2four > -1)
		{
			if (p1four == p2four)
			{
				highestwinner(player1, player2);
			}
			else
			{
				checkWin(p1four > p2four, p2four > p1four);
			}
			continue;
		}
		else if ((p1three > -1 && p1pair.size() == 1) || (p2three > -1 && p2pair.size() == 1))
		{
			if (p1pair.size() == 1 && p2pair.size() == 1)
			{
				if (p1three == p2three)
				{
					highestwinner(player1, player2);
				}
				else
				{
					checkWin(p1three > p2three, p2three > p1three);
				}
			}
			else if (p1pair.size() == 1)
			{
				checkWin(true, false);
			}
			else
			{
				checkWin(false, true);
			}			
			continue;
		}
		else if (p1pair.size() == 2 || p2pair.size() == 2)
		{
			if (p1pair.size() == 2 && p2pair.size() == 2)
			{
				highestwinner(player1, player2);
			}
			else if (p1pair.size() == 2)
			{
				checkWin(true, false);				
			}
			else 
			{
				checkWin(false, true);
			}	
			continue;
		}
		highestwinner(player1, player2);
	}

	return 0;
}

