/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 24659
 * Submitted at:  2016-04-10 23:51:00
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    185
 * Problem Name:  Andy's First Dictionary (UVa 10815)
 */

#include <iostream>
#include <string>
#include <queue>
#include <string.h>

using namespace std;


struct newString{
	string str;
	bool operator< (const newString &str2)const{
		return strcmp(str.c_str(), str2.str.c_str())>0;
	}
};

	priority_queue<newString> q;

int main(){
	string newInput;
	string subInput;

	while (cin >> newInput){
		
		subInput = "";
		newString newOne;
		for (int i = 0; i < newInput.length(); ++i)
		{

			char temp = newInput[i];
			if (temp >= 'A'&&temp <= 'Z')
				subInput += temp + ('a' - 'A');
			else if (temp >= 'a'&&temp <= 'z')
				subInput += temp;
			else{
				newOne.str = subInput;
				q.push(newOne);
				subInput = "";
			}
		}
		if (subInput != ""){
			newOne.str = subInput;
			q.push(newOne);
		}
	}

	string tempOutput;
	while (!q.empty()){
		newString poped = q.top();
		q.pop();
		if (tempOutput == poped.str)
			continue;
		tempOutput = poped.str;
		cout << tempOutput << endl;
	}

}
