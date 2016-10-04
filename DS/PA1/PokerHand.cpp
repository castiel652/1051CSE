#include <iostream>
#include <string>

using namespace std;

struct Player {
	int Cards[5];
	int Suits[5];
	int Rank;
	int *RankScore;
};

void getCards(Player &player, string Cards, int n)
{
	for(int i = 0, j = n; i < 5; ++i, j+=3) {
		if(Cards[j] == 'T')
			player.Cards[i] = 10;
		else if(Cards[j] == 'J')
			player.Cards[i] = 11;
		else if(Cards[j] == 'Q')
			player.Cards[i] = 12;
		else if(Cards[j] == 'K')
			player.Cards[i] = 13;
		else if(Cards[j] == 'A')
			player.Cards[i] = 14;
		else
			player.Cards[i] = Cards[j] - '0';
		if(Cards[j+1] == 'C')
			player.Suits[i] = 1;
		else if(Cards[j+1] == 'D')
			player.Suits[i] = 2;
		else if(Cards[j+1] == 'H')
			player.Suits[i] = 3;
		else if(Cards[j+1] == 'S')
			player.Suits[i] = 4;

	}
}

void Sort(Player &player)
{
	int temp; // temp value
	for(int i = 0; i < 5; ++i) {
		for(int j = i + 1; j < 5; ++j) {
			if(player.Cards[i] < player.Cards[j]) {
				temp = player.Cards[i];
				player.Cards[i] = player.Cards[j];
				player.Cards[j] = temp;

				temp = player.Suits[i];
				player.Suits[i] = player.Suits[j];
				player.Suits[j] = temp;
			}
		}
	}
}

bool isSF(Player &player)
{
	for(int i = 1; i < 5; ++i) {
		if(player.Suits[i] != player.Suits[0])
			return false;
	}

	for(int i = 0; i < 4; ++i) {
		if((player.Cards[i] - 1) != player.Cards[i + 1])
			return false;
	}

	player.Rank = 9;
	player.RankScore = new int[1];
	player.RankScore[0] = player.Cards[0];
}

bool isFoaK(Player &player) // Four of a Kind
{
	if(player.Cards[0] == player.Cards[3] || player.Cards[1] == player.Cards[4]) {
		player.Rank = 8;
		player.RankScore = new int[1];
		player.RankScore[0] = player.Cards[2];
		return true;
	}
	return false;
}

bool isFH(Player &player)
{
	if(((player.Cards[0] == player.Cards[1]) && (player.Cards[2] == player.Cards[4])) || ((player.Cards[0] == player.Cards[2]) && (player.Cards[3] == player.Cards[4]))) {
		player.Rank = 7;
		player.RankScore = new int[1];
		player.RankScore[0] = player.Cards[2];
		return true;
	}
	return false;
}

bool isFlush(Player &player)
{
	for(int i = 1; i < 5; ++i) {
		if(player.Suits[i] != player.Suits[0])
			return false;
	}

	player.Rank = 6;
	player.RankScore = new int[5];
	for(int i = 0; i < 5; ++i)
		player.RankScore[i] = player.Cards[i];

	return true;
}

bool isStraight(Player &player)
{
	for(int i = 0; i < 4; ++i) {
		if((player.Cards[i] - 1) != player.Cards[i + 1])
			return false;
	}
	player.Rank = 5;
	player.RankScore = new int[1];
	player.RankScore[0] = player.Cards[0];
	return true;
}

bool isToAK(Player &player) // Three of a Kind
{
	if((player.Cards[0] == player.Cards[2]) || (player.Cards[1] == player.Cards[3]) ||( player.Cards[2] == player.Cards[4])) {
		player.Rank = 4;
		player.RankScore = new int[1];
		player.RankScore[0] = player.Cards[2];
		return true;
	}
	return false;
}

bool isTP(Player &player) //Two Pair
{
	if((player.Cards[0] == player.Cards[1]) && (player.Cards[2] == player.Cards[3])) {
		player.Rank = 3;
		player.RankScore = new int[3];
		player.RankScore[0] = player.Cards[0];
		player.RankScore[1] = player.Cards[2];
		player.RankScore[2] = player.Cards[4];
		return true;
	}
	if((player.Cards[1] == player.Cards[2]) && (player.Cards[3] == player.Cards[4])) {
		player.Rank = 3;
		player.RankScore = new int[3];
		player.RankScore[0] = player.Cards[1];
		player.RankScore[1] = player.Cards[3];
		player.RankScore[2] = player.Cards[0];
		return true;
	}
	if((player.Cards[0] == player.Cards[1]) && (player.Cards[3] == player.Cards[4])) {
		player.Rank = 3;
		player.RankScore = new int[3];
		player.RankScore[0] = player.Cards[0];
		player.RankScore[1] = player.Cards[3];
		player.RankScore[2] = player.Cards[2];
		return true;
	}
	return false;
}

bool isPair(Player &player)
{
	int pp = -1; // pair position
	for(int i = 0; i < 4; ++i) {
		if(player.Cards[i] == player.Cards[i + 1]) {
			pp = i;
			break;
		}
	}

	if(pp != -1) {
		player.Rank = 2;
		player.RankScore = new int[4];
		player.RankScore[0] = player.Cards[pp];
		for(int i = 0, j = 1; i < 5; ++i) {
			if((i != pp) && (i != pp + 1)) {
				player.RankScore[j] = player.Cards[i];
				j++;
			}
		}
		return true;
	}
	return false;
}

bool isHC(Player &player) //High Card
{
	player.Rank = 1;
	player.RankScore = new int[5];
	for(int i = 0; i < 5; i++) {
		player.RankScore[i] = player.Cards[i];
	}
	return true;
}

void Scompare(Player &player1, Player &player2, int n)
{
	for(int i = 0; i < n; ++i) {
		if(player1.RankScore[i] > player2.RankScore[i]) {
			cout << "Black wins." << endl;
			return;
		}
		else if(player1.RankScore[i] < player2.RankScore[i]) {
			cout << "White wins." << endl;
			return;
		}
	}
	cout << "Tie." << endl;
}

void Fcompare(Player &player1, Player &player2) // First round
{
	if(player1.Rank > player2.Rank)
		cout << "Black wins." << endl;
	else if(player1.Rank < player2.Rank)
		cout << "White wins." << endl;
	else if(player1.Rank == 1)
		Scompare(player1, player2, 5);
	else if(player1.Rank == 2)
		Scompare(player1, player2, 4);
	else if(player1.Rank == 3)
		Scompare(player1, player2, 3);
	else if(player1.Rank == 4)
		Scompare(player1, player2, 1);
	else if(player1.Rank == 5)
		Scompare(player1, player2, 1);
	else if(player1.Rank == 6)
		Scompare(player1, player2, 5);
	else if(player1.Rank == 7)
		Scompare(player1, player2, 1);
	else if(player1.Rank == 8)
		Scompare(player1, player2, 1);
	else if(player1.Rank == 9)
		Scompare(player1, player2, 1);
}

void checkRank(Player &player)
{
	if(isSF(player));
	else if(isFoaK(player));
	else if(isFH(player));
	else if(isFlush(player));
	else if(isStraight(player));
	else if(isToAK(player));
	else if(isTP(player));
	else if(isPair(player));
	else if(isHC(player));
}

int main()
{
	Player Black;
	Player White;
	string Cards;

	while(getline(cin, Cards)) {
		getCards(Black, Cards, 0);
		getCards(White, Cards, 15);

		Sort(Black);
		Sort(White);
		checkRank(Black);
		checkRank(White);

		Fcompare(Black, White);

		if(Black.RankScore != NULL)
			delete[] Black.RankScore;
		if(White.RankScore != NULL)
			delete[] White.RankScore;
	}
	return 0;
}
