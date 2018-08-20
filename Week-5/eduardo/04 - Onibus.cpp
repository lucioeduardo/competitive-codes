#include <cstdio>
#define ll long long
#define T 2
#define M 1000000
using namespace std;

void mult_matrix(ll a[T][T], ll b[T][T]){
	ll res[T][T];
	
	for(int i=0; i<T; i++){
		for(int j=0; j<T; j++){
			ll val = 0;
			for(int k=0; k<T; k++)
				val += (a[i][k] * b[k][j]) % M;
			res[i][j] = (val % M);
		}
	}
	
	for(int i=0; i<T; i++)
		for(int j=0; j<T; j++)
			a[i][j] = res[i][j];
}

void pow_matrix(ll a[T][T], ll n){
	ll res[T][T] = {{1,0},{0,1}};
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
	ll n,k,l;
	
	while(scanf("%lld %lld %lld",&n,&k,&l) != EOF){
		n /= 5;
		
		k %= M;
		l %= M;
		
		ll matriz[T][T] = { {k,l},{1,0} };
		
		pow_matrix(matriz,n-2);
		
		/*for(int i=0; i<T; i++){
			for(int j=0; j<T; j++){
				printf("%lld ", matriz[i][j]);
			}
			printf("\n");
		}*/
		
		
		ll f2 = (k*k + l)%M;
		ll res = ((matriz[0][1]*k %M) + (matriz[0][0]*f2 % M)) % M;
		
		if(n == 1) res = k;
		
		printf("%06lld\n", res);
	}
	
	return 0;
}
