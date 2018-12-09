#include <bits/stdc++.h>
using namespace std;


int main(){
	int n;
	
	while(scanf("%d",&n) && n){
		bool is_a = true;
		int a=0,b=0;
		
		while(n > 0){
			int v = n & -n;
			
			if(is_a) a += v;
			else b += v;
			
			is_a = !is_a;
			n -= v;
		}
		
		printf("%d %d\n",a,b);
	}

    return 0;
}

