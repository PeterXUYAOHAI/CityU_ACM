/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 24565
 * Submitted at:  2016-04-08 21:40:19
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    462
 * Problem Name:  Goldbach and Euler (UVa 10311)
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

bool prime[50000005];

void gPrime(){
	memset(prime, 1, sizeof(prime));
	prime[0] = 0;
	prime[1] = 1;

	for (int i = 1; i <= 100000000; i += 2){
		if (prime[(i - 1) >> 1] == 0)
			continue;
		for (int j = i; j <= 100000000 / i; j += 2){
			//		    cout<<2*i*j+i+j<<endl;
			prime[(i*j - 1) >> 1] = 0;
		}
	}

}


int main(){
	gPrime();

	int input;
	int first, second;

	while (scanf("%d", &input)){

	
		bool flag = false;

		if (input & 1){
			if (prime[(input - 3) >>1] == 1){
				flag = true;
				first = 2;
				second = input - 2;
			}
		}
		else{
			if ((input >>1) & 1){
				for (int i = input / 2; i > 2; i -= 2)
				{
					if (prime[(i - 1) >>1] == 1 && prime[(input - i - 1) >>1] == 1){
						flag = true;
						first = i;
						second = input - i;
						break;
					}
				}

			}
			else{

				for (int i = (input / 2 - 1); i > 2; i -= 2)
				{
					if (prime[(i - 1) >>1] == 1 && prime[(input - i - 1) >>1] == 1){
						flag = true;
						first = i;
						second = input - i;
						break;
					}
				}
			}

		}


		if (flag)
			printf("%d is the sum of %d and %d.\n", input, first, second);
		//cout << input << " is the sum of " << first << " and " << second << "." << endl;
		else
			printf("%d is not the sum of two primes!\n", input);
		//cout << input << " is not the sum of two primes!" << endl;

		// 	for (int i = 0; i < 100; ++i)
		// 	{
		// 		cout <<i<<" "<< prime[i]<<endl;
		// 	}
		//	}
	}

}