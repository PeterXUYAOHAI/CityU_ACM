/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 21572
 * Submitted at:  2016-02-20 13:08:19
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    689
 * Problem Name:  Rising Trend
 */

#include <iostream>
#include <string>

using namespace std;

int searchUpper(int d[], int length, int key){
	int mid;
	int upper = length - 1;
	int lower = 0;
	if (d[length - 1]<=key)
		return length;

	while (1){
		mid = (upper + lower) / 2;
		if ((upper - lower) <= 1){
			return upper;
		}
		if (d[mid] < key){
			lower = mid;
		}

		if (d[mid]>key){
			upper = mid;
		}

		if (d[mid] == key ){
		    if(d[mid+1]>key)
			    return mid+1;
			else 
			    lower=mid;
        }
	}

}

int main(){
	int length;

	while (cin >> length){
		int a[1000001];
		int dp[1000001];
		for (int i = 0; i < length; i++){
			cin>>a[i];
		}
		int len = 1;
		dp[0] = 0;
		dp[1] = a[0];
		for (int i = 1; i < length; i++){
			int pos = searchUpper(dp, len+1, a[i]);
			dp[pos] = a[i];


			if (pos>len)
				len = pos;
		}


//		int max = 0;
//		for (int i = 0; i < length; i++)
//		{
//			max = max>dp[i] ? max : dp[i];
//		}
		cout << len<<endl;
	}



}