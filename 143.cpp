#include <iostream>
#include <string>

using namespace std;



int A[30010];



int Find(int e) {
	if (A[e] == -1)
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
	if(A[root1]<A[root2])
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

		for (int i = 1; i <= size; i++) {
			if (A[i] == -1)
				count[i]++;
			else
				count[Find(A[i])]++;
		}

		int max = 0;

		for (int i = 1; i <= size; i++) {
			max = count[i]>max ? count[i] : max;
		}

		cout << max << endl;

	}
}
