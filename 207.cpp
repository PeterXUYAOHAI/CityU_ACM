/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 22540
 * Submitted at:  2016-03-01 21:44:38
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    207
 * Problem Name:  Minimum Effort
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <sstream>


using namespace std;

struct node
{
	int x;
	int dis;
	int p;
	bool operator<(const node &s)const
	{
		return dis > s.dis;
	}
};




int main() {

	int pNum;
	string input;

while(cin>>pNum){

	getline(cin, input);
	int officeNum;
	int hallNum;
	int adjMa[300][300] = {-1};
	node visitedOne[300];
	node visitedTwo[300];

	memset(adjMa, -1, sizeof(adjMa));

	for(int i=0; i<300; i++){
		visitedOne[i].x = i;
		visitedOne[i].dis = 999999;
		visitedOne[i].p = -1;
		visitedTwo[i].x = i;
		visitedTwo[i].dis = 999999;
		visitedTwo[i].p = -1;

	}	
	// memset(visitedOne, 9999, sizeof(visitedOne));
	// memset(visitedTwo, 9999, sizeof(visitedTwo));
  
	int eNum;

	string place[300];
	for (int i = 0; i<pNum; i++) {
		getline(cin, place[i]);
		if (place[i] == "office")
			officeNum = i;
		if (place[i] == "hall")
			hallNum = i;
	}



    cin>>eNum;
	getline(cin, input);


	for (int i = 0; i<eNum; i++) {
		string inputLine;
		getline(cin, inputLine);
		string start = "";
		string end = "";
		int splitNum;
		int go = -1;
		int back = -1;
		int numStartP;
		for (int j = 0; j<inputLine.length(); j++) {
			if (inputLine[j] == ':') {
				for (int n = 0; n<j; n++)
					start += inputLine[n];
				splitNum = j;
			}
			if (inputLine[j] >= '0'&&inputLine[j] <= '9') {
				// if (go == -1) {
				bool exitCh = false;
				for(int p=j;p<inputLine.length();p++)
				    if(inputLine[p]>='A'&&inputLine[p]<='z'){
				        exitCh=true;
				        break;
				    }
				if(!exitCh){
					bool pNameExist = false;
					string temp = inputLine.substr(splitNum+1, j-splitNum-2);
					for (int p=0; p<pNum; p++){
						if(place[p] == temp){
							pNameExist = true;
							break;
						}
					}
					if(pNameExist){   
					numStartP = j;
				    break;
					}
					}
				}
				// }
				// else
					// back = inputLine[j] - '0';
			}
		
			for (int n = splitNum + 1; n<numStartP - 1; n++)
						end += inputLine[n];
						
		string numbers = inputLine.substr(numStartP);
		stringstream stream(numbers);
		stream>>go;
		if (!stream.eof())
			stream>>back;
		int startN;
		int endN;
		for (int j = 0; j<pNum; j++) {
			if (place[j] == start)
				startN = j;
			if (place[j] == end)
				endN = j;
		}

		adjMa[startN][endN] = go;
		if (back != -1)
			adjMa[endN][startN] = back;

	}


	priority_queue<node> q1,q2;

	// node n1;
	// n1.x = officeNum;
	// n1.p = -1;
	// n1.dis = 0;
	visitedOne[officeNum].dis = 0;

	// node n2;
	// n2.x = hallNum;
	// n2.p = -1;
	// n2.dis = 0;
	visitedTwo[hallNum].dis = 0;
	
	q1.push(visitedOne[officeNum]);
	q2.push(visitedTwo[hallNum]);
//  cout<<adjMa[0][0]<<endl<<visitedOne[2]<<endl;
	while (!q1.empty()) {
		node a = q1.top();
		q1.pop();
//		cout << a.x << endl << a.p << endl << a.dis << endl;
		for (int i = 0; i<pNum;i++) {
			if (adjMa[a.x][i] != -1 && (a.dis + adjMa[a.x][i])<visitedOne[i].dis) {
//				cout<<i<<endl;
				// node next;
				// next.x = i;
				// next.p = a.x;
				// next.dis = a.dis + adjMa[a.x][i];
				visitedOne[i].dis = a.dis + adjMa[a.x][i];
				visitedOne[i].p = a.x;
				q1.push(visitedOne[i]);
			}
		}
	}


	while (!q2.empty()) {
		node a = q2.top();
		q2.pop();
//		cout << a.x << endl << a.p << endl << a.dis << endl;
		for (int i = 0; i<pNum;i++) {
			if (adjMa[a.x][i] != -1 && (a.dis + adjMa[a.x][i])<visitedTwo[i].dis) {
//				cout<<i<<endl;
				// node next;
				// next.x = i;
				// next.p = a.x;
				// next.dis = a.dis + adjMa[a.x][i];
				visitedTwo[i].dis = a.dis + adjMa[a.x][i];
				visitedTwo[i].p = a.x;
				q2.push(visitedTwo[i]);
			}
		}
	}
		cout<<visitedOne[hallNum].dis+visitedTwo[officeNum].dis<<endl;

	// node test;
	// test = visitedOne[hallNum];

	// while(1){
	// 	cout<<place[test.x]<<endl;
	// 	if (test.p!=-1)
	// 		test = visitedOne[test.p];
	// 	else
	// 		break;
	// }

	// test = visitedTwo[officeNum];
	// while(1){
	// 	cout<<place[test.x]<<endl;
	// 	if (test.p!=-1)
	// 		test = visitedTwo[test.p];
	// 	else
	// 		break;
	// }

	node out;
	string s1[300], s2[300];
	int sCount=0;
	out = visitedOne[hallNum];

	while(1){
		s1[sCount] = place[out.x];
		sCount++;
		if (out.p!=-1)
			out = visitedOne[out.p];
		else
			break;
	}

	for (int i=sCount-1; i>=0; i--){
		cout<<s1[i]<<" -> ";
	}

	sCount = 0;
	out = visitedTwo[officeNum];

	while(1){
		s2[sCount] = place[out.x];
		sCount++;
		if (out.p!=-1)
			out = visitedTwo[out.p];
		else
			break;
	}

	for (int i=sCount-2; i>=0; i--){
		if(i>0)
			cout<<s2[i]<<" -> ";
		else
			cout<<s2[i];
	}
	cout<<endl<<endl;
}

}