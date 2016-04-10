#include <iostream>
#include <string>
#include <queue>

using namespace std;


struct newString{
	string str;
	bool operater<(const newString &str2)const{
		return strcmp(str,str2.str)<0;
	}
};



int main(){
	string newInput;
	string subInput;
	while (cin>>newInput){
		priority_queue<newString> q;
		subInput="";
		for (int i = 0; i < newInput.length(); ++i)
		{
			char temp = newInput[i];
			if(temp>='A'&&temp<='Z')
				subInput+=temp+('a'-'A');
			else if(temp>='a'&&temp<='z')
				subInput+=temp;
			else{
				q.push(subInput);
				subInput="";
			}
		}
		q.push(subInput);
	}

	string tempOutput;
	while(!q.empty()){
		q.pop();
	}


}