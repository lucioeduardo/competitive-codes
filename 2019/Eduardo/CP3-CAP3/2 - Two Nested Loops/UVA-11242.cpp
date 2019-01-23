#include <bits/stdc++.h>
#define MAXN 15
using namespace std;

double f[MAXN],r[MAXN];
vector<double> d;

int main(){
	int n,m;

	while(scanf("%d",&n) && n){
		d.clear();
		scanf("%d",&m);

		for(int i=0;i<n;i++){
			scanf("%lf",&f[i]);
		}

		for(int i=0; i<m; i++){
			scanf("%lf",&r[i]);
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				d.push_back(f[i]/r[j]);
			}
		}

		sort(d.begin(), d.end());

		double res = 0;

		for(size_t i=1; i<d.size(); i++){
			res = max(res,d[i]/d[i-1]);
		}

		printf("%.2lf\n",res);
	}
	
	return 0;
}
