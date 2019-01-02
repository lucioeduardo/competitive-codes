#include <bits/stdc++.h>
using namespace std;

int main(){
	int s,p;
	
	while(scanf("%d %d",&s, &p) && s){
		int d = ceil(sqrt(p));
		if(d % 2 == 0) d++;
		
		d = (d-1)/2;
		int t = (d-1)*2 + 1;
		int k = p - t*t;
		
		int x = (s/2) +d;
		int y = (s/2) +d;
		int l = (d*2);	
		
		if(k <= l){
			x = (x-(k-1));
			y += 1;
		}else if(k <= 2*l){
			y+=1;
			x-=(l-1);
			k-=l;
			
			y-=(k);
			
		}else if(k <= 3*l){
			y -= (l-1);
			x -= (l-1);
			
			k%=l;
			if(k==0)k=l;
			
			x += (k);
		}else{
			y -= (l-1);
			x += 1;
			
			k%=l;
			if(k==0)k=l;
			
			y += (k);
		}
		
		printf("Line = %d, column = %d.\n", y, x);
	}
	
	return 0;
}

