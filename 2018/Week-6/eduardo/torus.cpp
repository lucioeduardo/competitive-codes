#include <cstdio>
#include <algorithm>
#define MAXN 100
using namespace std;

int grid[MAXN][MAXN];

int kadane(int vet[], int n){
	int max_sum=-999999;
	int sum=0;
	
	for(int i=0; i<n; i++){
		sum += vet[i];
		
		max_sum = max(sum, max_sum);
		sum = max(0,sum);
	}
	
	return max_sum;
}

int max_circular_sum(int vet[], int n){
	int max_kadane = kadane(vet,n);
	
	int invert[n];
	int max_circ = 0;
	
	for(int i=0; i<n; i++){
		max_circ += vet[i];
		invert[i] = -vet[i];
	}
	
	max_circ += kadane(invert, n);
	
	
	return max(max_circ, max_kadane);
}

int max_rect_sum(int mat[MAXN][MAXN], int n){
	int max_sum = -9999999;
	
	int temp[n];
	
	
	for(int left=0; left<n; left++){
		for(int i=0;i<n;i++) temp[i]=0;
		
		/*for(int i=0; i<n; i++){
			temp[i] += mat[i][left];
		}
			
		max_sum = max(max_sum, max_circular_sum(temp, n));*/
		
		bool flag=true;
		
		for(int right=left; right!=left || flag; right++){
			//printf("l:%d r:%d\n",left,right);
			
			for(int i=0; i<n; i++){
				temp[i] += mat[i][right];
			}
			
			max_sum = max(max_sum, max_circular_sum(temp, n));
			if(right == left)
				flag=false;
			if(right == n-1)
				right=-1;
			
		}
	}


	return max_sum;
}


int main(){
	int t,n;
	
	scanf("%d",&t);
	
	for(int i=0; i<t; i++){
		scanf("%d",&n);
		
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				scanf("%d", &grid[j][k]);
			}
		}
		
		printf("%d\n",max_rect_sum(grid, n));
	}
	return 0;
}
