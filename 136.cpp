/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 22586
 * Submitted at:  2016-03-03 21:34:22
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    136
 * Problem Name:  Exact Change (UVa 11517)
 */

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int dp[20000];

int main(){
	int caseNum;
	cin>>caseNum;
	while(caseNum--){
		int amount;
		cin>>amount;
		int numOfConis;
		int max=0;
		cin>>numOfConis;
		int coins[105];
		for (int i = 1; i <= numOfConis; i++){
			cin>>coins[i];
			max+=coins[i];
		}
		
		memset(dp, 9999, sizeof(dp));
		dp[0]=0;
//		cout<<dp[1]<<endl;
		for(int i=1; i<=numOfConis; i++){
			for(int j=10005; j>=0;j--)
				if(dp[j]<99999){
//				    cout<<j<<endl<<dp[j]<<endl;
					dp[j+coins[i]]=dp[j+coins[i]]<(dp[j]+1)?dp[j+coins[i]]:(dp[j]+1);
				}
		}
	for(int i=1; i<=10005; i++)
	    if(i>=amount&&dp[i]<99999){
	        cout<<i<<" "<<dp[i]<<endl;
	        break;
	    }

	}
	
	


	}





