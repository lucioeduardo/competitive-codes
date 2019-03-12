#include <bits/stdc++.h>
#define MAXN 20
using namespace std;

int t,n,values[MAXN],qtd[MAXN],it;
int result[MAXN], idx_res=0;


bool solve(int idx, int soma){
	if(soma == t){
		printf("%d",result[0]);
		for(int i=1; i<idx_res; i++){
			printf("+%d",result[i]);
		}
		printf("\n");
		return true;
	}
	if(soma > t || idx >= it)
		return false;
	

	bool com=false,sem;

	if(qtd[idx] > 0){
		result[idx_res++] = values[idx];
		qtd[idx]--;
	
		com = solve(idx, soma+values[idx]);
		
		qtd[idx]++;
		idx_res--;
	}

	sem = solve(idx+1,soma);

	return com || sem;
}

int main(){

	while(scanf("%d %d",&t, &n) && n){
		int v;
		it=0;

		for(int i=0; i<n; i++){
			scanf("%d",&v);

			if(i == 0 || v != values[it-1]){
				values[it] = v;
				qtd[it++]=1;
			}else{
				qtd[it-1]++;
			}
		}

		printf("Sums of %d:\n",t);
		if(!solve(0,0))
			printf("NONE\n");
	}

	return 0;
}
