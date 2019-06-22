#include <bits/stdc++.h>
#define MAXN 1000100
using namespace std;

int values[MAXN], len=0, previous[MAXN], stacks[MAXN], st_id[MAXN], st_len=0;

void lis_print(int idx){
	if(idx < 0) return;
	if(idx > 0)
		lis_print(previous[idx]);
	printf("%d\n",values[idx]);
}

int main(){
	int v;

	while(scanf("%d",&v) != EOF){
		values[len++]=v;

		int idx = lower_bound(stacks,stacks + st_len, v) - stacks;
		st_id[idx] = len-1;
		stacks[idx]= v;
		previous[len-1] = idx > 0 ? st_id[idx-1] : -1;
		if(idx == st_len){
			st_len++;
		}

		//printf("=== %d %d %d\n", idx, st_id[idx], previous[len-1]);
	}

	printf("%d\n-\n", st_len);
	lis_print(st_id[st_len-1]);
	return 0;
}
