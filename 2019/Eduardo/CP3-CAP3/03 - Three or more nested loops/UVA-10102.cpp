#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;

int cell[MAXN][MAXN];



int main(){
	int n;

	while(scanf("%d ",&n) != EOF){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf("%c",&cell[i][j]);
			}
			getchar();
		}

		int res = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(cell[i][j] != '1') continue;
				int m = 9999999;

				for(int k=0; k<n; k++){
					for(int l=0; l<n; l++){
						if(cell[k][l] == '3'){
							int d = abs(i-k) + abs(j-l);
							m = min(m,d);	
						}
					}
				}

				res = max(res, m);

			}
		}

		printf("%d\n",res);

	}

	return 0;
}
