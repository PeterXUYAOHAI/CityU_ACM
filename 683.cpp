/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 19427
 * Submitted at:  2016-01-22 01:17:00
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    683
 * Problem Name:  Nuts
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
 int maxSection;
  int totalNuts;
  int divisors;
  int secCap;
  int totalBox =0;
   while(cin>>maxSection>>totalNuts>>divisors>>secCap){ 
  
  
  
  while(totalNuts>0){
      if ((maxSection-1)<divisors){
          totalNuts -= secCap*maxSection;
          totalBox++;
          divisors-=(maxSection-1);
      }
      else if ((maxSection-1)>=divisors){
          totalNuts -= (divisors+1)*secCap;
          divisors = 0;
          totalBox++;
      }
  }
  
  cout<<totalBox<<endl;
    totalBox=0;  
      
      
   }
}