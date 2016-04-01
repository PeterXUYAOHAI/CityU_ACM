#include <iostream>
#include <string>
using namespace std;

int solutionLine[100][8];
int digSit[8] = {0,0,0,0,0,0,0,0};
int soluCount = 0;

bool isSafe(int col){
	if(col==8){
		soluCount++;
		return true;
	}

	for(int i=0; i<8; i++){
		solutionLine[soluCount][col]=i;
		for (int j=0; j<col; j++){
			if(i==solutionLine[soluCount][j]||(i-col)==(solutionLine[soluCount][j]-j))
				return false;
		}
			return isSafe((col+1))


	}


}




int main(){




}