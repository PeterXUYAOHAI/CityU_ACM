#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <iomanip>

using namespace std;

struct edge{
	double d;
    int c;
};

struct city
{
	double t; 
	int s,sp,last;
	bool operator<(const city &other)const{
		return t>other.t;
	}
};



edge ed[40][40];
int vis[40][40][40];


int main(){
	int speedC[3]={-1,0,1};
	int numOfCity, numOfEdge,start, goal;
	bool reachable = false;
	while(1){
	memset(vis,0,sizeof(vis));
	cin>>numOfCity>>numOfEdge;
	
	if(numOfCity==0&&numOfEdge==0)
	    break;
	cin>>start>>goal;

	for(int i=0; i<40; i++){
		for (int j=0; j<40; j++){
			ed[i][j].d = 999;
		}
	}

	for(int i=0; i<numOfEdge; i++){
		int s,g;
		cin>>s>>g;
		cin>>ed[s][g].d>>ed[s][g].c;
	}

	priority_queue<city> q;
	city c;
	c.t=0; c.s=start; c.sp =0; c.last=0;
	vis[start][1][0]=-1;
	q.push(c);


	while (!q.empty()){
		city curr = q.top(); q.pop();
		double currT = curr.t;
		int cityNum = curr.s;
		int currSp = curr.sp;
		int lastCity = curr.last;
//		cout<<cityNum<<" "<<currT<<" "<<currSp<<" "<<lastCity<<endl;  
		if(cityNum==goal&&currSp==1){
		    cout<<setprecision(5)<<fixed<<currT<<endl;
		    reachable = true;
			break;
		}
		city newOne;
		for(int i=1; i<=numOfCity; i++){
			if(ed[cityNum][i].d<999&&i!=lastCity){
				for(int j=0;j<3;j++)
				if((currSp+speedC[j])>0&&(currSp+speedC[j])<=ed[cityNum][i].c&&vis[i][currSp+speedC[j]][cityNum]!=-1){
					newOne.s=i;
					newOne.sp=currSp+speedC[j];
					newOne.last=cityNum;
					newOne.t=currT+(ed[cityNum][i].d/(currSp+speedC[j]));
					q.push(newOne);
				}
			}
		}

		vis[cityNum][currSp][lastCity]=-1;
	}
	if(!reachable)
	    cout<<"unreachable"<<endl;
	}



}