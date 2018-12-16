#include <bits/stdc++.h>
#define S second
#define F first
#define pii pair<int, int>

using namespace std;

bool compare(pair<int, pii > &p1, pair<int, pii > &p2){
	if(p1.F != p2.F)
		return p1.F > p2.F;
	if(p1.S.F != p2.S.F)
		return p1.S.F < p2.S.F;

	return p1.S.S < p2.S.S;
}

int main()
{
	int test, status[105][15];
	char str[150];

	scanf("%d ", &test);
	pair<int, pii > score[105];

	for(int t=0; t<test; ++t)
	{
		int team, problem, minute;
		char veredict;

		memset(status, 0, sizeof status);

		for(int i=0; i<105; ++i)
			score[i] = {0, {0, i}};

		while(scanf("%[^\n]s", str) == 1)
		{
			getchar();
			sscanf(str, "%d %d %d %c", &team, &problem, &minute, &veredict);

			status[team][0] = 1; // indicates that the team was a submission

			if(status[team][problem] != -1) { // -1 indicates that it is solved
				if(veredict == 'C') {
					score[team].S.F += (minute + status[team][problem]);
					++score[team].F;
					status[team][problem] = -1;
				} else if( veredict == 'I') {
					status[team][problem] += 20;
				}
			}
		}

		sort(score+1, score + 101, compare);
		if(t) printf("\n");

		for(int i=1; i<=100; ++i) {
			int index = score[i].S.S;
			if(status[index][0] == 1)
				printf("%d %d %d\n", index, score[i].F, score[i].S.F);
		}

		getchar();
	}
	return 0;
}
