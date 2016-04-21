/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 20373
 * Submitted at:  2016-01-30 17:08:26
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    22
 * Problem Name:  Prime Path
 */

#include <iostream>
#include <string>
#include <queue>
#include <stdio.h>
#include <string.h>

using namespace std;

int prime[9000];

int primeCount = 1;


void genePrime(){
	prime[0] = 2;
	for (int i = 3; i < 9999; i++){
		for (int j = 0; j < primeCount; j++){
			if (i%prime[j] == 0)
				break;
			if (j == (primeCount - 1))
				prime[primeCount++] = i;
		}



	}

}

bool isPrime(int x){
	for (int i = 168; i < primeCount; i++){
		if (x == prime[i])
			return true;
	}
	return false;
}








int main(){
	genePrime();
	int caseNum = 0;
	cin>>caseNum;
	
	while (caseNum--){
	int visited[10000];
	queue<int> myQueue;
	memset(visited, 0, sizeof(visited));
	
	int start;
	int dest;
	cin >> start >> dest;

	visited[start] = 1;
	myQueue.push(start);
    bool found =false;
	while (!myQueue.empty()){
	    int step = 0;
		int x = myQueue.front();
		myQueue.pop();
		step = visited[x];
		if (x == dest){
			cout << (step-1) << endl;
			found =true;
			break;
		}

		int x1000 = x / 1000 * 1000;
		int x100 = (x - x1000) / 100 * 100;
		int x10 = (x - x1000 - x100) / 10 * 10;
		int x1 = x - x1000 - x100 - x10;

			for (int i = 0; i < 10; i++){
				if (i != 0 && isPrime(i * 1000 + x100 + x10 + x1) && visited[i * 1000 + x100 + x10 + x1] == 0){
					myQueue.push(i * 1000 + x100 + x10 + x1);
					visited[i * 1000 + x100 + x10 + x1] = (step+1);
				}
				if (isPrime(x1000 + i * 100 + x10 + x1) && visited[x1000 + i * 100 + x10 + x1] == 0){
					myQueue.push(x1000 + i * 100 + x10 + x1);
					visited[x1000 + i * 100 + x10 + x1] = (step + 1);
				}

				if (isPrime(x1000 + x100 + i * 10 + x1) && visited[x1000 + x100 + i * 10 + x1] == 0){
					myQueue.push((x1000 + x100 + i * 10 + x1));
					visited[x1000 + x100 + i * 10 + x1] = (step + 1);
				}

				if (isPrime(x1000 + x100 + x10 + i) && visited[x1000 + x100 + x10 + i] == 0){
					myQueue.push(x1000 + x100 + x10 + i);
					visited[x1000 + x100 + x10 + i] = (step + 1);
				}
			}
	}
	if(!found)
	cout<<"Impossible"<<endl;
	}





}