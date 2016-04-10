#include <iostream>
#include <string>
#include <queue>

#define INF 999999

using namespace std;


int cap[6000][6000];
int flow[6000][6000];
int n,m;

int source, sink;


void bfs(){


}

int main(){
	cin>>n>>m;
	source =0;
	sink = n+1;

	for (int i = 1; i <= n; ++i)
	{
		int weight;
		cin>>weight;
		weight>0?cap[source][i]=weight:cap[i][sink]=-weight;
	}

	while(m--){
		int a,b;
		cin>>a>>b;
		cap[a][b]=INF;
		cap[b][a]=INF;
	}





}