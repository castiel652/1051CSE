#include <iostream>
#include <list>

using namespace std;

int main()
{
	string input;
	list<char> beiju;
	list<char>::iterator j;
	while(getline(cin, input,'\n')) {
		j = beiju.begin();
		for(int i = 0; i < input.size(); ++i) {
			if(input[i] == '[') /* move to begin if encounter '[' */
				j = beiju.begin();
			else if(input[i] == ']') /* move to end if encounter ']' */
				j = beiju.end();
			else
				beiju.insert(j,input[i]);
		}
		for(list<char>::iterator it = beiju.begin(); it != beiju.end(); ++it)
			cout << *it;
		cout << endl;
		beiju.clear();
	}
	return 0;
}
