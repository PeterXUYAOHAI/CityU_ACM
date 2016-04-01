/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 21356
 * Submitted at:  2016-02-16 22:25:17
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    216
 * Problem Name:  Longest Common Subsequence (UVa 10405)
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
	string a;
	string b;

	while(getline(cin, a)){
        getline(cin, b);
	int m = a.length();
	int n = b.length();

	int matrix[1010][1010];

	for (int i = 0; i<m;i++)
		matrix[i][0] = 0;
	for (int i = 0; i<n;i++)
		matrix[0][i] = 0;

	for (int i = 0; i<m;i++) {
		for (int j = 0; j<n; j++) {
			if (a[i] == b[j])
				matrix[i][j] = matrix[i - 1][j - 1] + 1;
			else if (matrix[i - 1][j] >= matrix[i][j - 1])
				matrix[i][j] = matrix[i - 1][j];
			else
				matrix[i][j] = matrix[i][j - 1];
		}

		
	}
	cout << matrix[m - 1][n - 1]<<endl;
}
}