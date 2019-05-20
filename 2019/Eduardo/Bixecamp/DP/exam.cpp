#include <bits/stdc++.h>
#define MAXD 35
#define MAXS 245
using namespace std;

int min_h[MAXD], max_h[MAXD], d;
int dp[MAXS][MAXD];
vector<int> res, at;

bool solve(int s, int idx){
	if(s < 0) return false;
	if(idx == d){
		res = at;
		return (s == 0);
	}
	if(dp[s][idx] != -1)
		return dp[s][idx];
	bool res = false;


	for(int i = min_h[idx]; i <= max_h[idx]; i++){
		
		at.push_back(i);
		res = res || solve(s-i, idx+1);
		at.pop_back();
	}

	return dp[s][idx] = res;
}

int main(){
	int sum;

	scanf("%d %d",&d,&sum);

	memset(dp,-1,sizeof(dp));

	for(int i=0; i<d; i++){
		scanf("%d %d",&min_h[i], &max_h[i]);
	}

	bool sol = solve(sum,0);

	if(sol){
		printf("YES\n%d",res[0]);

		for(int i=1; i<res.size(); i++){
			printf(" %d", res[i]);
		}
		printf("\n");
	}else{
		printf("NO");
	}

	return 0;
}
