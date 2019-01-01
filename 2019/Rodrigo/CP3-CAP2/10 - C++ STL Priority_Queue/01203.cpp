#include <bits/stdc++.h>
#define F first
#define S second
#define ppii pair<int, pair<int, int> >
using namespace std;

int main()
{
	int id, sec;
	string op;

	priority_queue<ppii, vector<ppii>, greater<ppii> > pQ;
	
	while(cin >> op && op != "#"){
		cin >> id >> sec;
		pQ.push({sec, {id, sec}});
	}

	int n; cin >> n;

	while(n--) {
		auto p = pQ.top();
		cout << p.S.F << endl;

		pQ.push({p.F + p.S.S, {p.S.F, p.S.S}});
		pQ.pop();
	}

	return 0;
}
