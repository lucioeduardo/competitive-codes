// URI 2514 - Alinhamento Lunar
#include <cstdio>

long long gcd(long long a, long long b){
	if(a % b == 0) return b;
	return gcd(b, a%b);
}

int main(){
	int n;
	
	while(scanf("%d",&n) != EOF){
		long long v,mmc = 1;
		
		for(int i=0; i<3; i++){
			scanf("%lld",&v);
			
			mmc = mmc*v/gcd(mmc,v);
		}
		
		printf("%lld\n",mmc-n);
	}
	
	
	
	
	return 0;
}
