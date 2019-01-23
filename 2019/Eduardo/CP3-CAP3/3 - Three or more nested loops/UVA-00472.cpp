#include <bits/stdc++.h>
#define MAXN 15
using namespace std;

int val[MAXN];

int main(){
	int n;
	bool flag=false;

	
	while(scanf("%d",&n) && n){
		if(flag) printf("\n");
		flag=true;
		
		for(int i=0; i<n; i++){
			scanf("%d",&val[i]);
		}

		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++)
				for(int k=j+1; k<n; k++)
					for(int l=k+1; l<n; l++)
						for(int m=l+1; m<n; m++)
							for(int o=m+1; o<n; o++)
								printf("%d %d %d %d %d %d\n",val[i],val[j],val[k],val[l],val[m],val[o]);
	}
	

	return 0;
}
