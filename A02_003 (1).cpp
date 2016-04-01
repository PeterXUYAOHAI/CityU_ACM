#include <iostream>
#include <string>

using namespace std;

int isBalanced(){
	string line;
	getline(cin, line);
	int w1, d1, w2, d2;
	w1 = line[0] - '0';
	d1 = line[2] - '0';
	w2 = line[4] - '0';
	d2 = line[6] - '0';
	int temp = 0;

	if(w1==0){
		temp = isBalanced();
		if (temp==-1)
			return -1;
		else{
			w1 = temp;
		}
	}
	if(w2==0){
		temp = isBalanced();
		if (temp==-1)
			return -1;
		else{
			w2 = temp;
		}
	}

	if (w1*d1==w2*d2)
		return (w1+w2);
	else
		return -1;
}

		
int main(){
	int nums = 0;
	int result = 0;
	string empty = 0;
	cin>>nums;

	for(int i=0; i<nums; i++){
		getline(cin, empty);
		result = isBalanced();
		if (result==-1)
			cout<<"NO"<<endl<<endl;
		else
			cout<<"YES"<<endl<<endl;
	} 

	return 0;



}

