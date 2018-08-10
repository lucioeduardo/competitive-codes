// SPOJ - https://br.spoj.com/problems/TENTA/
#include <cstdio>
#include <algorithm>
#include <vector>
#define all(c) c.begin(), c.end()
using namespace std;

vector<int> values;

int main(){
	int n,v;
	bool flag=true;
	
	while(scanf("%d",&n) && n != 0){
		if(!flag){
			printf("\n");
		}
		flag=false;
		
		values.clear();
		
		for(int i=0; i<n; i++){
			scanf("%d",&v);
			values.push_back(v);
		}
		
		sort(all(values));
		
		do{
			printf("%d",values[0]);
			for(size_t i=1; i<values.size(); i++){
				printf(" %d",values[i]);
			}
			printf("\n");
		}while(next_permutation(all(values)));
		
		
	}
	

	
	return 0;	
}
