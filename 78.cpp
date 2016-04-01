/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 21352
 * Submitted at:  2016-02-16 21:32:47
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    78
 * Problem Name:  Largest Subsequence
 */

#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int caseNum;
    cin>>caseNum;
    while(caseNum--){
	string input;
	cin>>input;
	int startP = 0;
	int length = input.length();
	string result = "";

	while(startP<length){
	int max = 0;
	int maxPos = 0;
	for(int i=startP; i<length; i++){
		char candi = input[i];
		if (candi>max){
			max = candi;
			maxPos = i;
		}
	}
	result += max;
	startP=maxPos+1;
	}

	cout<<result<<endl;
    }

}