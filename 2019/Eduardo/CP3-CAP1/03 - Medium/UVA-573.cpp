#include <bits/stdc++.h>
using namespace std;

int main(){
	int h,u,d,f;
	
	while(scanf("%d %d %d %d",&h,&u,&d,&f) && h){
		double v_day = u;
		double w_h = 0;
		double ft = ((double)u*f)/100.0;
		
		
		int res = 0;
		
		while(++res){
			w_h += v_day;
						
			if(w_h > h)
				break;
			
			w_h -= d;
			
			if(w_h < 0)
				break;
			
			v_day -= ft;
			v_day = max(v_day, 0.0);
		}
		if(w_h > h)
			printf("success on day %d\n",res);
		else printf("failure on day %d\n", res);
	}
	
    return 0;
}
