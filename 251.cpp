/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 20925
 * Submitted at:  2016-02-05 20:46:21
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    251
 * Problem Name:  How Many Islands? (Japan Local 2009)
 */

/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 20894
 * Submitted at:  2016-02-05 17:36:52
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    251
 * Problem Name:  How Many Islands? (Japan Local 2009)
 */

#include <iostream>
#include <string>
#include <queue>
#include <string.h>
using namespace std;

int main(){
	int rowCo;
	int colCo;
while(cin>>colCo>>rowCo){
	string line;
	if(colCo==0&&rowCo==0)
		break;
	int mapM[60][60];
	int visited[60][60];
	memset(mapM, 0, sizeof(mapM));
	memset(visited, 0, sizeof(visited));
	int islandId=1 ;
	queue<int> myQueue;

	for (int i = 1;  i<=rowCo; i++){
		for(int j = 1; j<=colCo; j++){
		    int temp;
		    cin>> temp;
			mapM[i][j] = temp;
		}
	}

	for (int i=1; i<=rowCo; i++){
		for(int j = 1; j<=colCo; j++){
			if(visited[i][j]==0&&mapM[i][j]==1){
				visited[i][j]=islandId;
				myQueue.push(i*100+j);

				while(!myQueue.empty()){
					int x = myQueue.front();
					myQueue.pop();
					int row = x/100;
					int col = x%100;

					if(visited[row+1][col+1]==0&&mapM[row+1][col+1]==1){
						myQueue.push((row+1)*100+(col+1));
						visited[row+1][col+1] = islandId;
					}
					if(visited[row+1][col]==0&&mapM[row+1][col]==1){
						myQueue.push((row+1)*100+(col));
						visited[row+1][col] = islandId;
					}
					if(visited[row+1][col-1]==0&&mapM[row+1][col-1]==1){
						myQueue.push((row+1)*100+(col-1));
						visited[row+1][col-1] = islandId;
					}
					if(visited[row][col+1]==0&&mapM[row][col+1]==1){
						myQueue.push((row)*100+(col+1));
						visited[row][col+1] = islandId;
					}
					if(visited[row][col-1]==0&&mapM[row][col-1]==1){
						myQueue.push((row)*100+(col-1));
						visited[row][col-1] = islandId;
					}
					if(visited[row-1][col+1]==0&&mapM[row-1][col+1]==1){
						myQueue.push((row-1)*100+(col+1));
						visited[row-1][col+1] = islandId;
					}
					if(visited[row-1][col]==0&&mapM[row-1][col]==1){
						myQueue.push((row-1)*100+(col));
						visited[row-1][col] = islandId;
					}
					if(visited[row-1][col-1]==0&&mapM[row-1][col-1]==1){
						myQueue.push((row-1)*100+(col-1));
						visited[row-1][col-1] = islandId;
					}
					
				}
				islandId++;





			}
		}
	}
	cout<<(islandId-1)<<endl;
}


}