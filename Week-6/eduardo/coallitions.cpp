#include <cstdio>
#include <algorithm>
#define MAXN 110
#define MAXV 5050
using namespace std;

int stocks[MAXN], n;
int dp[MAXN][MAXV];

int solve(int i, int v){
	if(v > 5000)
		return v;
	if(i > n)
		return 99999;
	if(dp[i][v] != -1)
		return dp[i][v];
	
	return dp[i][v] = min(solve(i+1,v), solve(i+1, v + stocks[i]));
}

int main(){
	int x;
	
	while(scanf("%d %d",&n,&x) && !(n==0 && x==0)){
		for(int i=1; i<=n; i++){
			int a,b;
			scanf("%d.%d",&a,&b);
			int v = 100*a + b;
			
			stocks[i]=v;
		}
		
		for(int i=1; i<=n; i++)
			for(int j=0; j<MAXV; j++)
				dp[i][j]=-1;
		
		swap(stocks[x],stocks[1]);
		double res = 100*stocks[1];
		res /= (double)solve(2,stocks[1]);
				
		printf("%.2lf\n", res);
	}
}
