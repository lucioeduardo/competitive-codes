#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

int val[MAXN];

int main(){
	int t;

	scanf("%d",&t);

	while(t--){
		int n;
		scanf("%d",&n);

		for(int i=0; i<n; i++){
			scanf("%d",&val[i]);
		}

		int res=0;

		for(int i=1; i<n; i++){
			for(int j=i-1; j>=0; j--){
				if(val[i] >= val[j])
					res++;
			}
		}

		printf("%d\n",res);
	}

	return 0;
}
