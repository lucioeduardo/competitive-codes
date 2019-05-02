#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;

int values[MAXN];

int main(){

	int n;

	while(scanf("%d",&n) && n){
		for(int i=0; i<n; i++){
			scanf("%d",&values[i]);
		}

		int res = -9999999;

		int sum=0;
		for(int i=0;i<n;i++){
			sum += values[i];

			res = max(res,sum);
			if(sum < 0)
				sum=0;
		}

		if(res > 0) printf("The maximum winning streak is %d.\n",res);
		else printf("Losing streak.\n");
	}
	

	return 0;
}
