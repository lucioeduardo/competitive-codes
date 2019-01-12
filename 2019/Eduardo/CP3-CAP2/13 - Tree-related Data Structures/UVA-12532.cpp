#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int value[MAXN], tree[MAXN*4];

void build(int no, int i, int j){
	if(i == j)
		tree[no]=value[i];
	else{
		int meio = (i+j)/2;
		int left=2*no, right=left+1;
		
		build(left, i, meio);
		build(right, meio+1, j);
		
		tree[no] = tree[left]*tree[right];
	}
}

void update(int no, int i, int j, int idx, int v){
	if(i > idx || j < idx) return;
	
	if(i == j){
		tree[no] = v;
	}else{
		int meio = (i+j)/2;
		int left=2*no, right=left+1;
		
		update(left, i, meio, idx, v);
		update(right, meio+1, j, idx, v); 
		
		tree[no] = tree[left]*tree[right];
	}
}

int find(int no, int i, int j, int a, int b){
	if(i > b || j < a) return 1;
	
	if(i>=a && j<=b){
		return tree[no];
	}
	
	int meio = (i+j)/2;
	int left=2*no, right=left+1;

	int v_left = find(left, i, meio, a, b);
	int v_right = find(right, meio+1, j, a, b);
	
	return v_left*v_right;
}

int main(){
	int n,k;
	
	while(scanf("%d %d ",&n,&k) != EOF){
		for(int i=1;i<=n;i++){
			scanf("%d ",&value[i]);
			if(value[i] != 0) value[i] = value[i] < 0 ? -1 : 1;
		}
		
		build(1,1,n);
		
		for(int i=0; i<k; i++){
			char op;
			int a,b;
			scanf("%c %d %d ",&op,&a,&b);
			
			
			if(op == 'C'){
			if(b != 0) b = b < 0 ? -1 : 1;

				update(1,1,n,a,b);
			}else{
				int res = find(1,1,n,a,b);
				
				if(res == 0) printf("0");
				else printf("%c", res > 0 ? '+' : '-');
			}
			
			
		}
		printf("\n");
	}
	return 0;
}
