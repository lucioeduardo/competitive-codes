#include <bits/stdc++.h>
#define MAXM 16
using namespace std;

struct piece{
	int left,right;
};

piece esq,dir,pieces[MAXM];
bool used[MAXM];
int n,m;


bool solve(int idx, int last_dir){
	if(idx == n)
		return last_dir == dir.left;
	
	bool ret = false;
	for(int i=0; i<m; i++){
		if(!used[i]){
			if(pieces[i].left == last_dir){
				used[i] = true;
				ret = ret || solve(idx+1, pieces[i].right);
				used[i] = false;
			}
			else if(pieces[i].right == last_dir){
				used[i] = true;
				ret = ret || solve(idx+1, pieces[i].left);
				used[i]=false;
			}
		}
	}

	return ret;
}


int main(){

	while(scanf("%d",&n) && n){
		scanf("%d",&m);

		int a,b;

		scanf("%d %d",&a,&b);
		esq = {a,b};

		scanf("%d %d",&a,&b);
		dir = {a,b};

		for(int i=0;i<m;i++){
			scanf("%d %d",&a,&b);

			pieces[i] = {a,b};
			used[i]=false;
		}

		printf("%s\n", solve(0,esq.right) ? "YES":"NO");

	}

	return 0;
}
