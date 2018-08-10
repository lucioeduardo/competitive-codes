#include <cstdio>
#include <queue>
#include <algorithm>
#define MAXN 33000
using namespace std;

int power[MAXN], ini[MAXN], lose[MAXN];
queue<int> winners, beat[MAXN];

int q_pop(){
	int a = winners.front();
	winners.pop();
	return a;
}

int main(){
	int t,a,x;
	
	scanf("%d",&t);
	
	for(int i=0; i<t; i++){
		int n,k;
				
		scanf("%d %d",&n,&k);
		
		for(int j=1; j<=(1<<n); j++){
			scanf("%d", &ini[j]);
			power[j]=ini[j];
			winners.push(j);
		}
		
		while(winners.size() > 1){
			a = q_pop();
			x = q_pop();
			
			if(power[x] > power[a])
				swap(a,x);
			
			power[a] -= power[x];
			power[a] = min(power[a]+k, ini[a]);
			winners.push(a);
			beat[a].push(x);
			
			while(!beat[x].empty())
				beat[x].pop();
			
		}
		
		int winner = winners.front();
		winners.pop();
		printf("%d\n",winner);
		
		while(beat[winner].size() > 1){
			printf("%d ",beat[winner].front());
			beat[winner].pop();
		}
		printf("%d\n",beat[winner].front());
		beat[winner].pop();
	}
	

	
	return 0;
}	
