// http://codeforces.com/contest/664/problem/A#

#include <bits/stdc++.h>
#define MAX 110

int main()
{
	char n[MAX], m[MAX];
	scanf("%s %s", n, m);
	puts(strcmp(n, m) ? "1" : n);
	return 0;
}