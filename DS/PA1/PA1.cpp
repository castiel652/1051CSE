#include <iostream>

using namespace std;

struct Card
{
	int Rank;
	int Suit;
};

Class Hand
{
	public:
		Hand( char input[6][3] );
		void CheckType();
	private:
		Card HandCard[5];
		int Pair1[2];
		int Pair2[2];
};

int ConvertSuitToNumber( char suit )
{
	if ( suit == J )
	{
		return 11;
	}
	else if ( suit == Q )
	{
		return 12;
	}
	else if ( suit == K )
	{
		return 13;
	}
	else if ( suit == A )
	{
		return 14;
	}
	return ( suit - '0' );
}


Hand::Hand( char input[6][3] )
{
	for( int i = 0; i < 5; ++i )
	{
		HandCard[i].Rank = input[i][0] - '0';
		HandCard[i].Suit = ConvertSuitToNumber( input[i][1] );
	}
}


int main()
{
	char case[6][3];
	for( int i = 0; i < 5, ++i )
	{
		cin >> case[i][1] >> case[i][2];
	}
	Hand Player1( case );

	return 0;
}
