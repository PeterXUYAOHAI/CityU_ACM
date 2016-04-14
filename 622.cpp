#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

int gap = 1;
int length;
int pos[1005];

bool sufCmp(int i, int j) {
	if (pos[i] != pos[j])
		return pos[i]<pos[j];
	i += gap;
	j += gap;
	return (i<length&&j<length) ? pos[i]<pos[j] : i>j;
}




int main() {
	string input;
	int caseNum;
	cin>>caseNum;

	while(caseNum--){
	cin >> input;
	memset(pos,0,sizeof(pos));

	int sa[1005];
	int tmp[1005];
	int lcs[1005];
	length = input.length();
	for (int i = 0; i < length; ++i)
	{
		sa[i] = i;
		pos[i] = input[i];
	}

	for (gap = 1;;gap *= 2) {

		sort(sa, sa + length, sufCmp);

		for (int i = 0; i < length - 1; ++i)
			tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
		for (int i = 0; i < length; ++i)
			pos[sa[i]] = tmp[i];

		if (tmp[length - 1] == length - 1) break;

	}

	lcs[0] = 0;
	int max = 0;
	int maxPos = 0;
	for (int i = 1; i < length; ++i)
	{
		int count = 0;
		int a = sa[i];
		int b = sa[i - 1];
		while (a<length&&b<length) {
			if (input[a] != input[b])
				break;
			count++;
			a++;
			b++;
		}
		lcs[i]=count;
		if(count>max){
			max=count;
			maxPos=sa[i];
		}

	}
	int occer = 2;
	int maxi=0;
	for (int i = 0; i < length; ++i)
	{
//	    cout<<lcs[i]<<endl;
		if(lcs[i]==max){
//		    cout<<"lcs"<<lcs[i]<<"max"<<max<<endl;
			max=lcs[i]; maxPos=sa[i]; maxi=i;
			break;
			}
	}
//    cout<<"maxi "<<maxi<<endl;
	for (int i = maxi+1; i < length; ++i)
	{
		if(lcs[i]!=max)
		    break;
//		else if(lcs[i]==lcs[i-1])
 //   cout<<"pos"<<i<<endl;
			occer++;
	}

	if(max==0)
		cout<<"No repetitions found!"<<endl;
	else{
//	    cout<<"max "<<max<<endl;
		string repString = "";
		for (int i = maxPos; i < maxPos+max; ++i)
		{
			repString+=input[i];
		}
		cout<<repString<<" "<<occer<<endl;

	}
}



}