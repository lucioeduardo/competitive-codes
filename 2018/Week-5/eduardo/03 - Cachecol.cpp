#include <cstdio>
#define ll long long
#define M 1000000007
#define MAXN 2

ll matriz[MAXN][MAXN]= {{3,2},{2,2}};

void mult_matrix(ll a[MAXN][MAXN], ll b[MAXN][MAXN]){
	ll res[MAXN][MAXN];
	
	for(int i=0; i<MAXN; i++){
		for(int j=0; j<MAXN; j++){
			ll val = 0;
			
			for(int k=0; k<MAXN; k++)
				val += (a[i][k]*b[k][j]) % M;
			
			res[i][j] = (val % M);
		}
	}
	
	for(int i=0; i<MAXN; i++)
		for(int j=0; j<MAXN; j++)
			a[i][j] = res[i][j];
}

void pow_matrix(ll a[MAXN][MAXN], ll n){
	ll res[MAXN][MAXN] = {{1,0},{0,1}};
	while(n > 0){
		if(n % 2)
			mult_matrix(res,a);
		mult_matrix(a,a);
		n/=2;
	}
	
	for(int i=0; i<MAXN; i++)
		for(int j=0; j<MAXN; j++)
			a[i][j] = res[i][j];
}

int main(){
	long long int n;
	
	scanf("%lld",&n);
	
	pow_matrix(matriz,n-1);
	
	ll sum = 0;
	for(int i=0; i<MAXN; i++)
		for(int j=0; j<MAXN; j++)
			sum = (sum + matriz[i][j]) % M;
	
	printf("%lld",(sum*6)%M);
	
	return 0;
}
