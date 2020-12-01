#include <cstdio>
#define T 3
#define M 1000000009
#define ll long long

ll f[3] = {0,1,2};

void mult_matrix(ll a[T][T], ll b[T][T]){
	ll res[T][T];
	
	for(int i=0; i<T; i++){
		for(int j=0; j<T; j++){
			ll val = 0;
			for(int k=0; k<T; k++)
				val += (a[i][k] * b[k][j]) %M;
			res[i][j] = (val % M);
		}
	}
	
	for(int i=0; i<T; i++)
		for(int j=0; j<T; j++)
			a[i][j] = res[i][j];
}	

void pow_matrix(ll a[T][T], ll n){
	ll res[T][T] = {{1,0,0},{0,1,0},{0,0,1}};
	
	while(n > 0){
		if(n % 2)
			mult_matrix(res,a);
		mult_matrix(a,a);
		n/=2;
	}
	
	for(int i=0; i<T; i++)
		for(int j=0; j<T; j++)
			a[i][j] = res[i][j];
}


int main(){
	ll n;
	
	while(scanf("%lld",&n) && n!=0){
		ll matriz[T][T] = {{1,1,1},{1,0,0},{0,1,0}};
		
		pow_matrix(matriz,n-3);
		
		ll res = 0;
		
		for(int i=0; i<T; i++)
			res += (matriz[0][i] * f[T-i-1]) % M;
		
		if(n <= 3) res = f[n-1];
		
		printf("%lld\n", res%M);
	}
	
	
	return 0;
}
