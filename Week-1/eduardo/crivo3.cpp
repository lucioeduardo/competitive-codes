#include <cstdio>
#define MAXN 1010

bool is_prime[MAXN];
int primes[MAXN];

void sieve(int n){
	for(int i=2; i<=n; i++) is_prime[i] = true;
	
	for(int i=2; i*i<=n; i++){
		if(is_prime[i]){
			for(int j=2*i; j<=n; j+=i)
				is_prime[j]=false;
		}
	}
}


int main(){
	int n, k;
	
	scanf("%d %d", &n, &k);
	
	sieve(n);
	
	int res=0, qtd=0;
	
	for(int i=2; i<=n; i++){
		if(is_prime[i]){
			primes[qtd++]=i;
		}
	}
	
	for(int i=0; i<= qtd; i++){
		int sum = primes[i] + primes[i+1] + 1;
		if(sum > n) break;
		if(is_prime[ primes[i] + primes[i+1] + 1]) res++;
	}
	
	if(res >= k)
		printf("YES\n");
	else
		printf("NO\n");
		
	return 0;
}
