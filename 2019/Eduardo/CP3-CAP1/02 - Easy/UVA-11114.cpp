#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

double deprec[MAXN];
int month[MAXN];
int main(){
	int a,d;
	double b,c;
	
	while(scanf("%d %lf %lf %d",&a,&b,&c,&d) && a >= 0){
		int res = 0;
		double car_v = c+b;
		double p_m = c/a;
		bool flag=false;
		
		for(int i=0; i<d; i++){
			scanf("%d %lf",&month[i], &deprec[i]);
		}
		
		month[d] = 9999;
		
		for(int i=0; i<d; i++){
			while(res < month[i+1]){
				car_v *= (1-deprec[i]);
				if(car_v > (c - res*p_m)){
					flag = true;
					break;
				}
				
				res++;
			}
			if(flag) break;
		}
				
		
		if(res == 1) printf("1 month\n");
		else printf("%d months\n",res);
		
	}
    return 0;
}
