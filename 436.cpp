#include <iostream>
#include <string>

using namespace std;

int prime[1000005];
int cPrime[1000005];


void gPrime(){
	for (int i = 0; i < 1000000; ++i)
	{
		prime[i] = 1;
	}

	prime[0] = 0;
	prime[1] = 0;

	for (int i = 2; i <= 1000000; ++i)
	{
		if (prime[i] == 0)
			continue;
		for (int j = i; j <= 1000000 / i; j++)
			prime[i*j] = 0;
	}
}

void getCPrime(){
	cPrime[0] = 0;
	cPrime[1] = 0;
	for (int i = 2; i < 1000000; ++i)
	{
		bool flag = true;
		if (prime[i] != 0){
			int tens = 1;
			int temp = i;
			while (temp /= 10)
				tens *= 10;
			int now = i / tens + i%tens * 10;
			while (now != i){
				if (prime[now] == 0){
					flag = false;
					break;
				}
				now = now / tens + now%tens * 10;
			}
		}
		else
			flag = false;

		if (flag)
			cPrime[i] = cPrime[i - 1] + 1;
		else
			cPrime[i] = cPrime[i - 1];
	}


}





int main(){
    
	gPrime();
	getCPrime();
	// for (int i = 0; i < 200; ++i)
	// {
	// 	cout << i << " " << cPrime[i] << endl;
	// }
	int a, b;
	while (1){
		cin >> a;
		if (a == -1)
			break;
		cin >> b;
		
		int result;
		
		if((cPrime[a]-cPrime[a-1])!=0||(cPrime[b]-cPrime[b-1])!=0)
		    result = cPrime[b] - cPrime[a]+1;
		else
		    result = cPrime[b] - cPrime[a];
		    
		

		if (result == 0)
			cout << "No Circular Primes." << endl;
		if (result == 1)
			cout << result << " Circular Prime." << endl;
		if (result>1)
			cout << result << " Circular Primes." << endl;

	}


}