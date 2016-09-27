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
	/* The Following two cin.ignore() are used to skip the two \n after testcase  */
	cin.ignore();
	cin.ignore();
	int dit; // digit in ones
	int dio; // digit in tens
	int dih; // digit in hundreds

	for(int i = 0; i < testcase; ++i) {
		fill(RAM, RAM + 1000, 0);
		fill(Reg, Reg + 10, 0);

		ramcount = 0;
		while(gets(input)) {
			if(!strcmp(input,""))
				break;
			RAM[ramcount] = stoi(input);
			ramcount++;
		}

		count = 0;
		for(int j = 0; j < 1000; ++j) {
			count++;
			dit = RAM[j] / 10 % 10;
			dio = RAM[j] % 10;
			dih = RAM[j] / 100;

			switch(dih) {
			case 0:
				if(Reg[dio] != 0)
					j = Reg[dit] - 1;
				break;
			case 1:
				j = 1000;
				break;
			case 2:
				Reg[dit] = dio;
				break;
			case 3:
				Reg[dit] += dio;
				break;
			case 4:
				Reg[dit] *= dio;
				break;
			case 5:
				Reg[dit] = Reg[dio];
				break;
			case 6:
				Reg[dit] += Reg[dio];
				break;
			case 7:
				Reg[dit] *= Reg[dio];
				break;
			case 8:
				Reg[dit] = RAM[Reg[dio]];
				break;
			case 9:
				RAM[Reg[dio]] = Reg[dit];
				break;
			}
			Reg[dit] %=1000; /* The value in Reg can't be larger than 1000 */
		}
		cout << count << endl;
		if(i < testcase - 1)
			cout << endl;
	}
	return 0;
}
