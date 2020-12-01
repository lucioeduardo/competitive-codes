#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#define MAXN 20200

using namespace std;
typedef pair<int,int> pii;

vector<pii> dolls;
vector<int> stacks;

bool compare(pii a, pii b){
	if(a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

int main(){
	int t;
	
	scanf("%d", &t);
	
	for(int i=0; i<t; i++){
		int m;
		scanf("%d",&m);
		dolls.clear(); 
		
		for(int j=0; j<m; j++){
			int w,h;
			scanf("%d %d",&w,&h);
			
			dolls.push_back(pii(w,h));
		}
		sort(dolls.begin(), dolls.end(), compare);
		
		stacks.clear();
		
		for(size_t j=0; j<dolls.size(); j++){
			//printf("%d %d\n", dolls[j].first, dolls[j].second);
			
			int v = dolls[j].second;
			
			vector<int>::iterator it = upper_bound(stacks.begin(), stacks.end(), v);
			if(it == stacks.end())
				stacks.push_back(v);
			else
				*it=v;
		}
		
		printf("%d\n",(int) stacks.size());
	}
	
	
	return 0;
}
