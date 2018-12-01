#include <bits/stdc++.h>
#define MAXN 20
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int i=0; i<t; i++){
		int a,b;
		scanf("%d %d",&a, &b);
		
		if(a > b) printf(">\n");
		else printf("%s\n", a == b ? "=" : "<");
	}
    return 0;
}

