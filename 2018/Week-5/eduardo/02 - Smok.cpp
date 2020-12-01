#include <cstdio>
#define MAXN 110
#define M 1000000007
#define ll long long

ll graph[MAXN][MAXN],n,m,k,sol[MAXN][MAXN];

void mult_matrix(ll a[MAXN][MAXN],ll b[MAXN][MAXN]){
	ll res[MAXN][MAXN];
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			ll val=0;
			
			for(int k=1;k<=n;k++){
				val += ((a[i][k] * b[k][j]) % M);
			}
			
			res[i][j]=(val % M);
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			a[i][j] = res[i][j];
		}
	}
}

void pow_matrix(ll a[MAXN][MAXN], int p){
	ll res[MAXN][MAXN];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			res[i][j] = (i==j ? 1 : 0);
	
	while(p > 0){
		if(p % 2)
			mult_matrix(res,a);
		mult_matrix(a,a);
		p/=2;
	}
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			a[i][j] = (res[i][j] % M);
}

int main(){
	
	scanf("%lld %lld %lld",&n,&m,&k);
	
	for(int i=0; i<m; i++){
		int a,b;
		
		scanf("%d %d",&a,&b);
		graph[a][b]++;
		graph[b][a]++;
	}
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			sol[i][j] = graph[i][j];
			
	pow_matrix(sol,k-1);
	
	/*
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			printf("%lld ",sol[i][j]);
		}
		printf("\n");
	}*/
	

	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ll val = 0;
			
			for(int k=1; k<=n; k++)
				val += (sol[j][k] * graph[i][k]) % M;
			
			
			printf("%lld",val == 0? -1 : (val % M));
			if(j < n) printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
