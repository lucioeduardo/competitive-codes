#include <bits/stdc++.h>
using namespace std;

void calc(queue<int> &q, int l) {
	int carge = 0;

	while(!q.empty() && (carge + q.front()) <= (l*100)) {
		carge += q.front();
		q.pop();
	}
}

int main()
{
	queue<int> L, R;
	int n, l, m, x;
	string s;
	cin >> n;

	while(n--) {
		cin >> l >> m;

		while(m--) {
			cin >> x >> s;

			if(s == "left")
				L.push(x);
			else
				R.push(x);
		}

		int answer = 0;
		bool side = false;
		
		while(!L.empty() or !R.empty())
		{
			if(side) calc(R, l);
			else calc(L, l);
			
			side = !side;
			++answer;
		}
		cout << answer << endl;
	}

	return 0;
}
