#include <cstdio>
#define MAXN 100100

int num_factors[MAXN];

void sieve(int n){
	num_factors[0] = num_factors[1] = -1;
	
	for(int i=2; i <= 10000; i++){
		if(!num_factors[i]){
			for(int j=2*i; j<=n; j+=i)
				num_factors[j]++;
		}
	}
}

int main(){
	int t, n;
	
	scanf("%d",&t);
	
	sieve(MAXN-1);
	
	for(int i=0; i<t; i++){
		scanf("%d", &n);
		
		int count=0,j;
		
		for(j=2; j<=MAXN; j++){
			
							
			if(num_factors[j] >= 3) count++;
			if(count == n) break;
		}
		
		printf("%d\n",j);
	}
	
	
	
	
	
}
