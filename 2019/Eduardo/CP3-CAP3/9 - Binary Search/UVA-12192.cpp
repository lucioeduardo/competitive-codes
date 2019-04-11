#include <bits/stdc++.h>
#define MAXN 505
using namespace std;

int heights[MAXN][MAXN], n, m;

int solve(int x, int y, int u){
	int esq = 1, dir = min(n-x-1,m-y-1);
	int res=0;

	while(esq <= dir){
		int meio = (esq+dir)/2;


		//printf("--->%d %d, %d %d\n",meio,heights[meio+x][meio+y],esq,dir);
		if(heights[meio+x][meio+y] <= u){
			res=meio;
			esq = meio+1;
		}
		else
			dir = meio-1;
	}

	return res+1; 
}

int main(){

	while(scanf("%d %d",&n,&m) && n != 0){
		for(int i=0; i<n;i++){
			for(int j=0; j<m; j++){
				scanf("%d",&heights[i][j]);
			}
		}

		int q;
		scanf("%d",&q);

		for(int i=0; i<q; i++){
			int sol=0;

			int l,u;

			scanf("%d %d",&l,&u);

			for(int j=0; j<n; j++){
				

				int* esq = lower_bound(heights[j],heights[j]+m,l);
				int idx = esq-heights[j];

				if(idx < m && heights[j][idx] <= u){

					sol = max(sol, solve(j,idx,u));
				}
								
			};

			printf("%d\n",sol);
			

		}

		printf("-\n");

	}

	return 0;
}
