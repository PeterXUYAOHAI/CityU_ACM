#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>
#include <cstdio>

using namespace std;

int priority(char a){
	int temp;
	if (a == '(')
		temp = 1;
	else if (a == '*' || a=='/')
		temp = 2;
	else if (a == '+' || a=='-')
		temp = 3;
	return temp;

}

int main() {

	int caseNum = 0;

	string line;
	getline(cin, line);
	caseNum = (line[0] - '0');
	getline(cin, line);

	for(int i=0; i<caseNum; i++){

	string line;
	stack<char> opStack;
	string postfix = "";
	string input = "";
	
	while(getline(cin, line) && line.length()!=0){
		input+=line[0];
	}

	for (int i = 0; i<input.length(); i++){
		char income = input[i];

		if (income == '*' || income == '+'|| income == '/'|| income == '-'){
			if(opStack.size()==0)
				opStack.push(income);
			else{
			while (opStack.size() != 0 && opStack.top()!='(' && priority(opStack.top()) <= priority(income)){
				postfix += opStack.top();
				opStack.pop();
			}
			opStack.push(income);
		}
		}
		else if (income == '(')
			opStack.push(income);
		else if (income == ')'){
			while (opStack.top() != '('){
				postfix += opStack.top();
				opStack.pop();
			}
			opStack.pop();
		}
		
		else
			postfix += income;
	}

	while (opStack.size() != 0){
		postfix += opStack.top();
		opStack.pop();
	}
	if(i!=(caseNum-1))
	cout<<postfix<<endl<<endl;
	else
		cout<<postfix<<endl;
            
}
	}









