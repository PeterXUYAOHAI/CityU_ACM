/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 20065
 * Submitted at:  2016-01-28 01:11:49
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    194
 * Problem Name:  8 Queens Chess Problem (UVa 750)
 */

#include <iostream>
#include <string>
using namespace std;

int solutionLine[100][9];
int soluCount = 0;
int temp[9];

bool noConflict(int current){
	for (int i = 0; i < current; i++){
		if (solutionLine[soluCount][i] == solutionLine[soluCount][current])
			return false;
		if ((current - i) == (solutionLine[soluCount][current] - solutionLine[soluCount][i]) || (current - i) == (-(solutionLine[soluCount][current] - solutionLine[soluCount][i])))
			return false;
	}
	return true;
}




void isSafe(int col){
	if (col == 8){
		soluCount++;
		return;
	}
	else
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < col; ++j)
			temp[j] = solutionLine[soluCount][j];
		solutionLine[soluCount][col] = i;
		if (noConflict(col)){
		isSafe((col + 1));

		for (int j = 0; j < col; ++j)
			solutionLine[soluCount][j] = temp[j];
	}

	}
	


}






int main(){
	
	int caseNum = 0;
	cin >> caseNum;
	isSafe(0);


	while (caseNum--){
		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
		int row;
		int col;
		int soluNum = 1;
		cin >> row >> col;
		for (int i = 0; i < 92; i++){
			if (solutionLine[i][col - 1] == (row - 1)){
				printf("%2d      ", soluNum);
				for (int j = 0; j < 8; j++)
				if (j != 7)
					cout << solutionLine[i][j] + 1 << " ";
				else
					cout << solutionLine[i][j] + 1 << endl;
				soluNum++;
			}
				
		}
		if (caseNum>0)
			cout << endl;
	}
	
	


}