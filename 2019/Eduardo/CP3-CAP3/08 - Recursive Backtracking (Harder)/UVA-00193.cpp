#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

int n,k;
vector<int> graph[MAXN];

int max_black=0, visited[MAXN], res[MAXN], atual[MAXN], it=0;
int color[MAXN];

void solve(int v){
	if(v == n+1)
		return;
	
	visited[v] = true;
	solve(v+1);

	bool black = true;

	for(int i=0; i<graph[v].size(); i++){
		int u = graph[v][i];
		if(color[u] == 1) black = false;
	}

	if(black){
		atual[it++] = v;
		color[v] = 1;

		if(it > max_black){
			max_black = it;
			for(int i=0; i<max_black; i++)
				res[i] = atual[i];
		}

		solve(v+1);

		color[v]=0;
		it--;
	}

	visited[v]=false;	
}
	


int main(){
	int m;

	scanf("%d", &m);

	while(m--){
		it=max_black=0;
		
		scanf("%d %d",&n,&k);

		for(int i=1; i<=n; i++)
			graph[i].clear();
	
		while(k--){
			int a,b;
			scanf("%d %d",&a,&b);

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		solve(1);

		printf("%d\n",max_black);

		printf("%d", res[0]);
		for(int i=1; i<max_black; i++){
			printf(" %d",res[i]);
		}
		printf("\n");
	
	}

	return 0;
}
