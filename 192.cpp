/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 19772
 * Submitted at:  2016-01-24 14:41:02
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    192
 * Problem Name:  Not so Mobile (UVa 839)
 */

#include <iostream>
#include <string>

using namespace std;

int isGood;
int isBalanced(){
    
	int w1, d1, w2, d2;
	scanf("%d%d%d%d",&w1,&d1,&w2,&d2);

if(w1 && w2 && d1 && d2){
    if ((w1*d1)==(w2*d2))
		return (w1+w2);
	else{
	    isGood=0;
		return 0;
	}
}
else{
	if(w1==0)
		w1 = isBalanced();
	if(w2==0)
		w2 = isBalanced();
	 if ((w1*d1)==(w2*d2))
		return (w1+w2);
	else{
	    isGood=0;
		return 0;
	}
	
}
	
}

		
int main(){
	int nums;
	int result;
	string empty;
	cin>>nums;

	for(int i=0; i<nums; i++){
        isGood = 1;
        isBalanced();
		if (isGood==0)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
		if(i<(nums-1))
		    cout<<endl;
		
	} 

	return 0;



}
