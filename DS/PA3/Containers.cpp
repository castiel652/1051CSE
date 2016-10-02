#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int Case = 0;
	string input;
	int convert = 0;
	vector<int> Stack;

	while(1) {
		cin >> input;
		if(!input.compare("end")) // end the program if entered "end"
			break;
		Stack.push_back(-1); //at least used one stack and set the value to -1
		Case++;
		for(int i = 0; i < input.length(); ++i) {
			convert = input[i] - 'A'; // convert to int but minus the value of A
			for(int j = 0; j < Stack.size(); ++j) {
				if(Stack[j] >= convert || Stack[j] == -1) { //if the value of convert is larger than the current value or it still doesn't have container yet
					Stack[j] = convert; 
					break;
				}
				if( j == Stack.size() - 1 && Stack[j] < convert) {
					Stack.push_back(convert);
					break;
				}
			}
		}
		cout << "Case " << Case << ": " << Stack.size() << endl;
		Stack.clear();
	}
	return 0;
}
