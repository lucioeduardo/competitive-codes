// https://br.spoj.com/problems/TROCCARD/
// TIME 0.02

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, x;
	map<int, int> card;

	while(scanf("%d %d", &n, &m) && n+m) {
		int op1 = 0;
		int op2 = 0;

		for(int i=0; i<n; ++i) {
			scanf("%d", &x);
			card[x] = 1;
		}

		while(m--) {
			scanf("%d", &x);

			if(!card.count(x))
				card[x] = 2;
			else if(card[x] == 1)
				card[x] = 3;
		}

		for(auto &e : card) {
			if(e.second == 1)
				++op1;
			else if(e.second == 2)
				++op2;
		}
		card.clear();
		printf("%d\n", min(op1, op2));
	}

	return 0;
}