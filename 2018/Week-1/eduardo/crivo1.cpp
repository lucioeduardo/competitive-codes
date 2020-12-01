#include <cstdio>
#define MAXN 100100

bool is_prime[MAXN];

void sieve(int n){
	for(int i=2; i*i <= n; i++){
		if(is_prime[i]){
			for(int j=2*i; j<=n; j+=i)
				is_prime[j]=false;
		}
	}
}

int main(){
	int l, u;
	
	scanf("%d %d",&l, &u);
	
	for(int i=2;i<=u;i++) is_prime[i]=true;
	
	sieve(u);
	
	for(int i=l; i<=u; i++){
		if(is_prime[i])
			printf("%d ",i);
	}
	
}
