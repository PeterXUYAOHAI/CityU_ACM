/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 24117
 * Submitted at:  2016-03-31 23:00:32
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    362
 * Problem Name:  Winger Trial (UVa 11757)
 */

/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 24116
 * Submitted at:  2016-03-31 22:37:25
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    362
 * Problem Name:  Winger Trial (UVa 11757)
 */

#include <iostream>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

int cap[205][205];
int flow[205][205];
int sour;
int sink;

int parent[205];
int pathFlow[205];
int bfsFlow;
int l,w,n,d;

struct node{
	int x,y;
	int num;
};

node nodes[200];


void bfs(){

	for (int i = 0; i <= 2*n+2; ++i){
		parent[i] = -1;
		pathFlow[i]=0; 
	}
	parent[0]=-2;
	pathFlow[0]=9999999;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for (int i = 0; i <= 2*n+2; ++i)
		{
			if((cap[now][i]-flow[now][i]>0)&&parent[i]==-1){
			    
				pathFlow[i]=(pathFlow[now]<(cap[now][i]-flow[now][i])?pathFlow[now]:(cap[now][i]-flow[now][i]));
		//		cout<<now<<" "<<i<<" "<<pathFlow[i]<<endl;
				parent[i]=now;
				if(i!=sink){
					q.push(i);
					
					}
				else{
					bfsFlow=pathFlow[sink];
					return;
				}
				}
		}
		
	}
	bfsFlow=0;
		return;

}



int main(){
    
    int caseNum = 0;
    while(++caseNum){
        
	cin>>l>>w>>n>>d;
	if(l==0&&w==0&&n==0&&d==0)
	    break;

	memset(cap,0,sizeof(cap));
	memset(flow,0,sizeof(flow));
	sour = 0;
	sink = 2*n+2;
    
   // cout<<"OK";
	for (int i = 1; i <= n; ++i)
	{
		node newNode;
		cin>>newNode.x>>newNode.y;
		nodes[i]=newNode;
		cap[2*i][2*i+1] = 1;
	}

	for (int i = 1; i <=n; ++i)
	{
		if(nodes[i].y<=d){
			cap[0][2*i] = 9999;
			cap[2*i+1][0] = 9999;
			flow[0][2*i]=0;
			flow[2*i+1][0]=0;
		}
		if((w-nodes[i].y)<=d){
			cap[2*i+1][sink]=9999;
			cap[sink][2*i]=9999;
			flow[2*i+1][sink]=0;
			flow[sink][2*i]=0;
		}
		for (int j = i+1; j <=n; ++j)
		{
			int difX = nodes[i].x-nodes[j].x;
			int difY = nodes[i].y-nodes[j].y;
			if((difX*difX+difY*difY)<=4*d*d){
				cap[2*i+1][2*j]=9999;
				cap[2*j+1][2*i]=9999;
				flow[2*i+1][2*j]=0;
				flow[2*j+1][2*i]=0;
			}
		}

	}
	int maxFlow = 0;
	while(1){
		bfs();
		if(bfsFlow==0)
			break;
		maxFlow+=bfsFlow;
	//	cout<<"OK"<<endl;
		int v = sink;
		while(v!=sour){
			int u = parent[v];
			flow[u][v]+=bfsFlow;
			flow[v][u]-=bfsFlow;
			v=u;
		}
	}
    cout<<"Case "<<caseNum<<": "<<maxFlow<<endl;
    }


}