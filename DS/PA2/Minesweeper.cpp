#include <iostream>
#include <string>

using namespace std;

void 

int main()
{
	int count = 0;
	string *field;
	char input
	int n, m;

	while(1) {
		cin >> n;
		cin >> m;

		if( n == m == 0)
			break;

		field = new string[m + 1];

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				cin >> input; 
				//ifield[i].resize(field[i].size() + 1);
				field[i].push_back(input);
			}
		}

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if( field[i][j] == '.')
					field[i][j] = '0';
			}
		}

		delete field[];
	}
	return 0;
}
