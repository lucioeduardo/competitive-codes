#include <bits/stdc++.h>
#define MAXN 100100
using namespace std;

int next_r[MAXN], prev_l[MAXN];

int main(){
	int s,b;
	
	while(scanf("%d %d",&s, &b) && s != 0){
		for(int i=1; i<=s; i++){
			next_r[i]=i+1;
			prev_l[i]=i-1;
		}
		
		next_r[s] = -1;
		prev_l[1] = -1;
		
		for(int i=0; i<b; i++){
			int l,r;
			scanf("%d %d",&l,&r);
						
			next_r[l-1] = next_r[prev_l[l]] = next_r[r];
			prev_l[r+1] = prev_l[next_r[r]] = prev_l[l];
			
			if(prev_l[l] == -1) printf("* ");
			else printf("%d ", prev_l[l]);
		
			if(next_r[r] == -1) printf("*\n");
			else printf("%d\n", next_r[r]);
		}
		printf("-\n");
	}
	
	
	return 0;
}


