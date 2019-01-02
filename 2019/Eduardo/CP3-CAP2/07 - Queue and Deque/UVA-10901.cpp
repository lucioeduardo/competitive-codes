#include <bits/stdc++.h>
#define MAXM 10010
using namespace std;

queue< pair<int,int> > q_left, q_right;
int res[MAXM];
int pos=-1;

int main(){
	int c;
	
	scanf("%d ",&c);
	
	while(c--){
		pos = -1;
		int n,t,m;
		
		scanf("%d %d %d",&n,&t,&m);
	
		for(int i=0; i<m; i++){
			int t;
			string side;
			cin>>t>>side;
			
			if(side == "left") q_left.push({i,t});
			else q_right.push({i,t});
		}
		
		int time = 0;
		
		while(!q_right.empty() || !q_left.empty()){
			
			if(pos == -1){
				if(!q_left.empty() && q_left.front().second <= time){
					int qtd=0;
					while(!q_left.empty() && q_left.front().second <= time && qtd<n){
						res[q_left.front().first] = time + t;
						q_left.pop();
						qtd++;
					}
					time += t;
					pos=1;
				}else if(!q_right.empty() && q_right.front().second <= time){
					pos=1;
					time += t;
				}else{
					time = min(q_right.front().second, q_left.front().second);
					if(time == 0) time = max(q_right.front().second, q_left.front().second);
				}
			}else{
				if(!q_right.empty() && q_right.front().second <= time){
					int qtd=0;
					while(!q_right.empty() && q_right.front().second <= time && qtd<n){
						res[q_right.front().first] = time + t;
						q_right.pop();
						qtd++;
					}
					time += t;
					pos=-1;
				}else if(!q_left.empty() && q_left.front().second <= time){
					pos=-1;
					time += t;
				}else{
					time = min(q_right.front().second, q_left.front().second);
					if(time == 0) time = max(q_right.front().second, q_left.front().second);
				}
			}
		}
		
		for(int i=0; i<m; i++)
			printf("%d\n",res[i]);
		if(c > 0)
			printf("\n");
	}
	
	return 0;
}

