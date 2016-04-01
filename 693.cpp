/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 20043
 * Submitted at:  2016-01-27 21:57:16
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    693
 * Problem Name:  Towers of Hanoi
 */

#include <iostream>
#include <string>

using namespace std;

int hannoiStep(int disk){
	if (disk == 1)
		return 2;
	return (3*hannoiStep(disk-1)+2);
}


int main(){
	int input;
	while (cin>>input){
		cout<<hannoiStep(input)<<endl;
	}
	

}