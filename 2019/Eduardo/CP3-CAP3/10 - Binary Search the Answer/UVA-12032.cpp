#include <bits/stdc++.h>
#define MAXR 10000000
#define MAXN 100000
using namespace std;

int rungs[MAXN],n;

bool test(int k){
	int pos=0;
	for(int i=0;i<n;i++){
		if(rungs[i] - pos > k)
			return false;
		
		if(rungs[i] - pos == k)
			k--;
		
		pos = rungs[i];	
	}

	return true;
}

int main(){
	int t;

	scanf("%d",&t);

	for(int c=0;c<t;c++){
		scanf("%d", &n);

		for(int i=0; i<n; i++)
			scanf("%d",&rungs[i]);

		int esq=1, dir=MAXR, mid;
		int res=-1;

		while(esq <= dir){
			mid = (esq+dir)/2;

			if(test(mid)){
				res = mid;
				dir = mid-1;
			}else{
				esq = mid+1;
			}
				
		}

		printf("Case %d: %d\n",c+1,res);
	}


	return 0;
}
