#include <bits/stdc++.h>
#define MAXN 1025000
using namespace std;

string pirates;
int tree[MAXN*3];
int lazy[MAXN*3];

void op(int no,int i, int j, int v){
	if(v == 1) tree[no] = 0;
	else if(v==2) tree[no] = (j-i+1);
	else tree[no] = (j-i+1)-tree[no];
}

int find(int no, int i, int j, int a, int b){
	int meio = (i+j)/2;
	int left = 2*no, right=left+1;
	
	if(lazy[no]){
		op(no,i,j,lazy[no]);
		
		if(i != j){
			int v = lazy[no];
			lazy[left] =  v == 3 ? 3-lazy[left] : v;
			lazy[right] =  v == 3 ? 3-lazy[right] : v;
		}
		lazy[no] = 0;
	}
	
	if(i > b || j < a) return 0;
	
	
	if(i>=a && j<=b){
		return tree[no];
	}else{
		int v_l = find(left, i, meio, a, b);
		int v_r = find(right, meio+1, j, a, b);
		
		return v_l + v_r;
	}
}

void update(int no, int i, int j, int a, int b, int v){
	int meio = (i+j)/2;
	int left = 2*no, right=left+1;
		
	if(lazy[no]){
		op(no,i,j,lazy[no]);
		
		if(i != j){
			int k = lazy[no];
			lazy[left] =  k == 3 ? 3-lazy[left] : k;
			lazy[right] =  k == 3 ? 3-lazy[right] : k;
		}
		lazy[no] = 0;
	}
	
	if(i > b || j < a) return;
	
	if(i>=a && j<=b){
		op(no,i,j, v);
		
		if(i != j){
			lazy[left] =  v == 3 ? 3-lazy[left] : v;
			lazy[right] =  v == 3 ? 3-lazy[right] : v;
		}
	}
	else{
		update(left, i, meio, a, b, v);
		update(right, meio+1, j, a, b, v);
		
		tree[no] = tree[left] + tree[right];
	}
	
}

void build(int no, int i, int j){
	lazy[no]=0;
	if(i == j){
		tree[no] = (pirates[i] == '1');
	}else{
		int meio = (i+j)/2;
		int left = 2*no, right=left+1;
		
		build(left, i, meio);
		build(right, meio+1,j);
		
		tree[no] = tree[left] + tree[right];
	}
}


int main(){
	int t,m;
	 
	scanf("%d ",&t);
	
	for(int j=1;j<=t;j++){
		printf("Case %d:\n",j);
		
		pirates.clear();
		pirates = " ";
		scanf("%d ", &m);
	
		for(int i=0;i<m; i++){
			int k;
			string s;
			
			scanf("%d ", &k);
			cin>>s;
			
			while(k--)
				pirates += s;
		}

		int n = pirates.length()-1;
		
		build(1,1,n);
		
		int q,q_i=1;
		
		scanf("%d ",&q);
				
		while(q--){
			char c;
			int a, b;
			
			scanf("%c %d %d ",&c,&a,&b);
			
			a++;b++;
		
			if(c == 'F') update(1,1,n,a,b,2);
			if(c == 'E') update(1,1,n,a,b,1);
			if(c == 'I') update(1,1,n,a,b,3);
			if(c == 'S') printf("Q%d: %d\n", q_i++, find(1,1,n,a,b));
		}
	}

	return 0;
}
