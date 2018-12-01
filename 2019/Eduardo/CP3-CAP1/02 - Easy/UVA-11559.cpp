#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, b, h, w;
	
	while(scanf("%d %d %d %d",&n,&b,&h,&w) != EOF){
		int p;
		
		
		int res = -1;
		
		for(int j=0; j<h; j++){
			scanf("%d",&p);
		
			bool flag = false;

			for(int i=0; i<w; i++){
				int a;
				scanf("%d",&a);
				
				if(a > n) flag = true;
			}
			int price = p*n;
			
			if(!flag) continue;
			if(price > b) continue;
			if(price < res || res == -1)
				res = price;
		}
		
		if(res == -1) printf("stay home\n");
		else printf("%d\n",res);
	}
    return 0;
}
