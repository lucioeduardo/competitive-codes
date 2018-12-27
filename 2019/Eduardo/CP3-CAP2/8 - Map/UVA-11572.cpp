#include <bits/stdc++.h>
using namespace std;

map<int,int> val;

int main(){
	int t;
	
	scanf("%d",&t);
	
	
	while(t--){
		int n;
		scanf("%d",&n);
		val.clear();
	
		int qtd=0,res=0,esq=1;
	
		for(int i=1; i<=n; i++){
			int x;
			scanf("%d",&x);
			
			
			if(val[x] < esq) qtd++;
			else{
				qtd = i-val[x];
				esq = val[x]+1;
			}
			
			res = max(res,qtd);
			
			val[x]=i;
		}
		
		printf("%d\n",(int)res);
	}

	return 0;
}
