#include <bits/stdc++.h>
#define MAXN 20
using namespace std;

int qtd[MAXN], areas[MAXN], area_mask[MAXN];

int main(){
	int n,m,k,test_case=1;

	while(scanf("%d %d",&n,&k) && n != 0){
		for(int i=0; i<n; i++)
			scanf("%d",&qtd[i]);
		
		scanf("%d",&m);

		for(int i=0;i<m;i++){
			int t,n,area=0;
			scanf("%d",&t);
			for(int i=0; i<t; i++){
				int v;
				scanf("%d", &v); v--;
				area += (1<<v);
			}
			area_mask[i]=area;
			scanf("%d",&areas[i]);
		}

		int max=0, mask=0;

		for(int j=0; j<(1<<n); j++){
			if(__builtin_popcount(j) != k) continue;

			int res=0;

			for(int i=0; i<n; i++){
				if(j & (1<<i)){
					res += qtd[i];
				}
			}

			for(int i=0; i<m; i++){
				int val = __builtin_popcount(j & area_mask[i]);

				if(val > 1)
					res -= (val-1)*areas[i];
			}

			if(res > max){
				max = res;
				mask = j;
			}

		}

		int result[k],it=0;

		for(int i=0; i<n; i++){
			if(mask & (1<<i)){
				result[it++]=i+1;
			}
		}

		printf("Case Number  %d\n",test_case++);
		printf("Number of Customers: %d\n",max);

		printf("Locations recommended: %d",result[0]);
		for(int i=1; i<k; i++)
			printf(" %d",result[i]);
		printf("\n\n");

	}

	return 0;
}
