/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 24134
 * Submitted at:  2016-04-01 16:28:14
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    396
 * Problem Name:  Dual Core
 */

#include <iostream>
#include <string>
#include <queue>
#include <string.h>

using namespace std;

int n, m;
int cap[400][400];
int flow[400][400];
int source;
int sink;

int bfsFlow;
int parent[400];
int pathFlow[400];


void bfs(){
	for (int i = 0; i <= n + 1; ++i)
	{
		parent[i] = -1;
		pathFlow[i] = 0;
	}
	parent[source] = -2;
	pathFlow[source] = 999999;
	queue<int> q;
	q.push(source);
	while (!q.empty()){
		int now = q.front();
		q.pop();
		for (int i = 0; i <= n + 1; ++i)
		{
			if ((cap[now][i] - flow[now][i]>0) && parent[i] == -1){
			  //  cout<<now<<" "<<i<<endl;
				parent[i] = now;
				pathFlow[i] = ((pathFlow[now]<(cap[now][i] - flow[now][i])) ? pathFlow[now] : (cap[now][i] - flow[now][i]));
				if (i != sink){
					q.push(i);
				}
				else{
					bfsFlow = pathFlow[sink];
					return;
				}
			}
		}
	}
	bfsFlow = 0;
	return;


}



int main(){
    while(cin>>n){
	cin >> m;
	source = 0;
	sink = n + 1;
	memset(cap, 0, sizeof(cap));
	memset(flow, 0, sizeof(flow));
	for (int i = 1; i <= n; ++i)
	{
		int toA, toB;
		cin >> toA >> toB;
		cap[0][i] = toA;
		cap[i][sink] = toB;
	}

	while (m--){
		int a, b, cost;
		cin >> a >> b >> cost;
		cap[a][b] = cost;
		cap[b][a] = cost;
	}

	int maxFLow = 0;
	while (1){
		bfs();

		if (bfsFlow == 0)
			break;
		
		int v = sink;
		while (v != source){
			int u = parent[v];
			flow[u][v] += bfsFlow;
			flow[v][u] -= bfsFlow;
			v = u;
		}
		maxFLow += bfsFlow;

	}
	cout << maxFLow<<endl;
}
}