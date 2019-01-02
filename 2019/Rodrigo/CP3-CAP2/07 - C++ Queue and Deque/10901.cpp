// 10901 - Ferry Loading III

#include <bits/stdc++.h>
using namespace std;

vector<int> answer;

void advance(vector<pair<int, int> > &v, int &ind, int &qtd, bool &side, int t, int curr, bool signal) {
	answer[v[ind].second] = v[ind].first + ((curr + t) - v[ind].first);
	++ind;
	++qtd;
	side = signal;
}

void calc(vector<pair<int, int> > &v, int ind, int t, int &curr, bool &side, bool signal) {
	if((side && !signal) or (!side && signal)) {
		curr = max(v[ind].first + t, curr + t);
		side = signal;
	} else curr = max(curr, v[ind].first);
}

int main()
{
	int c, x, n,m,t;
	cin >> c;

	for(int k=0; k<c; ++k)
	{
		vector<pair<int, int> > left, right;
		cin >> n >> t >> m;
		answer.resize(m);

		if(k) cout << endl;

		for(int i=0; i<m; ++i) {
			string side;

			cin >> x >> side;
			if(side == "left") left.push_back({x, i});
			else right.push_back({x, i});

		}

		int l, r, curr;
		bool side = false;
		l = r = curr = 0;

		while(l < left.size() || r < right.size())
		{
			int qtd = 0;

			if(!side) {
				while(l < left.size() && left[l].first <= curr && qtd != n)
					advance(left, l, qtd, side, t, curr, true);
				if(side)
					curr += t;

			} else {
				while(r < right.size() && right[r].first <= curr && qtd != n)
					advance(right, r, qtd, side, t, curr, false);
				if(!side)
					curr += t;
			}

			if(qtd == 0)
			{
				if(l >= left.size() && r >= right.size()) {
					continue;

				} else if(l >= left.size() || (r < right.size() && right[r].first < left[l].first)) {
					calc(right, r, t, curr, side, true);

				} else if(r >= right.size() || (l < left.size() && right[r].first > left[l].first)){
					calc(left, l, t, curr, side, false);

				} else {
					if(side) curr = max(curr, right[r].first);
					else curr = max(curr, left[l].first);
				}
			}
		}

		for(int i=0; i<m; ++i)
			cout << answer[i] << endl;
	}
	return 0;
}
