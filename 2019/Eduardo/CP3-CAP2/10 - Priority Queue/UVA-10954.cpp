#include <bits/stdc++.h>
#define ll long long
using namespace std;

priority_queue<ll, vector<ll>, greater<ll> > q;

int main(){
	int n;
	
	while(scanf("%d",&n) && n){
		int x;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			q.push(x);
		}
		
		ll res=0;
		
		while(true){
			ll v1 = q.top(); q.pop();
			ll v2 = q.top(); q.pop();
			
			res += v1+v2;
			
			if(q.empty()) break;
			q.push(v1+v2);
		}
		
		printf("%lld\n",res);
	}

	return 0;
}
