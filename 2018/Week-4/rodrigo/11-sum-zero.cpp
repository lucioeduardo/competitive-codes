// https://www.spoj.com/problems/SUMFOUR/
// TIME 2.14

#include <bits/stdc++.h>
#define MAX 2505
using namespace std;

int a[MAX], b[MAX], c[MAX], d[MAX];

int main()
{
	int n;
	scanf("%d", &n);

	vector<int> A(n*n, 0);
	vector<int> B(n*n, 0);
	vector<int>::iterator f, s;

	for(int i=0; i<n; ++i)
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);

	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			A[n*i + j] = -(a[i] + b[j]);
			B[n*i + j] = c[i] + d[j];
		}
	}

	int answer = 0;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for(auto &curr : A) {
		f = lower_bound(B.begin(), B.end(), curr);
		s = upper_bound(B.begin(), B.end(), curr);
		
		if(f != B.end() &&  (*f) == curr)
			answer += (s-f);
	}

	A.clear(); B.clear();
	printf("%d\n", answer);
	return 0;
}