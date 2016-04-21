/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 23412
 * Submitted at:  2016-03-16 19:44:00
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    356
 * Problem Name:  Poor Trade Advisor (UVa 11749)
 */

#include <iostream>
#include <string>

using namespace std;


int A[510][510];
int set[510];




int Find(int e){
	if (set[e]<0)
		return e;
	else
		return set[e] = Find(set[e]);
}


void UnionSet(int r1, int r2){
	set[r1] += set[r2];
	set[r2] = r1;

}


void Union (int e1, int e2){
	int r1 = Find(e1);
	int r2 = Find(e2);
	if(r1==r2)
		return;

	if(r1<r2)
		UnionSet(r1,r2);
	else
		UnionSet(r2,r1);
}


int main(){

	int city, pair;
	int visited[510][510];
	
	while (true){
	cin>>city>>pair;
	if (city ==0 &&pair==0)
	    break;
	int max = -2147483648;
	for(int i=1;i<=city;i++)
		for(int j=1; j<=city;j++){
			A[i][j] = -2147483648;
			visited[i][j] = -1;
		}

	while (pair--){
		int s,d,ppa;
		cin>>s>>d>>ppa;

		if (ppa>max)
			max = ppa;
		if(ppa>A[s][d])
		    A[s][d] = ppa;
		    
		visited[s][d] = 1;
	}
//	cout<<max<<endl;

	for(int i=1; i<=city; i++)
		set[i] = -1;

	for(int i=1;i<=city;i++)
		for(int j=1; j<=city;j++){
			if (visited[i][j]==1&&A[i][j]==max){
//			    cout<<i<<" "<<j<<endl;
				Union(i,j);
			}
		}

	int maxCity = 0;
	for(int i=1; i<=city; i++){
//	    cout<<set[i]<<endl;
		if (set[i]<0 && -set[i]>maxCity)
			maxCity=-set[i];
	}

	cout<<maxCity<<endl;


}



}