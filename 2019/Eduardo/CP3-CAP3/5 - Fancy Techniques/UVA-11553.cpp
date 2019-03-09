#include <bits/stdc++.h>
#define MAXN 8
using namespace std;

int tab[MAXN][MAXN];
int choices[MAXN];

int main(){
	int t;

	scanf("%d",&t);

	

	while(t--){
		int n;

		scanf("%d",&n);

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				scanf("%d",&tab[i][j]);

		for(int i=0;i<n;i++)
			choices[i] = i;

		int res = -9999999;

		do{
			int qtd=0;
			for(int i=0;i<n;i++){
				qtd -= tab[i][choices[i]];
			}
			if(qtd > res) res=qtd;
		}while(next_permutation(choices,choices+n));


		printf("%d\n",-res);
	}

	return 0;
}
