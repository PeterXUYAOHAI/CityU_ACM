/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 18763
 * Submitted at:  2016-01-16 17:49:57
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    692
 * Problem Name:  Find Largest Prime Substring
 */

#include <iostream>
#include<string>

using namespace std;
int main() {

 int a[10000];
 
 a[0] =2;
 
 int pos = 0;
 
 for(int i = 2; i<100000; i++){
     for (int j=0; j<=pos; j++){
         if (i%a[j]==0)
            break;
        if (j==pos){
            a[++pos] = i;
        }
     }
 }
 

 
 //string input[10000];
 string inc;

 //int ippos=0;

 while(cin>>inc && inc!="0"){
    int results[1000];
    int resultpos = 0;
    int j = inc.length()<=5?inc.length():5;
    for(; j>0; j--){
      for(int z=0; z<=(inc.length()-j);z++){
            string temp = inc.substr(z,j);
            int test = stoi (temp);
        for (int y=0; y<=pos;y++){
          if(test<a[y])
            break;
          if (test==a[y]){
            results[resultpos++] = a[y];
          }
        }
    }
   
}

    int max = 2;
    for (int j=0;j<resultpos;j++){
      max = max>results[j]?max:results[j];
    }
    printf("%d\n",max);
     
     
     
 }


// for(int i=0;i<ippos;i++) {    
//   string inc = input[i];
 
//     int results[100];
//     int resultpos = 0;
//     int j = inc.length()<=5?inc.length():5;
//     for(; j>0; j--){
//       for(int z=0; z<=(input[i].length()-j);z++){
//             string temp = input[i].substr(z,j);
//             int test = stoi (temp);
//         for (int y=0; y<=pos;y++){
//           if(test<a[y])
//             break;
//           if (test==a[y]){
//             results[resultpos++] = a[y];
//           }
//         }
//     }
   
// }

//     int max = 2;
//     for (int j=0;j<resultpos;j++){
//       max = max>results[j]?max:results[j];
//     }
//     printf("%d\n",max);

// }

 return 0;
}
