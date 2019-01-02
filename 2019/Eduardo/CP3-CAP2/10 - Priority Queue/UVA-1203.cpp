#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

priority_queue<pii, vector<pii>, greater<pii> > q;
map<int,int> val;

int main(){
	string s;
	while(cin>>s && s != "#"){
		int a,b;
		scanf("%d %d\n",&a,&b);
		
		q.push({b,a});
		val[a]=b;
	}
	
	int k;
	scanf("%d",&k);
	
	while(k--){
		pii t = q.top();
		q.pop();
		printf("%d\n",t.second);
		t.first += val[t.second];
		q.push(t);
	}

	return 0;
}
