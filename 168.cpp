/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 23423
 * Submitted at:  2016-03-16 20:32:30
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    168
 * Problem Name:  Networking
 */

#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct cable{
	int cityA;
	int cityB;
	int length;

	bool operator<(const cable &n2)const{
		return length > n2.length;
	}
};


cable A[110];
int Set[55];


int Find (int e){
	if (Set[e]<0)
		return e;
	else 
		return Set[e]=Find(Set[e]);
}


void UnionSet(int e1, int e2){
	Set[e1] +=Set[e2];
	Set[e2] = e1;

}

bool Union (int e1, int e2){
	int root1 = Find(e1);
	int root2 = Find(e2);
	if (root1==root2)
		return false;

	if (root1<root2)
		UnionSet(root1, root2);
	else
		UnionSet(root2, root1);
	return true;
}





int main(){

	int cityNum, cableNum;


	while(true){
	priority_queue<cable> q;
	cin>>cityNum;
	if(cityNum==0)
		break;
	cin>>cableNum;
	if(cableNum==0){
	    cout<<0<<endl;
		continue;
	}

	for (int i = 1; i <=cityNum; i++)
	{
		Set[i]=-1;
	}

	while(cableNum--){
		int start, dest, length;
		cin>>start>>dest>>length;
		cable newC;
		newC.cityA=start;
		newC.cityB=dest;
		newC.length=length;
		q.push(newC);
	}

	int conCity = 0;
	int tLength = 0;
	cable first = q.top();
	q.pop();
	tLength = first.length;
	conCity += 2;
	Union(first.cityA,first.cityB);


	while(!q.empty()){
	
	    if(conCity==cityNum)
			break;
		cable now = q.top();
		q.pop();
		if(Union(now.cityA,now.cityB)){
			conCity+=1;
			tLength+=now.length;
		}
		
	}
	cout<< tLength<<endl;
}
}
