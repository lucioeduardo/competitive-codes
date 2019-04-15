#include <bits/stdc++.h>
using namespace std;

int main(){

	for(int a=1; a<300; a++){
		for(int b=a; b < 800; b++){
			for(int c=b; c <1000; c++){
				

				if(a*b*c == 1000000) continue;

				int d = ((a+b+c)*1000000)/(a*b*c-1000000);

				if((d < 0) || (d < c) || (a+b+c+d > 2000)) continue;

				if((a+b+c+d)*1000000 == a*b*c*d){
					printf("%.2lf %.2lf %.2lf %.2lf\n",a/100.0,b/100.0,c/100.0,d/100.0);
				}
			}
		}
	}

	return 0;
}
