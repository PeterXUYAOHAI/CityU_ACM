#include <iostream>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

int cap[200][200];
int flow[200][200];
int sour;
int sink;

int parent[200];
int pathFlow[200];
int bfsFlow;
int l,w,n,d;

struct node{
	int x,y;
	int num;
};

node nodes[200];


void bfs(){

	for (int i = 0; i <= n+1; ++i){
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
		for (int i = 0; i <= n+1; ++i)
		{
			if((cap[now][i]-flow[now][i]>0)&&parent[i]==-1){
			    
				pathFlow[i]=(pathFlow[now]<(cap[now][i]-flow[now][i])?pathFlow[now]:(cap[now][i]-flow[now][i]));
				cout<<now<<" "<<i<<" "<<pathFlow[i]<<endl;
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

	cin>>l>>w>>n>>d;

	memset(cap,0,sizeof(cap));
	memset(flow,0,sizeof(flow));
	sour = 0;
	sink = n+1;

	for (int i = 1; i <= n; ++i)
	{
		node newNode;
		cin>>newNode.x>>newNode.y;
		nodes[i]=newNode;
	}

	for (int i = 1; i <=n; ++i)
	{
		if(nodes[i].y<=d){
			cap[0][i] = 1;
			cap[i][0] = 1;
			flow[0][i]=0;
			flow[i][0]=0;
		}
		if((w-nodes[i].y)<=d){
			cap[i][sink]=1;
			cap[sink][i]=1;
			flow[i][sink]=0;
			flow[sink][i]=0;
		}
		for (int j = i+1; j <=n; ++j)
		{
			int difX = nodes[i].x-nodes[j].x;
			int difY = nodes[i].y-nodes[j].y;
			if((difX*difX+difY*difY)<=4*d*d){
				cap[i][j]=1;
				cap[j][i]=1;
				flow[i][j]=0;
				flow[j][i]=0;
			}
		}

	}
	int maxFlow = 0;
	while(1){
		bfs();
		if(bfsFlow==0)
			break;
		maxFlow+=bfsFlow;
		cout<<"OK"<<endl;
		int v = sink;
		while(v!=sour){
			int u = parent[v];
			flow[u][v]+=bfsFlow;
			flow[v][u]-=bfsFlow;
			v=u;
		}
	}
    cout<<maxFlow<<endl;


}