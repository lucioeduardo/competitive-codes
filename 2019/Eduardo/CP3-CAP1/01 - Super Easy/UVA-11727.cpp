#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		
		if(a < b) swap(a,b);
		if(b < c) swap(b,c);
		if(a < b) swap(a,b);
		
		printf("Case %d: %d\n",i+1,b);
	}
    return 0;
}
