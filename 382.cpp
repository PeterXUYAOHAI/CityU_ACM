#include <iostream>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

int regs[210];
int caps[210][210];
//int cap[210][210];
int flow[210][210];
int source;
int sink;
int regNum;

int path[210];
int bfsFlow;

void bfs(){
bfsFlow = 0;
	int pathCap[210];
	for (int i = 0; i <= regNum * 2 + 2; ++i){
		path[i] = -1;
		pathCap[i] = 0;
	}
	path[source] = -2;
	pathCap[source] = 99999999;
	queue<int> q;
	q.push(source);
//	cout<<caps[7][10]<<" "<<flow[7][10]<<endl;
	while (!q.empty()){
		int node = q.front();
		q.pop();
		for (int i = 1; i <= regNum * 2 + 2; ++i)
		{
			if (caps[node][i] - flow[node][i]>0 && path[i] == -1){
				path[i] = node;
	//			cout << node << " " << i << " " << path[i] << endl;
				pathCap[i] = (pathCap[node]<(caps[node][i] - flow[node][i]) ? pathCap[node] : (caps[node][i] - flow[node][i]));
				if (i != sink)
					q.push(i);
				else{
					bfsFlow = pathCap[sink];
					return;
				}

			}
		}
	}
	bfsFlow = 0;
	return;

}


int main(){



	while(cin >> regNum){

	memset(caps, 0, sizeof(caps));
	memset(flow, 0, sizeof(flow));

	for (int i = 1; i <= regNum; ++i)
	{
		int cap;
		cin >> cap;
		caps[2 * i][2 * i + 1] = cap;
		caps[2 * i + 1][2 * i] = 0;
	}
	int linkNum;
	cin >> linkNum;
	while (linkNum--){
		int st, des, cap;
		cin >> st >> des >> cap;
		caps[st * 2 + 1][des * 2] = cap;
	//	caps[des * 2 + 1][st * 2] = 0;
	}
	int sourceNum, desNum;
	cin >> sourceNum >> desNum;

	source = 0;
	while (sourceNum--){
		int sr;
		cin >> sr;
		caps[0][sr * 2] = 0;
		for (int i = 1; i <= regNum; ++i)
		{
			if (caps[sr * 2 + 1][2 * i]>0)
				caps[0][sr * 2] += caps[sr * 2 + 1][2 * i];
		}

	}
	sink = regNum * 2 + 2;
	while (desNum--){
		int de;
		cin >> de;
		caps[de * 2 + 1][regNum * 2 + 2] = 0;
		for (int i = 1; i <= regNum; ++i)
		{
			if (caps[i * 2 + 1][de * 2]>0)
				caps[de * 2 + 1][regNum * 2 + 2] += caps[i * 2 + 1][de * 2];
		}

	}


	int maxFlow = 0;

	//     cout<<source<<endl<<sink<<endl;
	//     for (int i = 0; i <= regNum*2+2; ++i){
	//         for (int j=0; j<=regNum*2+2; ++j)
	// 		 {
	// 		 	cout<<caps[i][j]<<" ";
	// 		 } 
	// 		 cout<<endl;
	//     }
	for (int i = 0; i <= regNum * 2 + 2; ++i){
		for (int j = 0; j <= regNum * 2 + 2; ++j)
			flow[j][i] = caps[i][j];
	}

	while (1){
		bfs();
	//	cout << bfsFlow << endl;
		if (bfsFlow == 0)
			break;
	//	cout << path[0] << endl;
		maxFlow += bfsFlow;
		int v = sink;
		while (v != source){
			int u;
			u = path[v];
//			cout << v << " " << u << endl;
			flow[u][v] = flow[u][v] + bfsFlow;
			flow[v][u] = flow[v][u] - bfsFlow;
//			cout << flow[u][v] << endl;
//			cout << flow[v][u] << endl;
			v = u;
		}


	}

	cout << maxFlow<<endl;
	}




}