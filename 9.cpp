/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 21425
 * Submitted at:  2016-02-17 23:09:54
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    9
 * Problem Name:  String Computer
 */

#include <iostream>
#include <string>

using namespace std;


	string a;
	string b;
	int op[1010][1010];
	int matrix[1010][1010];


void output(int m, int n){
	if(m==0&&n==0)
		return;
	if(op[m][n]==1){
		output(m-1,n);
		printf("D%c%02d",a[m-1],n+1);
	}
	else if (op[m][n]==2){
		output(m,n-1);
		printf("I%c%02d", b[n-1], n);
	}
	else if(op[m][n]==3){
		output(m-1,n-1);
		printf("C%c%02d", b[n-1],n);
	}else output(m-1,n-1);



}


int main() {
	

	while(cin>> a){
	    if(a=="#")
	     break;
        cin>>b;
	int m = a.length();
	int n = b.length();

 for ( int i = 0 ; i <= m ;  ++i )  
        for ( int j = 0 ; j <= n ;  ++j ) {  
            matrix[i][j] = 500;  
            op[i][j] = 0;  
        }  
	
	for (int i = 0; i<=m;++i){
		op[i][0]=1;matrix[i][0] = i;}
	for (int i = 0; i<=n;++i){
		op[0][i]=2;matrix[0][i] = i;}

	for (int i = 1; i<=m;++i) {
		for (int j = 1; j<=n; ++j) {
			if (a[i-1] != b[j-1]){
				matrix[i][j] = matrix[i - 1][j - 1] + 1;
				op[i][j] = 3;
			}else matrix[i][j]=matrix[i-1][j-1];
			if (matrix[i - 1][j]+1 < matrix[i][j]){
				matrix[i][j] = matrix[i -1][j]+1;
				op[i][j]=1;
			}
			if(matrix[i][j-1]+1<matrix[i][j]){
				matrix[i][j] = matrix[i][j - 1]+1;
				op[i][j]=2;
			}
		}
	}
	output(m,n);
    cout<<"E"<<endl;

}
}