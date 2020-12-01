// SPOJ - https://br.spoj.com/problems/SENHA/
// TIME - 0.00
#include <cstdio>
#include <set>
using namespace std;

set<int> senha[6];
int digitos[10];

int main(){
	int n,k=1;
	
	while(scanf("%d ",&n) && n!=0){
		for(int i=0; i<n; i++){
			for(int j=0; j<10; j++)
				scanf("%d ",&digitos[j]);
			
			for(int j=0; j<6; j++){
				char c;
				scanf("%c ", &c);
				
				int x = (c - 'A');
				
				if(i == 0){
					senha[j].insert(digitos[2*x]);
					senha[j].insert(digitos[2*x+1]);
				}else{
					int v1 = digitos[2*x];
					int v2 = digitos[2*x+1];
					for(set<int>::iterator it = senha[j].begin(); it != senha[j].end(); it++){
						if(*it != v1 && *it != v2)
							senha[j].erase(it);
					}
				}
			}
			
		}
		printf("Teste %d\n", k++);
			
		for(int j=0; j<6; j++){
			for(set<int>::iterator it = senha[j].begin(); it != senha[j].end(); it++){
				if(j == 0)printf("%d",*it);
				else printf(" %d",*it);
			}
		}
		printf("\n");
	}
	
	
	
}
