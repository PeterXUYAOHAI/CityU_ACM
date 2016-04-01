/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 20554
 * Submitted at:  2016-01-31 23:58:12
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    688
 * Problem Name:  Playing Chess
 */

#include<iostream>


#include<string>
#include<string.h>

using namespace std;


char chessM[8][8];
int steps[8][8];

int main()
{
    int caseSum;
    int dest=0;
    cin >> caseSum;
    char temp;
    int known[100] = {0}, store_known[100] = {0};
    
    for(int caseNum = 0; caseNum<caseSum ; caseNum++)
    {
        for(int i=0; i< 8; i++)
            for (int j =0; j<8 ;j++)
            {
                cin >> temp;
                chessM[i][j] = temp;
                switch (temp)
                {
                    case '#': {
                        steps [i][j] = 0;
                        known[0] = i*9+j + 1; // 1 to 64
                        break;
                    }
                    case '@': {
                        dest = i*9+j+1;
                        steps [i][j] = 99999;
                        break;
                    }
                    case '-': steps [i][j] = 99999; break;
                    case '*': steps [i][j] = -1; break;
                }
            }
        
       
        while (known [0] != 0)
        {
            int count = 0;
            for(int i=0; i< 100; i++)
            {
                if (known[i] == 0) break;
                int row = known[i]/9, col = known[i]%9 -1, new_row=0, new_col=0;
                bool get;
                
                
                
                for (int z=0; z< 8 ;z++)
                {
                    
                    switch (z)
                    {
                    case 0: new_row = row + 1; new_col = col +2; break;
                    case 1: new_row = row - 1; new_col = col +2; break;
                        
                    case 2: new_row = row + 1; new_col = col -2; break;
                        
                    case 3: new_row = row - 1; new_col = col -2;break;
                    
                    case 4: new_row = row + 2; new_col = col +1;break;
                
                    case 5: new_row = row - 2; new_col = col +1;break;
                
                    case 6: new_row = row + 2; new_col = col -1;break;
                    
                    case 7: new_row = row - 2; new_col = col -1;break;
                    }
                    
                    get = (new_row > -1 && new_row < 8 && new_col > -1 && new_col < 8);
                    

                    if (steps[row][col] + 1 < steps[new_row][new_col] && get)
                    {
                        store_known[count++] = new_row *9 +new_col + 1;
                        
                       
                        steps[new_row][new_col] = steps[row][col] + 1;
                    }
                }
            }
            

            
            for(int i=0; i< 100; i++)
            {
                known[i] = store_known[i];
                store_known[i] = 0;
            }
  
            
        }
        
        
       if (steps [dest/9] [dest%9 -1] == 99999)
        cout << "Case " << caseNum+1 <<": " << "IMPOSSIBLE" << endl;
       else
        cout << "Case " << caseNum+1 <<": " << steps [dest/9] [dest%9 -1]<< endl;
    }
    return 0;

}