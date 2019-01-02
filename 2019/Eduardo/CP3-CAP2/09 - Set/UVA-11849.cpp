#include <bits/stdc++.h>
using namespace std;

set<int> cds;

int main(){
	int n,m,x;
	
	while(scanf("%d %d",&n, &m) && (n || m) ){
		cds.clear();
	
		for(int i=0; i<n+m; i++){
			scanf("%d",&x);
			cds.insert(x);
		}
		
		printf("%d\n",(n+m-(int)cds.size()));
	}
	
	
	return 0;
}
