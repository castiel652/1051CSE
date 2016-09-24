#include <iostream>
#include <string>

using namespace std;

void PostAction(int x, int y, int n, int m, char field[][101])
{
	for(int i = -1; i <= 1; ++i) {
		for(int j = -1; j <= 1; ++j) {
			if(x + i >= 0 && x + i < n)
				if(y + j >= 0 && y + j < m) {
					if(x + i == x && y + j == y)
						continue;
					if(field[x+i][y+j] == '*')
						continue;
					field[x+i][y+j] += 1;
				}
		}
	}
}
int main()
{
	int count = 0;
	char field[101][101];
	char input;
	int n, m;

	while(1) {
		cin >> n;
		cin >> m;

		if( n == 0 && m == 0)
			break;

		count++;

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				cin >> input;
				if( input == '.')
					field[i][j] = '0';
				else
					field[i][j] = input;
			}
			field[i][m] = '\0';
		}

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(field[i][j] == '*')
					PostAction(i, j, n, m, field);
			}
		}
		if(count > 1)
            cout << endl;
		cout << "Field #" << count << ":" << endl;

		for(int i = 0; i < n; ++i)
			cout << field[i] << endl;


	}
	return 0;
}
