#include <iostream>

using namespace std;

int main()
{
	int count = 0;
	char *field;
	int n, m;

	while(1) {
		cin >> n;
		cin >> m;

		if( n == m == 0)
			break;

		field = new char[n + 1][m + 1];

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j)
				cin >> field[i][j];
		}

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if( field[i][j] == '.')
					field[i][j] = '0';
			}
		}

	}
	return 0;
}
