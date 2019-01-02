#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	while(cin >> N >> M)
	{		
		set<int> g[30];
		bool awake[30]; memset(awake, 0, sizeof awake);

		string synap; cin >> synap;

		for(auto e : synap)
			awake[e - 'A'] = true;

		while(M--) {
			cin >> synap;
			g[synap[0] - 'A'].insert(synap[1] - 'A');
			g[synap[1] - 'A'].insert(synap[0] - 'A');
		}

		int answer = 0;
		while(true)
		{
			vector<int> v;
			for(int i=0; i<30; ++i) {
				if(awake[i]) continue;
				int cur = 0;
				for(auto e : g[i])
					if(awake[e]) ++cur;
				
				if(cur >= 3) v.push_back(i);
			}

			if(v.empty()) break;

			for(auto e : v)
				awake[e] = true;
			
			N -= v.size();
			++answer;
		}

		if(N == 3)
			cout << "WAKE UP IN, " << answer << ", YEARS" << endl;
		else
			cout << "THIS BRAIN NEVER WAKES UP" << endl;
		
	}
	return 0;
}
