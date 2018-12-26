#include <bits/stdc++.h>
#define MAXN 35500
using namespace std;

int weight[MAXN],potency[MAXN];

int main(){
	int n;
	
	while(scanf("%d", &n) != EOF){
		memset(potency, 0, sizeof(potency));
		for(int i=0; i< (1<<n); i++){
			scanf("%d",&weight[i]);
		}
		
		for(int i=0; i<(1<<n); i++){
			for(int j=0; j<n; j++){
				potency[i] += weight[i ^ (1<<j)];
			}
		}
		
		int res=0;
		
		for(int i=0; i<(1<<n); i++){
			for(int j=0; j<n; j++){
				res = max(res, potency[i] + potency[i ^ (1<<j)]);
			}
		}
		
		printf("%d\n",res);
	}
	
	return 0;
}
