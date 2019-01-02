#include <bits/stdc++.h>
using namespace std;


stack<int> pilha;

void clear_stack(){
	while(!pilha.empty())
		pilha.pop();
}

int main(){
	int n;
	
	while(scanf("%d", &n) && n){
		int x;
		
		
		while(scanf("%d",&x) && x){
			int t=1;
			bool res=true;
						
			for(int i=1; i<n; i++){
				while((pilha.empty() or pilha.top() != x) and t <= n){
					pilha.push(t++);
				}
				
				
				if(pilha.top() != x)
					res=false;
				pilha.pop();
				
				scanf("%d",&x);
			}
			
			if(res) printf("Yes\n");
			else printf("No\n");
			clear_stack();		
		}
		
		
		printf("\n");
	}

    return 0;
}


