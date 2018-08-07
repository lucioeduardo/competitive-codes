#include <cstdio>
#include <vector>
#include <algorithm>
#define all(c) c.begin(), c.end() 
using namespace std;

vector<int> values;

int main(){
	int n,v;
	
	scanf("%d",&n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &v);
		values.push_back(v);
	}
	
	sort(all(values));
	
	printf("%d\n",values[n/2]);
	
	return 0;
}
