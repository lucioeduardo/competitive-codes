// https://br.spoj.com/problems/ELEICOES/
// TIME 0.10

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, x;
	map<int, int> votes;

	scanf("%d", &n);

	while(n--) {
		scanf("%d",&x);
		++votes[x];
	}
	int answer = 0;

	for(auto &e : votes) {
		if(e.second > votes[answer])
			answer = e.first;
	}

	printf("%d\n", answer);
	votes.clear();
	return 0;
}