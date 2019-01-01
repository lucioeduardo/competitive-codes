#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int n;
	priority_queue<int> pQ;

	while(cin >> n && n)
	{
		ll answer = 0;

		while(n--) {
			int x; cin >> x;
			pQ.push(-x);
		}

		while(pQ.size() > 1)
		{
			ll curr;
			curr = -pQ.top(); pQ.pop();
			curr -= pQ.top(); pQ.pop();
			answer += curr;
			pQ.push(-curr);
		}
		pQ.pop();

		cout << answer << endl;
	}
	return 0;
}
