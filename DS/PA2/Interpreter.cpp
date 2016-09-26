#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

int main()
{
	int RAM[1000];
	int Reg[10];
	int testcase;
	int count = 0;
	char input[4];
	int ramcount;
	cin >> testcase;
	cin.ignore();
	cin.ignore();

	for(int i = 0; i < testcase; ++i) {
		fill(RAM, RAM + 1000, 0);
		fill(Reg, Reg + 10, 0);

		ramcount = 0;
		cout << "start to get char" << endl;
		while(gets(input)) {
			if(!strcmp(input,""))
				break;
			RAM[ramcount] = stoi(input);
			ramcount++;
		}

		cout << "ouTTTTT" << endl;

		count = 0;
		for(int j = 0; j < 1000;++j) {
			if(RAM[j] / 100 == 1)
				break;
			else if(RAM[j] / 100 == 2)
				Reg[((RAM[j] / 10) % 10)] = RAM[j] % 10;
			else if(RAM[j] / 100 == 3) {
				Reg[((RAM[j] / 10) % 10)] += RAM[j] % 10;
				Reg[((RAM[j] / 10) % 10)] %= 1000;
			}
			else if(RAM[j] / 100 == 4) {
				Reg[((RAM[j] / 10) % 10)] *= RAM[j];
				Reg[((RAM[j] / 10) % 10)] %= 1000;
			}
			else if(RAM[j] / 100 == 5)
				Reg[((RAM[j] / 10) % 10)] = Reg[RAM[j] % 10];
			else if(RAM[j] / 100 == 6) {
				Reg[((RAM[j] / 10) % 10)] += Reg[RAM[j] % 10];
				Reg[((RAM[j] / 10) % 10)] %= 1000;
			}
			else if(RAM[j] / 100 == 7) {
				Reg[((RAM[j] / 10) % 10)] *= Reg[RAM[j] % 10];
				Reg[((RAM[j] / 10) % 10)] %= 1000;
			}
			else if(RAM[j] / 100 == 8)
				Reg[((RAM[j] / 10) % 10)] = RAM[Reg[RAM[j] % 10]];
			else if(RAM[j] / 100 == 9)
				RAM[Reg[RAM[j] % 10]] = Reg[(RAM[j]/10) % 10];
			else if(RAM[j] / 100 == 0)
				if(Reg[RAM[j] % 10] != 0)
					j = Reg[(RAM[j]/10) % 10] - 1;
			count++;
			//cout << j << endl;
		}
		cout << count<< endl;
	}
	return 0;
}
