/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 21575
 * Submitted at:  2016-02-20 15:26:01
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    318
 * Problem Name:  Obstacle Course
 */

#include <iostream>
#include <string>
#include <queue>
#include <stdio.h>
#include <string.h>

using namespace std;

	int dx[4] ={0,1,0,-1};
	int dy[4] ={1,0,-1,0};

struct node  
{  
    int x, y;  
    int dis;  
    bool operator<(const node &s)const  
    {  
        return dis > s.dis;  
    }  
}; 




int main(){
    int	map[200][200];
	int visited[200][200];
	 
    int pro=0;

	int width;
	priority_queue<node> queue;

	while(++pro){
	cin >> width;
	if(width == 0)
		break;
	
	memset(visited,-1,sizeof(visited)); 
	for (int i=0; i<width; i++)
		for (int j=0; j<width; j++)
			cin>>map[i][j];
		
	node n;
	n.x = 0; n.y=0; n.dis=map[0][0];
    visited[0][0] = map[0][0];
	queue.push(n);

	 while(!queue.empty()){
	 	node pre = queue.top();
	 	queue.pop();
		
		

		for(int i=0; i<4;i++){
			int xx = pre.x+dx[i];
			int yy = pre.y+dy[i];

			if(xx>=0&&xx<width&&yy>=0&&yy<width){
			    
				if(visited[xx][yy]==-1||visited[xx][yy]>(pre.dis+map[xx][yy])){\
					node next;
					next.x = xx;
					next.y = yy;
					next.dis = pre.dis+map[xx][yy];
					visited[xx][yy] = pre.dis+map[xx][yy];
					queue.push(next);
				}
			} 

		}

		

	 }
	 cout<<"Problem "<<pro<<": "<<visited[width-1][width-1]<<endl;

}
}
