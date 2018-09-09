#include <cstdio>
#include <algorithm>
#define MAXM 50
#define MAXS 300
using namespace std;

int m,s,conv[MAXM], tech[MAXM];
int value=0, dp[MAXM][MAXS][MAXS];

int solve(int i, int sum_tech, int sum_conv){
	int sum = sum_tech*sum_tech + sum_conv*sum_conv;
	
	if(sum > value)
		return 9999;
	if(sum == value)
		return 0;
	if(i > m-1)
		return 9999;
	if(dp[i][sum_tech][sum_conv] != -1)
		return dp[i][sum_tech][sum_conv];
	
	int com = 1 + solve(i, sum_tech + tech[i], sum_conv + conv[i]);
	int sem = solve(i+1, sum_tech, sum_conv);
	
	
	return dp[i][sum_tech][sum_conv] = min(com,sem);
}

int main(){
	int n;
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d %d",&m,&s);
		value = s*s;
		
		for(int j=0; j<=m; j++)
			for(int k=0; k<=s; k++)
				for(int l=0; l<=s; l++)
					dp[j][k][l]=-1;
		
		for(int i=0; i<m; i++){
			scanf("%d %d",&conv[i], &tech[i]);
		}
		
		int res = solve(0,0,0);
		
		if(res > 3000)
			printf("not possible\n");
		else
			printf("%d\n",res);
		
	}
	
	
	
	return 0;
}
