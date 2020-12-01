// https://br.spoj.com/problems/ALIENSMG/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string dna;
	while(cin >> n && n)
	{
		map<string, int> m;

		while(n--) {
			cin >> dna;
			sort(dna.begin(), dna.end());
			++m[dna];
		}

		int answer = 0;
		for(auto &e : m)
			++answer;

		printf("%d\n", answer);
	}
	return 0;
}