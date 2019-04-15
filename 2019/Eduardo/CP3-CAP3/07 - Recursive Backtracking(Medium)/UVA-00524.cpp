#include <bits/stdc++.h>
#define MAXN 40
using namespace std;

bool is_prime[MAXN], used[MAXN];
int n, solution[MAXN];

void calc_primes(){
	is_prime[1] = false;

	for(int i=2; i<MAXN; i++){
		is_prime[i] = true;
		for(int j=2; j*j <= i; j++){
			if(i % j == 0)
				is_prime[i]=false;
		}
	}
}

void solve(int idx){
	//printf("%d\n",idx);
	if(idx == n){
		printf("%d", solution[0]);
		for(int i=1; i<n; i++){
			printf(" %d",solution[i]);
		}
		printf("\n");
		return;
	}

	for(int i=2; i<=n; i++){
		bool flag;
		
		flag = is_prime[i + solution[idx-1]];
		if(idx == n-1)
			flag = flag & is_prime[i + 1];
		
		if(flag && !used[i]){
			used[i]=true;
			solution[idx]=i;
			solve(idx+1);
			used[i]=false;
		}
	}
}

int main(){
	int t=1;
	bool first = true;
	calc_primes();	
	
	while(scanf("%d",&n) != EOF){
		if(!first)
			printf("\n");
		first=false;
		solution[0]=1;
		used[1]=true;

		printf("Case %d:\n",t++);
		solve(1);
	}

	return 0;
}
