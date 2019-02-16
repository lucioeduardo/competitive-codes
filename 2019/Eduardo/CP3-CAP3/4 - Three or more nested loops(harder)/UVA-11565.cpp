#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;

	scanf("%d",&n);

	while(n--){
		int a,b,c;
		bool sol = false;

		scanf("%d %d %d",&a,&b,&c);

		for(int x=-30; x<=30 && !sol; x++){
			for(int y=-100; y<=100; y++){
				if(x == 0 || y == 0) continue;

				if(b % (y*x)) continue;

				int z = b/(y*x);

				int pX = x, pY = y;

				if(pX > pY) swap(pX, pY);

				if(x == y || x == z || y == z) continue;
			
				if((x + y + z == a) && (x*x + y*y + z*z) == c){
					sol = true;
					printf("%d %d %d\n",pX,pY,z);
					break;
				}
			}
		}

		if(!sol) printf("No solution.\n");
	}

	return 0;
}
