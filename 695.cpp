/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 24551
 * Submitted at:  2016-04-08 20:25:55
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    695
 * Problem Name:  Exponentiation
 */

#include <iostream>
#include <string>
#include <string.h>

using namespace std;


string cleanZero(string input) {

	string output = "";
	int postNonZpos = 0;
	int preNonZpos=0 ;

	for (int i = input.length() - 1; i >= 0; --i)
		if (input[i] != '0'&&input[i] != '.') {
			postNonZpos = i;
			break;
		}

	for (int i = 0; i < input.length() - 1; ++i)
		if (input[i] != '0') {
// 			if (input[i] == '.')
// 				preNonZpos = i - 1;
// 			else
				preNonZpos = i;
			break;
		}

	for (int i = preNonZpos; i <= postNonZpos; ++i)
		output += input[i];

	return output;

}







string mulitply(string a, string b) {

	int result[10000];
	memset(result, 0, sizeof(result));

	for (int i = 0; i < b.length(); ++i)
		for (int j = 0; j < a.length(); ++j)
			result[i + j + 1] += ((b[i] - '0')*(a[j] - '0'));

	int carry = 0;
	for (int i = (a.length() + b.length() - 1); i > 0; i--)
	{
		int temp = result[i] + carry;
		result[i] = temp % 10;
		carry = temp / 10;
	}
	result[0] = carry;

	string output = "";
	for (int i = 0; i <= (a.length() + b.length() - 1); ++i)
	{
		if (i == 0 && result[i] == 0)
			continue;

		output = output + (char)(result[i] + '0');
	}

	return output;

}

string power(string input, int times) {
	if (times == 0)
		return "1";
	if (times == 1)
		return input;
	if (times == 2)
		return mulitply(input, input);

	if (times & 1)
		return mulitply(power(power(input, times / 2), 2), input);
	else
		return power(power(input, times / 2), 2);



}



int main() {

	string input;
	int times;

	while (cin >> input) {

		cin >> times;
		int dotPos = 0;
		string pruned = "";
		for (int i = 0; i < input.length(); ++i)
		{
			if (input[i] == '.') {
				dotPos = input.length() - 1 - i;
			}
			else {
				pruned += input[i];
			}
		}

		

		string interm = power(pruned, times);


		int newDotpos = interm.length() - dotPos*times;

		string intermWithDot = "";
		for (int i = 0; i < newDotpos; ++i)
			intermWithDot += interm[i];
		if (newDotpos != interm.length())
			intermWithDot += '.';
		for (int i = newDotpos; i < interm.length(); ++i)
			intermWithDot += interm[i];




		cout << cleanZero(intermWithDot) << endl;

	}



}