#include <iostream>
#include <string>

using namespace std;

bool prime[100000005];

void gPrime(){
	for (int i = 0; i <= 100000000; ++i)
		prime[i] = 1;
	prime[0] = 0;
	prime[1] = 0;

	for (int i = 2; i <= 100000000; ++i){
		if (prime[i] == 0)
			continue;
		for (int j = i; j <= 100000000 / i; ++j)
			prime[i*j] = 0;
	}

}


int main(){
	gPrime();

	int input;

	while(cin>>input){

	int first, second;
	bool flag=false;

	if(input&1){
		if(prime[input-2]==1){
			flag=true;
			first = 2;
			second = input-2;
		}
	}
	else{
		for (int i = input/2; i > 2; --i)
		{
			if(prime[i]==1&&prime[input-i]==1){
				flag=true;
				first = i ;
				second = input-i;
				break;
			}
		}
	}


	if(flag)
		cout<<input<<" is the sum of "<<first<<" and "<<second<<"."<<endl;
	else
		cout<<input<<" is not the sum of two primes!"<<endl;

	// for (int i = 0; i < 100; ++i)
	// {
	// 	cout <<i<<" "<< prime[i]<<endl;
	// }
		}

}