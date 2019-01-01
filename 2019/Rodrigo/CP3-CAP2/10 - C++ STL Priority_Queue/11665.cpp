#include <bits/stdc++.h>
using namespace std;

int s[1010], q[1010];

int main()
{
	int n, op, x;
	while(scanf("%d", &n) != EOF)
	{
		priority_queue<int> pQ;

		int t = 0; // stack
		int i = 0, j = 0; // queue

		bool S, Q, P;
		S = Q = P = true;

		while(n--)
		{
			scanf("%d %d", &op, &x);
			
			if(op == 1){
				if(S) s[t++] = x;
				if(Q) q[j++] = x;
				if(P) pQ.push(x);
			} else {
				if(!t || (S && x != s[--t]))   S = false;
				if(i == j || (Q && x != q[i++])) Q = false;
				if(pQ.empty() || (P && x != pQ.top())) P = false;
				else pQ.pop();
			}
		}

		if(!P && !Q && !S)
			printf("impossible\n");
		else if(P && !Q && !S)
			printf("priority queue\n");
		else if(Q && !P && !S)
			printf("queue\n");
		else if(S && !Q && !P)
			printf("stack\n");
		else
			printf("not sure\n");
	}
	return 0;
}
