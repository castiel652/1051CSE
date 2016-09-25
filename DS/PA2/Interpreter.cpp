#include <iostream>
#include <string>

using namespace std;

int main()
{
	int RAM[1000];
	int Reg[10];
	int testcase;
	int input;
	int count = 0;
	return 0;
	cin >> testcase;

	for(int i = 0; i < testcase; ++i) {
		fill(RAM, RAM + 1000, 0);
		fill(Reg, Reg + 10, 0);
		
		for(int j = 0; j < 1000; ++j) {
			if(cin.eof())
				break;
			cin >> RAM[j];
		}

		for(int j = 0; j < 1000; ++j) {
			if(RAM[j] / 100 == 1)
				break;
			else if(RAM[j] / 100 == 2)
				Reg[((RAM[j] / 10) % 10)] = RAM[j] % 10;
			else if(RAM[j] / 100 == 3)
				Reg[((RAM[j] / 10) % 10)] += RAM[j] % 10;
			else if(RAM[j] / 100 == 4)
				Reg[((RAM[j] / 10) % 10)] *= RAM[j] % 10;
			else if(RAM[j] / 100 == 5)
				Reg[((RAM[j] / 10) % 10)] = Reg[RAM[j] % 10];
			else if(RAM[j] / 100 == 6)
				Reg[((RAM[j] / 10) % 10)] += Reg[RAM[j] % 10];
			else if(RAM[j] / 100 == 7)
				Reg[((RAM[j] / 10) % 10)] *= Reg[RAM[j] % 10];
			else if(RAM[j] / 100 == 8)

		}
	}
}
