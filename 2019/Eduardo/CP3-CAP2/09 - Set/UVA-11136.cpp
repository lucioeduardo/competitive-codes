#include <bits/stdc++.h>
using namespace std;

multiset<int> box;

int main(){
	int n;
	
	while(scanf("%d",&n) && n){
		box.clear();
		
		long long int res = 0;
		
		for(int i=0; i<n; i++){
			int k,x;
			scanf("%d",&k);
			
			for(int j=0; j<k; j++){
				scanf("%d",&x);
				box.insert(x);
			}
						
			res += (*box.rbegin()) - (*box.begin());
			box.erase(box.begin());
			box.erase(prev(box.end()));
		}
		
		printf("%lld\n",res);
	}
	
	return 0;
}
