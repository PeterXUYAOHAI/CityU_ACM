/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 23444
 * Submitted at:  2016-03-16 22:10:43
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    165
 * Problem Name:  Frogger (UVa 534) (Precision)
 */

#include <iostream>
#include <string>
#include <queue>
#include <math.h>
#include <iomanip>

using namespace std;



int set[210];


struct node {
	int x;
	int y;
};

struct route
{
	int st;
	int de;
	double length;

	bool operator < (const route &n2)const {
		return length>n2.length;
	}
};


node nodes[210];

int Find(int e) {
	if (set[e]<0)
		return e;
	else
		return set[e] = Find(set[e]);
}

void unionSet(int r1, int r2) {
	set[r1] += set[r2];
	set[r2] = r1;
}


void Union(int e1, int e2) {
	int root1 = Find(e1);
	int root2 = Find(e2);

	if (root1 == root2)
		return;
	if (set[root1]<set[root2])
		unionSet(root1, root2);
	else
		unionSet(root2, root1);

}



int main() {
	int sNum;
	int caseNum = 0;

	while (cin >> sNum) {
		caseNum++;
		if (sNum == 0)
			break;
		priority_queue<route> q;


		for (int i = 0; i < sNum; i++)
		{
			node N;
			cin >> N.x >> N.y;
			set[i] = -1;
			nodes[i] = N;
		}



		for (int i = 0; i < sNum; i++)
			for (int j = 1; j < sNum; j++)
				if (i != j) {
					double distance;
					distance = sqrt(pow((nodes[i].x - nodes[j].x), 2) + pow((nodes[i].y - nodes[j].y), 2));

					route nR;
					nR.st = i;
					nR.de = j;
					nR.length = distance;

					q.push(nR);

				}




		double min = 0;
		while (!q.empty()) {


			route out = q.top();
			q.pop();


			min = out.length;
			Union(out.st, out.de);



			if (Find(0) == Find(1))
				break;




		}
		cout << "Scenario #" << caseNum << endl;
		cout<< "Frog Distance = "<<setprecision(3)<<fixed << min << endl<<endl;
	}


}





