#include <bits/stdc++.h>
using namespace std;

queue< int > q[2];

int main(){
	int c;
	
	scanf("%d ",&c);
	
	while(c--){
		int l,m;
		
		scanf("%d %d",&l,&m);
		
		for(int i=0; i<m; i++){
			int v;
			string s;
			cin>>v>>s;
			
			if(s == "left") q[0].push(v);
			else q[1].push(v);
		}
		
		int res = 0, pos=0;
		while(!q[0].empty() || !q[1].empty()){
			res++;
			int tam=0;
			while(!q[pos].empty() && tam + q[pos].front() < l*100){
				tam += q[pos].front();
				q[pos].pop();
				
				//printf("%d %d\n",tam, q[pos].front());
			}
			pos = !pos; 
		}
		
		printf("%d\n",res);
	}
	
	return 0;
}


