#include <bits/stdc++.h>
#define MAXN 1000100
using namespace std;

int pai[MAXN];

int find(int x){
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}

void join(int a, int b){
	int fa=find(a), fb=find(b);
	
	pai[fa]=fb;
}

int main(){
	int t;
	
	scanf("%d  ",&t);
	
	while(t--){
		for(int i=0; i<MAXN; i++) pai[i]=i;
		
		int n,a,b;
		int s=0,u=0;
		char c;
		scanf("%d ", &n);
		
		while(scanf("%c",&c) != EOF && c != '\n'){
			scanf("%d%d",&a,&b);
			
			getchar();
			
			if(c == 'c'){
				join(a,b);
			}else{
				if(find(a) == find(b)) s++;
				else u++;
			}
		}
		
		printf("%d,%d\n",s,u);
		if(t > 0) printf("\n");
	}
	
	return 0;
}
