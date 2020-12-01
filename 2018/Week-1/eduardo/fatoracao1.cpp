#include <cstdio>
#include <vector>
#include <bitset>
#define MAXN 10000010
using namespace std;

int factor[MAXN];

void sieve(){
	factor[0]=factor[1]=0;
	for(int i=2; i*i<MAXN; i++){
		if(!factor[i]){
			for(int j=i*i; j<MAXN; j+=i)
				if(!factor[j])factor[j]=i;
		}
	}
}
void prime_factors(int n){
	printf("1");
	
	while(factor[n] != 0){
		printf(" x %d",factor[n]);
		n /= factor[n];
		
	}
	
	if(n!=1) printf(" x %d",n);
	
	printf("\n");
}


int main(){
	vector<int>res;
	int n;
	
	sieve();
	
	while(scanf("%d",&n) != EOF){
		prime_factors(n);
	}
	return 0;
}

