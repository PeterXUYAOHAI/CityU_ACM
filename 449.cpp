/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 19577
 * Submitted at:  2016-01-22 21:57:06
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    449
 * Problem Name:  Beach Length
 */

#include <iostream>
#include <string>

using namespace std;

void calculateRowlength(int numOfRow, string* rows){
	int columLen = rows[0].length();
	int rowLen = numOfRow;
	int beachLen = 0;
	string* input = rows;

		for(int i = 0; i<rowLen; i++){
			for (int j = 0; j<columLen; j++){
				if (input[i][j] == '.')
					continue;
				if (i % 2 == 1){
					if ((i - 1) >= 0){
						if (input[i - 1][j] == '.')
							beachLen++;
						if ((j + 1)<columLen&&input[i - 1][j + 1] == '.')
							beachLen++;
					}
					if ((j - 1) >= 0 && input[i][j - 1] == '.')
						beachLen++;
					if ((j + 1)<columLen&&input[i][j + 1] == '.')
						beachLen++;

					if ((i + 1)<rowLen){
						if (input[i + 1][j] == '.')
							beachLen++;
						if ((j + 1)<columLen&&input[i + 1][j + 1] == '.')
							beachLen++;
					}
				}
				if (i % 2 == 0){
					if ((i - 1) >= 0){
						if (input[i - 1][j] == '.')
							beachLen++;
						if ((j - 1) >= 0 && input[i - 1][j - 1] == '.')
							beachLen++;
					}
					if ((j - 1) >= 0 && input[i][j - 1] == '.')
						beachLen++;
					if ((j + 1)<columLen&&input[i][j + 1] == '.')
						beachLen++;

					if ((i + 1)<rowLen){
						if (input[i + 1][j] == '.')
							beachLen++;
						if ((j - 1) >= 0 && input[i + 1][j - 1] == '.')
							beachLen++;
					}
				}

			}
		}
	cout << beachLen << endl;

}






int main()
{
	string line;
	string rows[200];
	int numOfRow = 0;

	while (getline(cin, line)){
		if (line.length() != 0)
			rows[numOfRow++] = line;
		else{
			calculateRowlength(numOfRow, rows);
			numOfRow = 0;
		}
	}

}


