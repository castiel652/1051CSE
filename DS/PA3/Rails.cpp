#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int Max;
	int input = 1;
	stack<int> B; // Store coach
	queue<int> Asked; // asked form

	while(1) {
		cin >> Max; // Maximum digits
		if(Max == 0)
			break;
		while(1) {
			cin >> input;
			if(!input) // input 0
				break;
			Asked.push(input);
			for(int i = 1; i < Max && input != 0 ; ++i) {
				cin >> input;
				Asked.push(input);
			}

			for(int i = 1; i <= Max; ++i) {
				B.push(i);
				while(B.size() && B.top() == Asked.front()) { // if top equals front, pop.
					B.pop();
					Asked.pop();
				}
			}

			if(B.size() > 0)
				cout << "No" << endl;
			else
				cout << "Yes" << endl;
			while(!B.empty())
				B.pop();
			while(!Asked.empty())
				Asked.pop();
		}

		cout << endl;
	}

	return 0;
}
