#include <bits/stdc++.h>
#define MAXM 20
using namespace std;

int tracks[MAXM], N, m;
int max_sum=0, res_mask=0;

void solve(int idx, int sum, int mask){

	if(sum > max_sum){
		max_sum = sum;
		res_mask = mask;
	}
	if(idx >= m) return;

	solve(idx+1,sum,mask);

	if(tracks[idx] + sum <= N){
		solve(idx+1,sum+tracks[idx],mask + (1<<idx));
	}
}

int main(){

	while(scanf("%d %d",&N,&m) != EOF){
		max_sum=0;
		for(int i=0;i<m;i++){
			scanf("%d",&tracks[i]);
		}

		solve(0,0,0);

		for(int i=0;i<m; i++)
			if(res_mask & (1<<i)) printf("%d ",tracks[i]);
		printf("sum:%d\n", max_sum);
	}


	return 0;
}
