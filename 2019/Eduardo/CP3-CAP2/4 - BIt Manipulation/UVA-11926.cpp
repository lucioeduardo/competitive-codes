#include <bits/stdc++.h>
#define MAXN 1000100
using namespace std;

bitset<MAXN> used;

int main(){
	int n,m;
	
	while(scanf("%d %d",&n,&m) && (n || m)){
		used.reset();
		bool res = true;
		
		for(int i=0; i<n; i++){
			int a,b;
			scanf("%d %d",&a, &b);
			
			for(int j=a; j<b; j++){
				if(used[j])
					res = false;
				used.set(j,1);
			}
		}
		
		for(int i=0; i<m; i++){
			int a,b,t;
			scanf("%d %d %d",&a, &b, &t);
			int k=0;
			
			do{
				for(int j=a; j<b && j+k < 1000001; j++){
					if(used[j+k])
						res = false;
					used.set(j+k,1);
				}
				k+=t;
			}while(k < MAXN);
		}
		
		if(res) printf("NO CONFLICT\n");
		else printf("CONFLICT\n");
	}


    return 0;
}

