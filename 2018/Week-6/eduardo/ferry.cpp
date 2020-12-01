#include <cstdio>
#include <iostream>
#define MAXN 220
#define MAXF 10100

using namespace std;

int cars[MAXN], m, j;

int sum[MAXN];
string dp[MAXN][MAXF];

string solve(int i, int left){
	//printf("new-%d %d %d\n",i,sum[i],left);
	//cout << dp[i][left] << endl;

	
	if(dp[i][left] != "X") return dp[i][left];
	if(i >= j) return "";
	
	int right = sum[i]-left;
	//printf("%d %d\n", left, right);
	string res_r="", res_l="";
	
	if(right + cars[i] <= m)
		res_r = "s" + solve(i+1, left);
	if(left + cars[i] <= m)
		res_l = "p" + solve(i+1, left+cars[i]);
		
	return dp[i][left] = res_r.length() > res_l.length() ? res_r : res_l;
}

int main(){
	int t;
	
	scanf("%d",&t);
	
	
	
	for(int i=0; i<t; i++){
		
		for(int k=0; k<MAXN; k++)
		for(int l=0; l<MAXF; l++)
			dp[k][l] = "X";
		
		scanf("%d",&m);
		m*=100;
		int l;
		j = 0;
		sum[0]=0;
		while(scanf("%d",&l) && l!=0){
			if(j < MAXN) cars[j] = l;
			if(j>0)sum[j] = cars[j-1] + sum[j-1];
			//if(j>1) sum[j] += sum[j-2];
			j++; 
		}
		
		/*for(int k=0; k<j; k++){
			printf("sum[%d]=%d\n",k,sum[k]);
		}*/
		
		string res = solve(0,0);
		
		printf("%d\n",(int)res.length());
		for(size_t k=0; k<res.length(); k++){
			if(res[k] == 'p')
				printf("port\n");
			else
				printf("starboard\n");
		}
		
		if(i < t-1) printf("\n");
		
	}
	
	
	return 0;
}
