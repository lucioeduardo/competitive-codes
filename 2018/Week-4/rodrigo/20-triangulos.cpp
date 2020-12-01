// https://www.urionlinejudge.com.br/judge/pt/problems/view/1472
// TIME 0.044

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, x;
	vector<int> dist;
	
	while(scanf("%d", &n) != EOF)
	{
		int arc = 0;
		int answer = 0;

		for(int i=0; i<n; ++i) {
			scanf("%d", &x);
			arc += x;
			dist.push_back(arc);
		}

		if(arc % 3 == 0) {
			arc = arc / 3;

			for(int i=0; i<n; ++i) {
				if(dist[i] > arc)
					break;
				if(binary_search(dist.begin()+i, dist.end(), dist[i]+arc) && binary_search(dist.begin()+i+1, dist.end(), dist[i] + 2*arc))
					++answer;
			}
		}

		printf("%d\n", answer);
		dist.clear();
	}
	return 0;
}