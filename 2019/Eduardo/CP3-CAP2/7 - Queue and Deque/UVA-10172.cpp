#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

queue<int> filas[MAXN];
stack<int> carry;

int main(){
	int t;
	
	scanf("%d",&t);
	
	while(t--){
		int n,s,q;
		int qtd=0;
		
		scanf("%d %d %d",&n,&s,&q);
		
		for(int i=1; i<=n; i++){
			int k,v;
			scanf("%d",&k);
			qtd += k;
			for(int j=0; j<k; j++){
				scanf("%d",&v);
				filas[i].push(v);
			}
		}
		
		int station = 1, time=-2;
		
		while(qtd){
			time += 2;
			
			while(!carry.empty()){
				if(carry.top() == station){
					carry.pop();
					time++;
					qtd--;
				}else{
					if((int)filas[station].size() == q) break;
					filas[station].push(carry.top());
					carry.pop();
					time++;
				}
			}
			
			while((int)carry.size() < s && !filas[station].empty()){

				carry.push(filas[station].front());
				filas[station].pop();
				time++;
			}
			
			station++;
			if(station == n+1) station = 1;
		}
		
		printf("%d\n",time);
		
	}
	
	return 0;
}
