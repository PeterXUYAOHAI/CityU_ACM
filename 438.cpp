/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 20367
 * Submitted at:  2016-01-30 16:05:09
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    438
 * Problem Name:  Party
 */

#include <iostream>
#include <string>

using namespace std;

int main(){
	int caseNum = 0 ;
	cin>>caseNum;
	while (caseNum--){
		int people = 0;
		cin>>people;

		if (people == 1 || people ==2)
			cout<<0<<endl;
		else
			cout<<(people-2)<<endl;

	}


}