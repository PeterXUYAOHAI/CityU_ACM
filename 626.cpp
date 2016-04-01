/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 22548
 * Submitted at:  2016-03-02 18:35:41
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    626
 * Problem Name:  Magic Boxes
 */

#include <iostream>
#include <string>
#include <math.h>
#include <string.h>

using namespace std;

unsigned long long int method[1000001];
long int box[20];

int main(){
	

	int N, M;
	int maxPos;
	while(cin>>N){
		cin>>M;
	memset(method, 0, sizeof(method));
	memset(box, 0, sizeof(box));

	for (int i=0; i<20; i++){
		
		
		if(pow (M, i)<=N){
		    box[i] = pow (M, i);
	//	    cout<<box[i]<<endl;
		    maxPos = i;
		    }  
		else
			break;
	}

//	unsigned long long int method[1000001];

    
    method[0]=1;
	for(int i=0; i<=maxPos; i++)
		for (int j=0; j+box[i]<=N ;j++){
			
// 			if(	(method[j+box[i]]+method[j])<0)
// 			    cout<<method[j+box[i]]<<endl<<method[j]<<endl<<box[i]<<endl;
            if(j+box[i]<=N){
			method[j+box[i]] += method[j];
			if (method[j+box[i]]>1000000007)
			    method[j+box[i]] = method[j+box[i]]%1000000007;
            }
		}


    // for(int i = 0 ; i<8; i++)
    //     cout<<method[i]<<endl;
	cout<<method[N]<<endl;

    // for(int i=0; i<9999; i++)
    //     if(method[i]<0){
    //         cout<<i<<endl<<method[i];
    //         break;
    //     }
        
        }


}