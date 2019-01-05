#include <bits/stdc++.h>
#define MAXN 300
using namespace std;

vector<int> graph[MAXN];
bool awake[MAXN], aux[MAXN];

int main(){
	int n;
	
	while(scanf("%d ", &n) != EOF){
		int m;
		
		for(int i='A'; i<='Z'; i++){
			graph[i].clear();
			awake[i] = false;
		}
		
		scanf("%d ",&m);
		
		string s;
		cin>>s;	
		awake[s[0]] = awake[s[1]] = awake[s[2]] = true;
		
		
		for(int i=0; i<m; i++){
			cin>>s;
			graph[s[0]].push_back(s[1]);
			graph[s[1]].push_back(s[0]);
		}
		
		int years=0;
		bool flag = true;
		
		while(n>3 && flag){
			flag = false;
			
			for(int i='A'; i<='Z'; i++){
				int qtd = 0;
				aux[i] = awake[i];
				if(awake[i]) continue;
				
				for(int j=0; j<graph[i].size(); j++){
					int v = graph[i][j];
					//printf("%c %c %d %d\n",i,v,awake[v],n);
					if(awake[v]) qtd++;
				}
				
				if(qtd >= 3){
					aux[i]=true;
					flag = true;
					n--;
				}
			}
			
			for(int i='A'; i<='Z'; i++)
				awake[i] = aux[i];
			
			years++;
		}
		
		if(n > 3) printf("THIS BRAIN NEVER WAKES UP\n");
		else printf("WAKE UP IN, %d, YEARS\n", years);
	}
	

	return 0;
}
