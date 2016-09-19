#include <iostream>

using namespace std;

struct Card {
    int Rank;
    int Suit;
};

class Hand {
  public:
    Hand(char input[6][3]);
    ~Hand();

    bool isHC();
    bool isPair();
    bool isTP();
    bool isToaK();
    bool isStraight();
    bool isFlush();
    bool isFH();
    bool isFoaK();
    bool isSf();
    void CheckType();
    int getType();

  private:
    Card HandCard[5];
    int Pair1[2];
    int Pair2[2];
    int type;
    /*
     * HC = 1
     * Pair = 2
     * TP = 3
     * ToaK = 4
     * Straight = 5
     * Flush = 6
     * FH = 7
     * FoaK = 8
     * Sf = 9
     */
};

int ConvertSuitToNumber(char suit) {
    if (suit == 'J') {
	return 11;
    } else if (suit == 'Q') {
	return 12;
    } else if (suit == 'K') {
	return 13;
    } else if (suit == 'A') {
	return 14;
    }
    return (suit - '0');
}

bool Hand::isSf() {
    if (HandCard[0].Suit == HandCard[1].Suit == HandCard[2].Suit ==
	HandCard[3].Suit == HandCard[4].Suit) {
	int c;
	for (int i = 0; i < 5; ++i) {
	    for (int a = i + 1; a < 5; ++i) {
		if (HandCard[i].Rank < HandCard[a].Rank) {
		    c = HandCard[a].Rank;
		    HandCard[a].Rank = HandCard[i].Rank;
		    HandCard[i].Rank = c;
		}
	    }
	}
	if (HandCard[0].Rank - 1 == HandCard[1].Rank &&
	    HandCard[1].Rank - 1 == HandCard[2].Rank &&
	    HandCard[2].Rank - 1 == HandCard[3].Rank &&
	    HandCard[3].Rank - 1 == HandCard[4].Rank) {
	    return true;
	}
    }
    return false;
}

bool Hand::isFoaK()
{
	int count = 0;
	for(int i = 0; i < 2; i++)
	{
		for(int a = i +1 ;a <5;++a)
		{
			if()
		}
	}
}

Hand::Hand(char input[6][3]) {
    for (int i = 0; i < 5; ++i) {
	HandCard[i].Rank = input[i][0] - '0';
	HandCard[i].Suit = ConvertSuitToNumber(input[i][1]);
    }

    for (int i = 0; i < 5; ++i) {
	if ()
    }
}

Hand::~Hand(){};

int Hand::getType() { return type; }

int main() {
    char input[6][3];
    for (int i = 0; i < 5; ++i) {
	cin >> input[i][0] >> input[i][1];
    }
    Hand Player1(input);

    for (int i = 0; i < 5; ++i) {
	cin >> input[i][0] >> input[i][1];
    }
    Hand Player2(input);

    return 0;
}
