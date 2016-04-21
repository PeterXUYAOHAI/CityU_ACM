/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 20917
 * Submitted at:  2016-02-05 19:59:13
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    375
 * Problem Name:  Making Okonomiyaki
 */

/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 20735
 * Submitted at:  2016-02-02 22:30:04
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    375
 * Problem Name:  Making Okonomiyaki
 */

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    int cA, cB, cC,cD,T;
while(cin>>cA>>cB>>cC>>cD>>T){

	int visited[25][25][25][25] = {0};
	queue<int> myQueue;
	myQueue.push(0);
	myQueue.push(0);
	myQueue.push(0);
	myQueue.push(0);
	myQueue.push(0);
	visited[0][0][0][0] = 1;

	bool found=false;

	

	while(!myQueue.empty()){
		
		int step = myQueue.front();
		myQueue.pop();
		int a = myQueue.front();
		myQueue.pop();
		int b = myQueue.front();
		myQueue.pop();
		int c = myQueue.front();
		myQueue.pop();
		int d = myQueue.front();
		myQueue.pop();
//		cout<<step<<endl<<a<<b<<c<<d<<endl;

		if(a==T||b==T||c==T||d==T){
			cout<<step<<endl;
			found = true;
//			cout<<a<<b<<c<<d;
			break;
		}


		for (int z=0; z<20 ; z++){
			switch(z){
				case 0:
				{
					int nA = 0;
					if(!visited[nA][b][c][d]){
						visited[nA][b][c][d] = 1;
						myQueue.push(step+1);
						myQueue.push(nA);
						myQueue.push(b);
						myQueue.push(c);
						myQueue.push(d);
					}

				}
				 break;

				 case 1:
				{
					int nB = 0;
					if(!visited[a][nB][c][d]){
						visited[a][nB][c][d] = 1;
						myQueue.push(step+1);
						myQueue.push(a);
						myQueue.push(nB);
						myQueue.push(c);
						myQueue.push(d);
					}

				}
				 break;

				case 2:
				{
					int nC = 0;
					if(!visited[a][b][nC][d]){
						visited[a][b][nC][d] = 1;
						myQueue.push(step+1);
						myQueue.push(a);
						myQueue.push(b);
						myQueue.push(nC);
						myQueue.push(d);
					}

				}
				 break;

				case 3:
				{
					int nD = 0;
					if(!visited[a][b][c][nD]){
						visited[a][b][c][nD] = 1;
						myQueue.push(step+1);
						myQueue.push(a);
						myQueue.push(b);
						myQueue.push(c);
						myQueue.push(nD);
					}

				}
				 break;



				case 4:
				{
					int nA = cA;
					if(!visited[nA][b][c][d]){
						visited[nA][b][c][d] = 1;
						myQueue.push(step+1);
						myQueue.push(nA);
						myQueue.push(b);
						myQueue.push(c);
						myQueue.push(d);
					}

				}
				 break;

				  case 5:
				{
					int nB = cB;
					if(!visited[a][nB][c][d]){
						visited[a][nB][c][d] = 1;
						myQueue.push(step+1);
						myQueue.push(a);
						myQueue.push(nB);
						myQueue.push(c);
						myQueue.push(d);
					}

				}
				 break;

				case 6:
				{
					int nC = cC;
					if(!visited[a][b][nC][d]){
						visited[a][b][nC][d] = 1;
						myQueue.push(step+1);
						myQueue.push(a);
						myQueue.push(b);
						myQueue.push(nC);
						myQueue.push(d);
					}

				}
				 break;

				case 7:
				{
					int nD = cD;
					if(!visited[a][b][c][nD]){
						visited[a][b][c][nD] = 1;
						myQueue.push(step+1);
						myQueue.push(a);
						myQueue.push(b);
						myQueue.push(c);
						myQueue.push(nD);
					}

				}
				 break;

				case 8:
				{
					int nA, nB;
					if((a+b)>cB){
						nA = a + b -cB;
						nB = cB;
					}
					else{
						nA = 0;
						nB = a + b;
					}

					if(!visited[nA][nB][c][d]){
						visited[nA][nB][c][d] = 1;
						myQueue.push(step+1);
						myQueue.push(nA);
						myQueue.push(nB);
						myQueue.push(c);
						myQueue.push(d);
					}

				}
				 break;

				case 9:
				{
					int nA, nB;
					if((a+b)>cA){
						nA = cA;
						nB = a+b-cA;
					}
					else{
						nA = a+b;
						nB = 0;
					}

					if(!visited[nA][nB][c][d]){
						visited[nA][nB][c][d] = 1;
						myQueue.push(step+1);
						myQueue.push(nA);
						myQueue.push(nB);
						myQueue.push(c);
						myQueue.push(d);
					}

				}
				 break;

				 case 10:
				{
					int nA, nC;
					if((a+c)>cC){
						nA = a + c -cC;
						nC = cC;
					}
					else{
						nA = 0;
						nC = a + c;
					}

					if(!visited[nA][b][nC][d]){
						visited[nA][b][nC][d] = 1;
						myQueue.push(step+1);
						myQueue.push(nA);
						myQueue.push(b);
						myQueue.push(nC);
						myQueue.push(d);
					}

				}
				 break;

				case 11:
				{
					int nA, nC;
					if((a+c)>cA){
						nA = cA;
						nC = a+c-cA;
					}
					else{
						nA = a+c;
						nC = 0;
					}

					if(!visited[nA][b][nC][d]){
						visited[nA][b][nC][d] = 1;
						myQueue.push(step+1);
						myQueue.push(nA);
						myQueue.push(b);
						myQueue.push(nC);
						myQueue.push(d);
					}

				}
				 break;

				 case 12:
				{
					int nA, nD;
					if((a+d)>cD){
						nA = a + d -cD;
						nD = cD;
					}
					else{
						nA = 0;
						nD = a + d;
					}

					if(!visited[nA][b][c][nD]){
						visited[nA][b][c][nD] = 1;
						myQueue.push(step+1);
						myQueue.push(nA);
						myQueue.push(b);
						myQueue.push(c);
						myQueue.push(nD);
					}

				}
				 break;

				case 13:
				{
					int nA, nD;
					if((a+d)>cA){
						nA = cA;
						nD = a+d-cA;
					}
					else{
						nA = a+d;
						nD = 0;
					}

					if(!visited[nA][b][c][nD]){
						visited[nA][b][c][nD] = 1;
						myQueue.push(step+1);
						myQueue.push(nA);
						myQueue.push(b);
						myQueue.push(c);
						myQueue.push(nD);
					}

				}
				 break;

				 case 14:
				{
					int nB, nC;
					if((b+c)>cC){
						nB = b + c -cC;
						nC = cC;
					}
					else{
						nB = 0;
						nC = b + c;
					}

					if(!visited[a][nB][nC][d]){
						visited[a][nC][nC][d] = 1;
						myQueue.push(step+1);
						myQueue.push(a);
						myQueue.push(nB);
						myQueue.push(nC);
						myQueue.push(d);
					}

				}
				 break;
				case 15:
				{
					int nB, nC;
					if((b+c)>cB){
						nB = cB;
						nC = b+c-cB;
					}
					else{
						nB = b+c;
						nC = 0;
					}

					if(!visited[a][nB][nC][d]){
						visited[a][nB][nC][d] = 1;
						myQueue.push(step+1);
						myQueue.push(a);
						myQueue.push(nB);
						myQueue.push(nC);
						myQueue.push(d);
					}

				}
				 break;

				case 16:
				{
					int nB, nD;
					if((b+d)>cD){
						nB = b + d -cD;
						nD = cD;
					}
					else{
						nB = 0;
						nD = b + d;
					}

					if(!visited[a][nB][c][nD]){
						visited[a][nB][c][nD] = 1;
						myQueue.push(step+1);
						myQueue.push(a);
						myQueue.push(nB);
						myQueue.push(c);
						myQueue.push(nD);
					}

				}
				 break;
				case 17:
				{
					int nB, nD;
					if((b+d)>cB){
						nB = cB;
						nD = b+d-cB;
					}
					else{
						nB = b+d;
						nD = 0;
					}

					if(!visited[a][nB][c][nD]){
						visited[a][nB][c][nD] = 1;
						myQueue.push(step+1);
						myQueue.push(a);
						myQueue.push(nB);
						myQueue.push(c);
						myQueue.push(nD);
					}

				}
				 break;
				 case 18:
				{
					int nC, nD;
					if((c+d)>cD){
						nC = c + d -cD;
						nD = cD;
					}
					else{
						nC = 0;
						nD = c + d;
					}

					if(!visited[a][b][nC][nD]){
						visited[a][b][nC][nD] = 1;
						myQueue.push(step+1);
						myQueue.push(a);
						myQueue.push(b);
						myQueue.push(nC);
						myQueue.push(nD);
					}

				}
				 break;
				case 19:
				{
					int nC, nD;
					if((c+d)>cC){
						nC = cC;
						nD = c+d-cC;
					}
					else{
						nC = c+d;
						nD = 0;
					}

					if(!visited[a][b][nC][nD]){
						visited[a][b][nC][nD] = 1;
						myQueue.push(step+1);
						myQueue.push(a);
						myQueue.push(b);
						myQueue.push(nC);
						myQueue.push(nD);
					}

				}
				 break;







				}






			}
}

	
if(!found){
		cout<<-1<<endl;
	}
}
	
	
}