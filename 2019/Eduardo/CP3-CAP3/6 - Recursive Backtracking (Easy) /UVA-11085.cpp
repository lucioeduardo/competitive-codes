#include <bits/stdc++.h>
#define N 8
using namespace std;

int pos[N];

bool isValid(int idx, int row){
	for(int i=0; i<idx; i++){
		if(pos[i] == row || abs(row - pos[i]) == abs(idx - i))
			return false;
	}
	return true;
}

int solve(int idx, int qtd){
	if(idx >= 8){
		return 0;
	}
	
	int res = 9999999;
	if(isValid(idx,pos[idx])){
		res = solve(idx+1, qtd);
	}
	
	int ini_pos = pos[idx];

	for(int i=1; i<=8; i++){
		if(isValid(idx,i)){
			pos[idx]=i;
			res = min(res, 1 + solve(idx+1, qtd+1));
		}
	}

	pos[idx]=ini_pos;

	return res;
}




int main(){
	int t=1;

	while(scanf("%d",&pos[0]) != EOF){
		for(int i=1; i<N;i++) scanf("%d",&pos[i]);
		printf("Case %d: %d\n",t++,solve(0,0));
	}

	return 0;
}
