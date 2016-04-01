/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 21935
 * Submitted at:  2016-02-25 19:45:59
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    266
 * Problem Name:  Cow Contest
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
	int n,m;
	
	while(cin>>n){
    cin>>m;
	int score[200];
	int winTable[200][200];

	memset (score, 0, sizeof(score));
	memset (winTable, 0, sizeof(winTable));

	for (int i=0; i<m; i++){
		int win;
		int lose;
		cin>>win>>lose;
		winTable[win][lose] = 1;
	}

	for(int i=1; i<=n;i++){
		for(int j=1; j<=n; j++){
			for (int k=1; k<=n; k++)
				if(winTable[j][i]&&winTable[i][k])
					winTable[j][k]=1;
			}
		}
	

	int result = 0;

	for(int i=1;i<=n;i++){
		for(int j=1; j<=n; j++){
			if(i==j) continue;
		 	if(winTable[i][j]){
				score[i]++;
				score[j]++;
		 	}
		}
	}

	for(int i=1;i<=n;i++){
		if(score[i]==n-1)
			result++;
	}

	cout<<result<<endl;
}


}