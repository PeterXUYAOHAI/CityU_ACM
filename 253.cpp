/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 24142
 * Submitted at:  2016-04-01 19:08:29
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    253
 * Problem Name:  Discrete Speed (Japan Local 2009)
 */

/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 22627
 * Submitted at:  2016-03-04 17:44:14
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    253
 * Problem Name:  Discrete Speed (Japan Local 2009)
 */

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
double ts[40][40][40];


int main(){
	int speedC[3]={-1,0,1};
	int numOfCity, numOfEdge,start, goal;
	bool reachable = false;
	while(1){
		reachable=false;
	memset(vis,0,sizeof(vis));
	for(int i=0; i<40; i++)
	    for(int j=0;j<40;j++)
	        for(int n=0; n<40; n++)
	            ts[i][j][n]=999999;
//	cout<<ts[0][0][0];
	cin>>numOfCity>>numOfEdge;
	
	if(numOfCity==0&&numOfEdge==0)
	    break;
	cin>>start>>goal;

	for(int i=0; i<40; i++){
		for (int j=0; j<40; j++){
			ed[i][j].d = 9999;
			ed[i][j].c = 0;
		}
	}

	for(int i=0; i<numOfEdge; i++){
		int s,g,d,c;
		cin>>s>>g>>d>>c;
		ed[s][g].d=d;
		ed[s][g].c=c;
		ed[g][s].d=d;
		ed[g][s].c=c;
	}


	priority_queue<city> q;
	city c;
	c.t=0; c.s=start; c.sp =0; c.last=0;
	vis[start][0][0]=-1;
	ts[start][0][0]=0;
	q.push(c);


	while (!q.empty()){
		city curr = q.top(); q.pop();
		double currT = curr.t;
		int cityNum = curr.s;
		int currSp = curr.sp;
		int lastCity = curr.last;
//		cout<<cityNum<<" "<<currT<<" "<<currSp<<" "<<lastCity<<endl;  
		if(cityNum==goal&&currSp==1){
//		    cout<<setprecision(5)<<fixed<<currT<<endl;
		    reachable = true;
//			break;
		}
		city newOne;
		for(int i=1; i<=numOfCity; i++){
			if(ed[cityNum][i].d<9999&&i!=lastCity){
				for(int j=0;j<3;j++)
				if((currSp+speedC[j])>0&&(currSp+speedC[j])<=ed[cityNum][i].c&&vis[i][currSp+speedC[j]][cityNum]!=-1){
					newOne.s=i;
					newOne.sp=currSp+speedC[j];
					newOne.last=cityNum;
					newOne.t=currT+(ed[cityNum][i].d/(currSp+speedC[j]));
				// 	if(cityNum==24)
				// 	    cout<<"    "<<newOne.t<<" "<<newOne.s<<" "<<newOne.sp<<endl;
					if(newOne.t<ts[newOne.s][newOne.sp][newOne.last]){
					ts[newOne.s][newOne.sp][newOne.last]=newOne.t;
					q.push(newOne);
					}
				}
			}
		}

		vis[cityNum][currSp][lastCity]=-1;
	}
	if(!reachable)
	    cout<<"unreachable"<<endl;
	else{
	    double min = 999999;
	    for(int i=0;i<40;i++){
	       // cout<<ts[goal][1][i]<<endl;
	        min = min<ts[goal][1][i]?min:ts[goal][1][i];
	    }
	    cout<<setprecision(5)<<fixed<<min<<endl;
	}
	}
	
	



}