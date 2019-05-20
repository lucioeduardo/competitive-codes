#include <bits/stdc++.h>
#define MAXN 80
using namespace std;

int torus[MAXN][MAXN];

int kadane(int vet[], int len){
	int res = vet[0];
	int sum = vet[0];

	for(int i=1;i<len;i++){
		if(sum < 0) sum = 0;
		sum += vet[i];
		res = max(res,sum);
	}

	return res;
}

int max_circular1d(int vet[], int len){
	int total = 0;
	int temp[len];

	for(int i=0;i<len;i++){
		total += vet[i];
		temp[i] = -vet[i];
	}

	return max(kadane(vet,len), total + kadane(temp,len));
}

int max_circular2d(int n){
	int temp[n];
	int res = -9999999;
	for(int i=0; i<n; i++){
		memset(temp,0,sizeof(temp));
		bool flag = true;
		for(int j=i; j!=i or flag; j=(j+1)%n){
			flag=false;
			for(int k=0; k<n; k++){
				temp[k] += torus[k][j];
			}

			res = max(res,max_circular1d(temp,n));

		}
	}

	return res;
}

int main(){
	int t;

	int v[5] = {1,2,-3,-4,5};

	scanf("%d",&t);

	while(t--){
		int n;

		scanf("%d",&n);

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&torus[i][j]);
			}
		}

		printf("%d\n", max_circular2d(n));
	}


	return 0;
}
