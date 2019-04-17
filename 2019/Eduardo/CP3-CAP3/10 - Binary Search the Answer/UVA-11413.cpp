#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

int vessels[MAXN],n,m;
int containers[MAXN];

bool test(int capacity){
	int it=0, sum=0;
	for(int i=0; i<n; i++){
		if(sum + vessels[i] > capacity){
			it++;
			sum=0;
		}

		if(vessels[i] > capacity) return false;

		sum += vessels[i];
	}

	return (it < m);
}

int main(){

	while(scanf("%d %d",&n,&m) != EOF){
		memset(containers,0,sizeof(containers));

		int sum=0;

		for(int i=0;i<n;i++){
			scanf("%d", &vessels[i]);
			sum += vessels[i];
		}

		int res=0;

		int esq=1, dir=sum, mid=0;

		while(esq <= dir){
			mid = (esq + dir)/2;

			if(test(mid)){
				res = mid;
				dir = mid-1;
			}else{
				esq = mid+1;
			}
			
		}

		printf("%d\n",res);
	}
	return 0;
}
