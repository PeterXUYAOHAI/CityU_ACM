/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 21985
 * Submitted at:  2016-02-26 02:08:56
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    676
 * Problem Name:  Capital City
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
	int cityN, roadN;

	while (cin >> cityN){
		cin >> roadN;

		int adjMa[200][200] = { -1 };
		long long int distanceMa[200][200] = { 999999 };

		for (int i = 0; i < 200; i++)
		for (int j = 0; j < 200; j++)
			distanceMa[i][j] = 9999999999;

		//memset(distanceMa, 0x7F, sizeof(distanceMa));

		for (int i = 1; i <= cityN; i++)
			distanceMa[i][i] = 0;

		//cout<<distanceMa[1][2]<<endl;
		for (int i = 0; i<roadN; i++){
			int start, end, distance;
			cin >> start >> end >> distance;
			distanceMa[start][end] = distance;
			distanceMa[end][start] = distance;
		}
		// 	for(int i=1; i<=cityN; i++)
		// 	    for(int k=1;k<=cityN;k++)
		// 	        cout<<i<<k<<endl<<distanceMa[i][k]<<endl;
		//   cout<<distanceMa[1][2]<<endl; 
		//    cout<<distanceMa[1][2]<<endl<<distanceMa[2][1]<<endl;
		for (int k = 1; k <= cityN; k++)
		for (int i = 1; i <= cityN; i++){
		//	cout << i << k << endl << distanceMa[i][k] << endl;
			for (int j = 1; j <= cityN; j++)
			if (distanceMa[i][j]>(distanceMa[i][k] + distanceMa[k][j])){
				distanceMa[i][j] = distanceMa[i][k] + distanceMa[k][j];
		//		cout << i << j << endl << distanceMa[i][j] << endl;
			}

		}


		int minCity;
		long long int minDis = 99999999999;


		for (int i = 1; i <= cityN; i++){
			long long int sum = 0;
			for (int j = 1; j <= cityN; j++){

				sum += distanceMa[i][j];
			}
			//		cout<<i<<endl<<sum<<endl;
			if (sum<minDis){
				minDis = sum;
				minCity = i;
			}
		}

			cout<<minCity<<endl;
	}





}