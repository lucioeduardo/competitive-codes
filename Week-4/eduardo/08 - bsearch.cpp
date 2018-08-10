#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> values;

int main(){
	int n,q,v;
	
	scanf("%d %d", &n, &q);
	
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		
		values.push_back(v);
	}
	
	for(int j=0;j<q;j++){
		scanf("%d", &v);
		vector<int>::iterator it = lower_bound(values.begin(), values.end(), v);
		
		if(v == *it)
			printf("%d\n",(int)(it - values.begin()));
		else
			printf("-1\n");
	}
	
	return 0;
}
