#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

vector<int> graph[MAXN];

int main(){
	int n,m,x;
	
	while(scanf("%d %d",&n,&m) != EOF){
		for(int i=0;i<MAXN;i++)graph[i].clear();
				
		for(int i=1; i<=n; i++){
			scanf("%d",&x);
			
			graph[x].push_back(i);
		}
		
		for(int i=0; i<m; i++){
			int k,v;
			scanf("%d %d",&k,&v);
					
			if(k>(int)graph[v].size()) printf("0\n");
			else printf("%d\n",graph[v][k-1]);
		}
	}
	return 0;
}
