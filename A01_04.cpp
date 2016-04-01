#include <iostream>
#include <string>
#include <locale>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
  long double finalResult=0;

  while (!cin.eof()){

    string a;
    long double temp = 0;
    long double result;
    int dotPos = 0;
    cin >> a;
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
  cout << setprecision(4) << fixed << finalResult;





}