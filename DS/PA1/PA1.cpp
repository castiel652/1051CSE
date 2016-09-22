#include <iostream>

using namespace std;

struct Card{
	int Suit;
	int Rank;
};

struct Hand{
	Card HandCard[5];
	Card Pair1[5];
	Card Pair2[5];
	int type1;
	int type2;
	bool twopair;
};

int ConvertRank(char Rank)
{
	if(Rank == 'J')
		return 11;
	else if(Rank == 'Q')
		return 12;
	else if(Rank == 'K')
		return 13;
	else if(Rank == 'T')
		return 10;
	else if(Rank == 'A')
		return 14;
	else
		return (Rank - '0');
}

int ConvertSuit(char Suit)
{
	if(Suit == 'C')
		return 1;
	else if(Suit == 'D')
		return 2;
	else if(Suit == 'H')
		return 3;
	else if(Suit == 'S')
		return 4;
}

bool St(Card input[]) //Straight
{
	if(input[0].Rank == input[1].Rank + 1 && input[1].Rank == input[2].Rank + 1 && input[2].Rank == Card[3].Rank + 1 && Card[3].Rank == Card[4].Rank + 1)
		return true;
	return false;
}

bool FK(Card input[]) //Four of a Kind
{
	for(int i = 0; i < 2; i++)
	{
		for( int a = i + 1; a < 5; ++a)
		{
			if((a == 3 || a == 4) && input[i].Suit == input[a].Suit)
				return true;
			if(input[i].Suit != input[a].Suit)
				break;
		}
	}
	return false;
}

bool Sf(Card input[]) //Straight Flush
{
	if(input[0].Suit == input[1].Suit == input[2].Suit == input[3].Suit == input[4].Suit)
	{
		if(St(input[6]))
		return true;
	}
	return false;
}

void sort(&Card input[])
{
	Card temp;
	for(int i = 0; i < 5; ++i)
	{
		for(int a = i + 1; a < 5; ++i)
		{
			if(input[i].Rank < input[a].Rank)
			{
				temp.Suit = input[i].Suit;
				temp.Rank = input[i].Rank;
				input[i].Suit = input[a].Suit;
				input[i].Rank = input[a].Rank;
				input[a].Suit = temp.Suit;
				input[a].Rank = temp.Rank;
			}
		}
	}
}

bool (*type)(Card[]) = {, HC, Pa, TP, TK, St, Fl, FH, FK, Sf};

int main()
{
	char input[21];
	Hand Player1;
	Hand Player2;

	while(getline(cin, input))
	{
		for(int i = 0; i < 10; ++i)
		{
			if(i % 2 == 0)
				Player1.HandCard[i].Suit = ConvertSuit(input[i]);
			else
				Player1.HandCard[i].Rank = ConvertRank(input[i]);
		}
		Sort(Player1.HandCard[6]);
		for(int i = 11; i < 20; ++i)
		{
			if(i % 2 == 0)
				Player2.HandCard[i].Suit = ConvertSuit(input[i]);
			else
				Player2.HandCard[i].Rank = ConvertRank(input[i]);
		}
		Sort(Player2.HandCard[6]);
	}

	return 0;
}
