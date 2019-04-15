#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

int val[MAXN], n;

int find(int x){
	int res = val[0]+val[1];

	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int s = val[i]+val[j];
			if(abs(x-res) > abs(x-s))
				res = s;
		}
	}
	return res;
}

int main(){
	int c=0;
	while(scanf("%d",&n) && n){
		for(int i=0; i<n; i++){
			scanf("%d",&val[i]);
		}

		int m;
		scanf("%d",&m);

		printf("Case %d:\n",++c);
		for(int i=0; i<m; i++){
			int q;
			scanf("%d",&q);

			printf("Closest sum to %d is %d.\n",q,find(q));
		}
	}
	
	return 0;
}
