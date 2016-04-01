/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 23299
 * Submitted at:  2016-03-15 00:18:33
 *
 * User ID:       146
 * Username:      53546028
 * Problem ID:    142
 * Problem Name:  FRIENDS (UVa 10608)
 */

#include <iostream>
#include <string>

using namespace std;



int A[30010];



int Find(int e) {
	if (A[e] < 0)
		return e;
	else
		return A[e] = Find(A[e]);
}

void UnionSet(int s1, int s2) {
	A[s1] += A[s2];
	A[s2] = s1;
}

void Union(int e1, int e2) {
	int root1 = Find(e1);
	int root2 = Find(e2);
	if (root1 == root2)
		return;
	if (A[root1]<A[root2])
		UnionSet(root1, root2);
	else
		UnionSet(root2, root1);

}


int main() {


	int count[30010];
	int size, pair;
	int caseNum;

	cin >> caseNum;

	while (caseNum--) {


		cin >> size >> pair;

		for (int i = 1; i <= size; i++) {
			A[i] = -1;

			count[i] = 0;
		}


		while (pair--) {
			int se1, se2;
			cin >> se1;
			cin >> se2;
			Union(se1, se2);
			
		}

		int max = 0;
		for (int i = 1; i <= size; i++)
		if (A[i] < 0 && -A[i]>max)
			max = -A[i];

		cout << max << endl;
		
	
	

	}
}
