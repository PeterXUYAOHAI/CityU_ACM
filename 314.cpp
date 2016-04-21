/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 24647
 * Submitted at:  2016-04-10 22:14:10
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    314
 * Problem Name:  Extend to Palindromes (UVa 11475)
 */

#include <iostream>
#include <string>

using namespace std;



void kmp(string str, int next[], int n) {
	int i = 0, j = -1;
	next[0] = -1;
	while (i<n)
		if (j == -1 || str[i] == str[j]) next[++i] = ++j;
		else j = next[j];
}

int go_match(string str, string key, int next[], int nstr) {
	int i = 0, j = 0;
	while (i<nstr) {
		if (j == -1 || str[i] == key[j]) { i++;j++; }
		else j = next[j];
	}
	return j;
}


int main() {
	int next[100005];
	string input;
	while (cin >> input) {
		
		string reverInput = "";
		for (int i = input.length() - 1; i >= 0; --i)
			reverInput += input[i];

		kmp(reverInput, next, input.length());
		int matchlength = go_match(input, reverInput, next, input.length());

		for (int i = matchlength;i<reverInput.length();i++)
			input += reverInput[i];

		cout << input << endl;
	}

}