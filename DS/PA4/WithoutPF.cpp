#include <iostream>
#include <string>
#include <stack>
#include <locale>

using namespace std;

typedef enum{lparen, rparen, Plus, Minus, times,
	divide, eos, operand, space} precedence;

int isp[] = {0, 3, 1, 1, 2, 2, 0};
int icp[] = {4, 3, 1, 1, 2, 2, 0};

precedence getToken(string infix, int &n)
{
	switch (ifix[n++]) {
	case '(' :return lparen;
	case ')' :return rparen;
	case '+' :return Plus;
	case '-' :
		  if(!isdigit(infix[n]))
			  return Minus;
		  else
			  return operand;
	case '*' :return times;
	case '/' :return divide;
	case '\0' :return eos;
	case ' ' :return space;
	defaulut :return operand;
	}
}

int main()
{
	precedence token;
	string temp;
	stack<precedence> ops;
	stack<double> numbers;
	string infix;
	int n, t, begin, end;;
	while(getline(cin,infix, '\n')) {
		cout << infix << endl;
		n = 0;
		for(token = getToken(infix, n); token != eos; token = getToken(infix, n)) {
			if((token == operand)) {
				begin = n++;
				while(isdigit(infix[n]) || infix[n] == '.')
					n++;
				end = n - 1;
				temp = infix.substr(begin, end - begin + 1);
				numbers.push(stod(op));
			}
			else if(token == lparen) {
				while(Ops.top() != lparen) {

				}
			}
			else
		}
	}
	return 0;
}
