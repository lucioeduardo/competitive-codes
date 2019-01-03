#include <bits/stdc++.h>
#define MAXN 255
using namespace std;

vector<char> graph[MAXN];
bool visited[MAXN];

int dfs(int x){
	visited[x] = true;
	
	int res=1;
	
	for(size_t i=0; i<graph[x].size(); i++){
		int u = graph[x][i];
		if(!visited[u])
			res += dfs(u);
	}
	
	return res;
}

int main(){
	int n;
	
	scanf("%d",&n);
	
	while(n--){
		for(int i='A'; i<='Z'; i++) graph[i].clear();
		memset(visited, false, sizeof(visited));
		
		string str;
		while(cin>>str && str[0] != '*'){
			int a = str[1], b = str[3];
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		cin>>str;
		
		int n_t=0, n_a=0;
		
		for(size_t i=0; i<str.length(); i+=2){
			int v = str[i];
			
			if(!visited[v]){
				int k = dfs(v);
				if(k == 1) n_a++;
				else n_t++;
			}
		}
		
		printf("There are %d tree(s) and %d acorn(s).\n", n_t, n_a);
		
	}

	return 0;
}
