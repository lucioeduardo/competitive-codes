#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

int mat[MAXN][MAXN], n;


int kadane(int vetor[], int length){
	int res = vetor[0];

	int sum = 0;

	for(int i=0; i<length; i++){
		sum += vetor[i];

		res = max(sum,res);

		if(sum < 0)
			sum=0;
	}

	return res;
}

int max2d(){
	int temp[n];
	int res = INT_MIN;
	for(int i=0; i<n; i++){
		memset(temp, 0, sizeof(temp));
		for(int j=i;j<n;j++){
			for(int k=0; k<n; k++){
				temp[k] += mat[k][j];
			}

			int sum = kadane(temp, n);
			res = max(res,sum);
		}
	}
	return res;
}

int main(){

	scanf("%d",&n);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d",&mat[i][j]);
		}
	}

	printf("%d\n", max2d());

	return 0;
}
