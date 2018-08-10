#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXN 30
using namespace std;

int ini[MAXN], val[MAXN];

int main(){
	int n;
	
	while(scanf("%d",&n) != EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&ini[i]);
		}
		for(int i=0;i<n;i++){
			int v;
			scanf("%d",&v);
			val[v]=i;
		}
		
		int qtd=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n-1;j++){
				if(val[ini[j]] > val[ini[j+1]]){
					swap(ini[j],ini[j+1]);
					qtd++;
				}
			}
		}
		
		printf("%d\n",qtd);
	}
	
	return 0;
}
