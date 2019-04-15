#include <bits/stdc++.h>
#define MAXP 20
using namespace std;

int bars[MAXP];

int main(){
	int t;

	scanf("%d",&t);

	while(t--){
		int n,p;

		scanf("%d %d",&n,&p);
	
		for(int i=0; i<p; i++) scanf("%d",&bars[i]);

		bool flag=false;

		for(int i=0; i < (1<<p); i++){
			int sum=0;
			for(int j=0; j<p; j++){
				if(i & (1<<j))
					sum += bars[j];
			}

			if(sum == n){
				flag = true;
				break;
			}
		}
		printf("%s\n", flag? "YES":"NO");

	}


	return 0;
}
