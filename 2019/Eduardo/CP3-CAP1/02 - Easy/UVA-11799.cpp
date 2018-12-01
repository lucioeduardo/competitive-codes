#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	
	scanf("%d",&n);
	
	for(int i=0; i<n; i++){
		int m;
		scanf("%d",&m);
		
		int res = -1;
		
		for(int j=0; j<m; j++){
			int x;
			scanf("%d",&x);
		
			res = max(res,x);
		}
		
		printf("Case %d: %d\n",i+1,res);
	}
	
    return 0;
}
