#include <bits/stdc++.h>
using namespace std;

vector<int> prices;

int main(){
	int n;

	while(scanf("%d",&n) != EOF){
		prices.clear();

		for(int i=0; i<n; i++){
			int v;
			scanf("%d",&v); prices.push_back(v);
		}

		sort(prices.begin(), prices.end());

		int m;
		scanf("%d",&m);

		int res_i=-1, res_j=-1;

		vector<int>::iterator test = prices.begin()+2;

		for(int i=0; i<n; i++){
			int val = prices[i];

			int k = i;
			vector<int>::iterator it = lower_bound(prices.begin()+i,prices.end(),m-val);

			int idx = it - prices.begin();

			if(it != prices.end() && *it == m-val){
				if(res_i == -1 || (idx-i) < (res_j - res_i)){
					res_i = i;
					res_j = idx;
				}
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",prices[res_i],prices[res_j]);

	}



	return 0;
}
