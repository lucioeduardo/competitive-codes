#include <cstdio>
#define MAXM 55
#define M 1000000007
#define ll long long

int n,m;
ll matriz[MAXM][MAXM], res[MAXM][MAXM], mult[MAXM][MAXM];

void mult_matrix(ll a[MAXM][MAXM], ll b[MAXM][MAXM]){
	
	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			ll val = 0;
			
			for(int k=0; k<m; k++){
				val += ((a[i][k] * b[k][j]) % M);
				
			}
			
			mult[i][j]=(val % M);
		}
	}
	
	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			a[i][j] = mult[i][j];
		}
	}
}

void pow_matrix(int n){
	while(n > 0){
		if(n % 2)
			mult_matrix(res,matriz);
		mult_matrix(matriz,matriz);
		n/=2;
	}
}

int main(){
	int t;
	
	scanf("%d",&t);
	
	for(int i=0;i<t;i++){
		scanf("%d %d",&m,&n);
		
		for(int j=0;j<m;j++){
			for(int k=0; k<m; k++){
				scanf("%lld",&matriz[j][k]);
				res[j][k]= (j == k ? 1 : 0);
			}
		}
		
		pow_matrix(n);
		
		for(int i=0; i<m; i++){
			printf("%lld",res[i][0]);
			for(int j=1; j<m; j++){
				printf(" %lld",res[i][j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}
