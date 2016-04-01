/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 21574
 * Submitted at:  2016-02-20 14:16:21
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    570
 * Problem Name:  High Score
 */

#include <iostream>
#include <string>

using namespace std;

int main(){

	int caseNum;
	string input;
    cin>>caseNum;
	while(caseNum--){
		cin>>input;
		int sum =0;
		int len =  input.length();
		int result;

		for (int i=0; i<len; i++){
			if (input[i]-'A'> (26 - (input[i] - 'A')))
				sum+=(26 - (input[i] - 'A'));
			else 
				sum+=input[i]-'A';
		}

		result = len-1;

		for(int i=1; i<len; i++){
			if (input[i]=='A'){
				int j =0;
				// for(j = i+1; j<=len;j++)
				//     if(input[j]!='A')
				//         break;
				for (j = i + 1; j < len && input[j] == 'A'; ++j)  
                    ;  
				int left = (i-1)*2 + len-j;
				int right =  (len-j)*2 +i-1;

				if (result<left&&result<right)
					continue;
				else if(left<=right&&left<result)
					result = left;
				else if (right<=left&&right<result)
					result = right;
			}



			}
		cout<<result+sum<<endl;


	}


}