/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 19551
 * Submitted at:  2016-01-22 21:03:59
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    222
 * Problem Name:  Simple Calculation (II)
 */

#include <iostream>
#include <string>
#include <locale>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	int flag = 0;
	string line;
	while (getline(cin, line)){
		string input[100];
		int nums = 0;
		string temp = "";
		for (int i = 0; i <= line.length(); i++){
			
			if (line[i] == ' ' || i == (int)line.length()){
				input[nums++] = temp;
				temp = "";
			}
			else{
				temp += line[i];
			}
		}
		long double finalResult = 0;
		for (int i = 0; i<nums; i++){

			string a = input[i];
			long double temp = 0;
			long double result;
			int dotPos = 0;
			for (int i = 0; i < a.length(); i++){
				if (a[i] == '.')
					dotPos = i;
			}
			for (int i = 0; i < a.length(); i++){
				if (dotPos != 0){
					if (i < dotPos){
						long double b = (double)(a[i] - '0');
						long double power = pow(10, (dotPos - i - 1));
						temp += b*power;
					}
					if (i > dotPos){
						long double b = (double)(a[i] - '0');
						long double power = pow(10, (dotPos - i));
						temp += b*power;
					}
				}
				if (dotPos == 0){
					long double b = (double)(a[i] - '0');
					long double power = pow(10, (a.length() - i - 1));
					temp += b*power;
				}
			}
			finalResult += temp;
		}
		//  result = temp / pow(10, (a.length()-dotPos));
		if (flag == 0){
			cout << setprecision(4) << fixed << finalResult<<endl;
			flag++;
		}
		else{
			cout << endl << setprecision(4) << fixed << finalResult << endl;
		}


	}









}