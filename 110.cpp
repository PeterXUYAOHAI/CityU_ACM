/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 19467
 * Submitted at:  2016-01-22 16:08:24
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    110
 * Problem Name:  Longest Word
 */

#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main()
{
   int maxLength=0;
   string maxWord;
   string inputWord;
   locale loc;
   string result = "";
   
   cin>>inputWord;
   maxWord = inputWord;
   
   while(inputWord!="E-N-D"){
       int tempLength = 0;
      for (int i=0; i<inputWord.length(); i++){
        char cTemp = inputWord[i];
        if ((cTemp <= 'z' && cTemp >= 'a') || (cTemp <= 'Z' && cTemp >= 'A')||cTemp=='-')
                tempLength++;
      }


        
       if (tempLength>maxLength){
           maxLength = tempLength;
           maxWord = inputWord;
       }
       cin>>inputWord;
   }
   
   
  for (string::size_type i=0; i<maxWord.length(); i++){
       if ((maxWord[i] <= 'z' && maxWord[i] >= 'a') || (maxWord[i] <= 'Z' && maxWord[i] >= 'A')||maxWord[i]=='-')
            result+=tolower(maxWord[i],loc);
   
  }
  cout<<result<<endl;
   return 0;
   
   
}