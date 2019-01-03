#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;
typedef pair<int,int> pii;

vector<pii> graph[MAXN];
int ind[MAXN];

int main(){
	int n,m;
	
	while(scanf("%d %d", &m, &n) != EOF){
		for(int i=1;i<=n;i++) graph[i].clear();
			
		for(int i=1; i<=m; i++){
			int k;
			scanf("%d",&k);
			
			for(int j=0; j<k; j++){
				scanf("%d",&ind[j]);
			}
			
			for(int j=0; j<k; j++){
				int v;
				scanf("%d",&v);
				graph[ind[j]].push_back({i,v});
			}
		}
		
		printf("%d %d\n",n,m);
		for(int i=1; i<=n; i++){
			int len = graph[i].size();
			
			if(len == 0){
				printf("0\n\n");
				continue;
			}
			
			printf("%d %d",len,graph[i][0].first);
			for(int j=1; j<len; j++){
				printf(" %d", graph[i][j].first);
			}
			
			printf("\n%d", graph[i][0].second);
			for(int j=1; j<len; j++){
				printf(" %d", graph[i][j].second);
			}
			printf("\n");
		}
	}
	
	return 0;
}
