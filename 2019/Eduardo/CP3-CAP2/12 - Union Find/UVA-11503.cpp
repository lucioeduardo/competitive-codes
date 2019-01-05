#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int p[MAXN], qtd[MAXN];
map<string,int> idx;

int find(int x){
	if(x == p[x]) return x;
	return p[x] = find(p[x]);
}

int join(int a, int b){
	int fa = find(a), fb=find(b);
		
	if(fa == fb) return qtd[fa];
	
	qtd[fb] += qtd[fa];
	p[fa] = fb;
	
	return qtd[fb];
}

int main(){
	int n,m;
	
	scanf("%d",&n);
	
	while(n--){
		idx.clear();
		scanf("%d",&m);
		
		int it=1;
		
		for(int i=0; i<MAXN; i++){
			p[i] = i;
			qtd[i] = 1;
		}
		
		for(int i=0;i<m;i++){
			string a,b;
			
			cin>>a>>b;
			
			if(!idx[a]) idx[a] = it++;
			if(!idx[b]) idx[b] = it++;
			
			printf("%d\n", join(idx[a],idx[b]));
		}
	}

	return 0;
}
