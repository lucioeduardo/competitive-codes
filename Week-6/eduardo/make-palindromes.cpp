#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAXN 1010

using namespace std;

string a,b;
int len;

int dp[MAXN][MAXN];

int solve(int esq, int dir){
	
	if(esq >= dir)
		return 0;
	if(dp[esq][dir] != -1)
		return dp[esq][dir];
	
	int add = 1 + min(solve(esq, dir-1), solve(esq+1, dir));
	
	int n_add = 99999999;
	if(a[esq] == a[dir])
		n_add = solve(esq+1, dir-1);
		
	
	return dp[esq][dir] = min(add,n_add);
}

int main(){
	string s;
	
	while(cin>>s){
		a = s;
		len = s.length();
		
		for(int i=0; i<=len; i++)
			for(int j=0; j<=len; j++)
				dp[i][j]=-1;
	
		int res = solve(0,len-1);
		
		
		string res_s = string(" ", len+res);
		int esq = 0;
		int dir = len-1;
		int it_e=0;
		int it_d=len+res-1;
		
		
		while(it_e <= it_d){
			if(s[esq] == s[dir]){
				res_s[it_e++] = s[esq];
				res_s[it_d--] = s[esq];
				esq++;
				dir--;
			}else if(dp[esq][dir-1] < dp[esq+1][dir]){
				res_s[it_e++] = s[dir];
				res_s[it_d--] = s[dir];
				dir--;
			}else{
				res_s[it_e++] = s[esq];
				res_s[it_d--] = s[esq];
				esq++;
			}
		}

		cout << res << " " << res_s << endl;
	}
	
	return 0;
}
