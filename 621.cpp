/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 23456
 * Submitted at:  2016-03-16 23:52:43
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    621
 * Problem Name:  Rebuilding Roads
 */

#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct road{
	int st, de;
	int cost;

	bool operator <(const road &r2)const{
		return cost>r2.cost;
	}
};

int set[55];

int Find(int e){
	if (set[e]<0)
		return e;
	else
		return set[e] = Find(set[e]);
}

void unionSet(int e1, int e2){
	set[e1] += set[e2];
	set[e2] = e1;
}

bool Union(int e1, int e2){
	int root1 = Find(e1);
	int root2 = Find(e2);
	
	if (root1 == root2)
		return false;

	if (set[root1]<set[root2])
		unionSet(root1, root2);
	else
		unionSet(root2, root1);

	return true;
}


int main(){

	int cityNum;
	int isRoad[55][55];
	int buildRoad[55][55];
	int destRoad[55][55];


    while (true){
    	priority_queue<road> q;
	string input;
	cin >> cityNum;
	if(cityNum==0)
	    break;
	getline(cin, input);
	
	for (int i=0; i<cityNum; i++)
	    set[i] = -1;
	for (int i = 0; i<cityNum; i++){
		getline(cin, input);
		for (int j = 0; j<cityNum; j++)
			isRoad[i][j] = input[j]-'0';
	}

	for (int i = 0; i<cityNum; i++)
	for (int j = 0; j<cityNum; j++)
		cin >> buildRoad[i][j];

	for (int i = 0; i<cityNum; i++)
	for (int j = 0; j<cityNum; j++)
		cin >> destRoad[i][j];

//	cout << "OK";
	int totalCost = 0;
	for (int i = 0; i<cityNum; i++)
	for (int j = i + 1; j<cityNum; j++){
		road r;
		r.st = i;
		r.de = j;
		if (isRoad[i][j] == 0)
			r.cost = buildRoad[i][j];
		else{
//			cout << "2" << endl;
			r.cost = -destRoad[i][j];
			totalCost += destRoad[i][j];
		}


		q.push(r);
	}

	int concCity = 1;
//	cout<<totalCost;

//	cout << "3" << endl;
	while (!q.empty()){
//		cout << "4" << endl;
		if (concCity == cityNum)
			break;
		road newR = q.top();
		q.pop();
//		cout << "5" << endl;
		if (Union(newR.st, newR.de)){
			concCity++;
			totalCost += newR.cost;

		}



	}
	cout << totalCost << endl;
    }






}