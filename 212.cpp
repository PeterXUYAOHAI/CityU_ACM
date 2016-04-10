#include <iostream>
#include <string>

using namespace std;

long long int B, P, M;

long long int bigMod(long long int b, long long int p, long long int m){
	if (p == 0)
		return 1;


	if (p % 2){
		return ((b % m) * (bigMod(b, p - 1, m))) % m;
		
	}
	else{
		long long int result = bigMod(b, p / 2, m);
		return (result%m)*(result%m) % m;
	}
		

}


int main(){


	while (cin>>B){
	    cin>>P>>M;
	

	cout<<bigMod(B,P,M)<<endl;
	}



}