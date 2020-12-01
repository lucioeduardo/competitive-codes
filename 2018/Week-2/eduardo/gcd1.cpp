#include <cstdio>

int gcd(int a, int b){
	if(a % b == 0) return b;
	return gcd(b, a%b);
}

int main(){
	int t;
	
	scanf("%d", &t);
	
	for(int i=0; i<t; i++){
		int n, num;
		
		scanf("%d",&n);
		
		int gcd_all;
		
		for(int i=0; i<n; i++){
			scanf("%d", &num);
			if(i == 0) gcd_all = num;
			
			gcd_all = gcd(gcd_all, num); 
		}
		
		printf("%s\n", gcd_all == 1 ? "YES" : "NO");
	}
	
	return 0;
}
