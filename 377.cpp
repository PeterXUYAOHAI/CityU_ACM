/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 24139
 * Submitted at:  2016-04-01 18:08:38
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    377
 * Problem Name:  Firing (PKU 2987)
 */

#include <iostream>
#include <string>
#include <queue>
#include <string.h>

#define INF 999999999

using namespace std;


int cap[6000][6000];
int flow[6000][6000];

int n, m;

int parent[6000];
int pathFlow[6000];

int pathNode[6000];

int source, sink;
int bfsFlow;

void bfs() {
	for (int i = 0; i <= n + 1; ++i)
	{
		parent[i] = -1;
		pathFlow[i] = 0;
	}
	parent[source] = -2;
	pathFlow[source] = INF;

	queue<int> q;
	q.push(source);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		//cout<<now<<endl;
		for (int i = 1; i <= n + 1; ++i)
		{
			if (cap[now][i] - flow[now][i]>0 && parent[i] == -1) {

				parent[i] = now;
				pathFlow[i] = pathFlow[now]<cap[now][i] - flow[i][now] ? pathFlow[now] : cap[now][i] - flow[i][now];
			//	cout << now << " " << i << " " << pathFlow[i] << endl;
				if (i != sink)
					q.push(i);
				else {
					bfsFlow = pathFlow[sink];
					return;
				}
			}

		}
	}
	bfsFlow = 0;
	return;
}

int main() {
	while (cin >> n) {
		cin >> m;
		source = 0;
		sink = n + 1;
		long int sum = 0;
		memset(cap, 0, sizeof(cap));
		memset(flow, 0, sizeof(flow));
		memset(pathNode, 0, sizeof(pathNode));

		for (int i = 1; i <= n; ++i)
		{
			int weight;
			cin >> weight;
			if (weight > 0) {
				cap[source][i] = weight;
				sum += weight;
			}
			else cap[i][sink] = -weight;
		}

		while (m--) {
			int a, b;
			cin >> a >> b;
			cap[a][b] = INF;
			//	cap[b][a] = INF;
		}

		int maxFlow = 0;
		while (1) {
			bfs();
			if (bfsFlow == 0)
				break;
			int v = sink;
			maxFlow += bfsFlow;
			while (v != source) {
				int u = parent[v];
				flow[u][v] += bfsFlow;
				flow[v][u] -= bfsFlow;
				v = u;
				pathNode[u] = 1;
			}
		}

		int nodeNum = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (parent[i] == -1) {
				//cout<<i<<endl;
				nodeNum++;
			}
		}

		cout << n - nodeNum << " " << sum - maxFlow << endl;
	}



}