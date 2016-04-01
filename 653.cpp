/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 21499
 * Submitted at:  2016-02-19 19:19:30
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    653
 * Problem Name:  Table Cloth
 */

#include <iostream>
#include <string>

using namespace std;

int main(){
	int dep,wid;
	int map[60][60];
	while(cin>>dep){
		cin>>wid;
		if(wid==0&&dep==0)
		    break;
		for(int i=0; i<dep;i++)
			for(int j=0;j<wid;j++)
				cin>>map[i][j];

		int step = 4;

		for(int i=0; i<dep;i++){
			if(map[i][0]==1||map[i][wid-1]==1){
				step=2;
				break;
			}
		}

		for(int i=0; i<wid;i++){
			if(map[0][i]==1||map[dep-1][i]==1){
				step=2;
				break;
			}
		}
		cout<<step<<endl;



		}





	




}