#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct no{
	int left, right, res;
};

no tree[MAXN*3];
int val[MAXN];

void build(int node, int i, int j){
	if(i == j){
		tree[node].left = tree[node].right = tree[node].res = 1;
	}else{
		int meio = (i+j)/2;
		int l = 2*node, r = l+1;
		
		build(l, i, meio);
		build(r, meio+1,j);
		
		if(tree[l].left == (meio-i+1) && val[meio+1] == val[i]){
			tree[node].left = tree[l].left + tree[r].left;
		}else tree[node].left = tree[l].left;
		
		if(tree[r].right == (j - meio) && val[meio] == val[j])
			tree[node].right = tree[l].right + tree[r].right;
		else
			tree[node].right = tree[r].right;
		
		tree[node].res=0;
		
		if(val[meio] == val[meio+1])
			tree[node].res = tree[l].right + tree[r].left;
		
		tree[node].res = max(tree[node].res, max(tree[l].res, tree[r].res));
	}
}

no find(int node, int i, int j, int a, int b){
	if(i>b || j<a) return {0,0,0};
	
	if(i >= a && j <= b){
		return tree[node];
	}else{
		int meio = (i+j)/2;
		int l=2*node, r=l+1;
		
		no r_left = find(l, i, meio, a, b);
		no r_right = find(r, meio+1, j, a, b);
		no result;
		
		if(r_left.left == (meio-i+1) && val[meio+1] == val[i]){
			result.left = r_left.left + r_right.left;
		}else result.left = r_left.left;
		
		if(r_right.right == (j - meio) && val[meio] == val[j])
			result.right = r_left.right + r_right.right;
		else
			result.right = r_right.right;
			
		
		result.res=0;
		if(val[meio] == val[meio+1])
			result.res = r_left.right + r_right.left;
		
		result.res = max(result.res, max(r_left.res, r_right.res));
				
		return result;
	}
}

int main(){
	int n, q;
	
	while(scanf("%d",&n) && n){
		scanf("%d",&q);
	
		for(int i=1; i<=n; i++)
			scanf("%d",&val[i]);
		
		build(1,1,n);
		
		for(int i=0; i<q; i++){
			int a,b;
			scanf("%d %d",&a,&b);
			
			no sol = find(1,1,n,a,b);
			
			printf("%d\n", sol.res);
		}
		
	}
	

	return 0;
}
