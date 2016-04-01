#include <iostream>
#include <string>
#include <stack>

using namespace std;

int priority(char a){
	int temp;
	if (a == '(')
		temp = 1;
	else if (a == '*')
		temp = 2;
	else if (a == '+')
		temp = 3;
	return temp;

}

int change(char a){
	if(a=='A')
		return 10;
	else if (a=='B')
		return 11;
	else if (a=='C')
		return 12;
	else if (a=='D')
		return 13;
	else if (a=='E')
		return 14;
	else if (a=='F')
		return 15;
	else
		return (a - '0');
}




int main(){


	string input;


	while(cin>>input){
	stack<char> opStack;
	
	string postfix = "";
	for (int i = 0; i<input.length(); i++){
		char income = input[i];

		if (income == '*' || income == '+'){
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

 
	stack<int> oS;
	oS.push(change(postfix[0]));
	oS.push(change(postfix[1]));
	for(int i=2; i<postfix.length(); i++){
		char come = postfix[i];
		if (come=='+'){
			int t1 = oS.top();
			oS.pop();
			int t2 = oS.top();
			oS.pop();
			oS.push(t1+t2);
			} 
		else if (come== '*'){
			int t1 = oS.top();
			oS.pop();
			int t2 = oS.top();
			oS.pop();
			oS.push(t1*t2);
		}

		else
			oS.push(change(come));

	}


	cout<<hex<<uppercase<<oS.top()<<endl;

}
}