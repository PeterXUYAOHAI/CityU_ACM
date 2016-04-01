/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 19220
 * Submitted at:  2016-01-19 21:23:35
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    108
 * Problem Name:  Birthdates
 */

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int sum;
    int cur = 0;
    string maxName = "";
    string minName = "";
    int maxBirthday=0;
    int minBirthday=99999999;
    
    cin>>sum;
    
    while (cur<sum){
        string tempName;
        int year;
        int month;
        int day;
        int value;
        
        cin>>tempName>>day>>month>>year;
        
        value = year*10000+month*100+day;
                
        if (value>maxBirthday){
            maxName = tempName;
            maxBirthday = value;
        }
        if (value<minBirthday){
            minName = tempName;
            minBirthday = value;
        }
        cur++;
    }
    cout<<maxName<<endl;
    cout<<minName<<endl;
}
    