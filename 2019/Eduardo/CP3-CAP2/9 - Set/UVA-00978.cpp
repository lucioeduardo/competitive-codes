#include <bits/stdc++.h>
using namespace std;

multiset<int, greater<int> > green, blue;

int main(){
	int t;
	
	scanf("%d",&t);
	
	while(t--){
		int n,g,b,x;
		
		scanf("%d %d %d",&n,&g,&b);
			
		green.clear(); blue.clear();
		
		for(int i=0; i<g; i++){
			scanf("%d",&x);
			green.insert(x);
		}
		
		for(int i=0; i<b; i++){
			scanf("%d",&x);
			blue.insert(x);
		}
		vector<int> g_back, b_back;

		while( !(green.empty() || blue.empty()) ){
			int qtd = min(n, min((int)green.size(), (int)blue.size()));
			
			multiset<int, greater<int> >::iterator ig = green.begin(), ib = blue.begin(), aux;
			g_back.clear(); b_back.clear();
				
			while(qtd--){
				//printf("%d %d\n",*ig, *ib);
				if(*ig > *ib)
					g_back.push_back(*ig - *ib);
				else if(*ib > *ig)
					b_back.push_back(*ib - *ig);
				
				aux = ig++;
				green.erase(aux);
					
				aux = ib++;
				blue.erase(aux);
			}
			
			for(size_t i=0; i<g_back.size(); i++) green.insert(g_back[i]);
			for(size_t i=0; i<b_back.size(); i++) blue.insert(b_back[i]);
		}
		
		if(green.size() == blue.size())
			printf("green and blue died\n");
		else if(green.size()){
			printf("green wins\n");
			for(set<int>::iterator it = green.begin(); it!=green.end(); it++)
				printf("%d\n",*it);
		}else{
			printf("blue wins\n");
			for(set<int>::iterator it = blue.begin(); it!=blue.end(); it++)
				printf("%d\n",*it);
		}
		
		if(t > 0) printf("\n");
	}
	
	
	return 0;
}
