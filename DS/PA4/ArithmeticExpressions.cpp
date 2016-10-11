#include <iostream>
#include <string>
#include <stack>
#include <sstream>


using namespace std;

enum precedence{lparen, rparen, Plus, Minus, times, divide, eos, operand};

int isp[] = {0, 3, 1, 1, 2, 2, 0}; // in-stack priority
int icp[] = {4, 3, 1, 1, 2, 2, 0}; // incoming priority

precedence getToken(string temp)
{
	if(temp == "(")
		return lparen;
	else if(temp == ")")
		return rparen;
	else if(temp == "+")
		return Plus;
	else if(temp == "-")
		return Minus;
	else if(temp == "/")
		return divide;
	else if(temp == "*")
		return times;
	else
		return operand;
}

void Cal(string infix, stack<double> &numbers, stack<precedence> &Ops)
{
	double op1, op2;
	precedence token;
	stringstream Modifier; // Used to manipulate the string
	string temp;
	Modifier << infix;
	Ops.push(eos);
	int i = 0;
	while(Modifier >> temp) { // Modifier can transfer until space
		token = getToken(temp);
		if(token == operand) // Operand which means temp is nubmer
			numbers.push(stod(temp));
		else if(token == rparen) { // Calculate the value until meeting lparen
			while(Ops.top() != lparen) {
				op2 = numbers.top();
				numbers.pop();
				op1 = numbers.top();
				numbers.pop();
				switch(Ops.top()) {
				case Plus :
					numbers.push(op1 + op2);
					break;
				case Minus :
					numbers.push(op1 - op2);
					break;
				case times :
					numbers.push(op1 * op2);
					break;
				case divide :
					numbers.push(op1 / op2);
					break;
				default  :
					break;
				}
				Ops.pop();
			}
			Ops.pop();
		}
		else {
			while(isp[Ops.top()] >= icp[token]) { //isp > icp (*/ > +-)
				op2 = numbers.top();
				numbers.pop();
				op1 = numbers.top();
				numbers.pop();
				switch(Ops.top()) {
				case Plus :
					numbers.push(op1 + op2);
					break;
				case Minus :
					numbers.push(op1 - op2);
					break;
				case times :
					numbers.push(op1 * op2);
					break;
				case divide :
					numbers.push(op1 / op2);
					break;
				default  :
					break;
				}
			}
			Ops.push(token);
		}
	}
}

int main()
{
	int lines, counts = 0; // input cases
	string infix;
	stack<double> numbers;
	stack<precedence> Ops;

	cin >> lines;
	while(getchar() != '\n');

	while(getline(cin,infix)) {
		Cal(infix, numbers, Ops);
		cout.precision(2);
		cout << fixed << numbers.top() << endl;
		counts++;
		if(counts == lines)
			break;
	}

	return 0;
}
