// URI 2063 - Caçando Diglets
#include <cstdio>
#define MAXN 110
int tunel[MAXN];

int solve(int n, int v){
	if(tunel[n] == v)
		return 1;
	return 1 + solve(tunel[n],v);
}

long long gcd(int a, int b){
	if(a % b == 0)
		return b;
	return gcd(b, a%b);
}

int main(){
	int n;
	long long mmc=1;
	
	scanf("%d",&n);
	
	for(int i=1; i<=n; i++){
		scanf("%d", &tunel[i]);
	}
	
	for(int i=1; i<=n; i++){
		int v = solve(i,i);
		mmc = (mmc*v)/gcd(mmc,v);
	}
	
	printf("%lld\n",mmc);
	
	return 0;
}
