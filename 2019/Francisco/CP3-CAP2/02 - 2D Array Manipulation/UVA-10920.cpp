#include <bits/stdc++.h>

using namespace std;

long long s, p, x, y, c, k, cont;

int main(){
	
	while(true){
	
		scanf("%lld %lld", &s, &p);

		if(s == 0 && p == 0) break;

        x=y=(s/2)+1;
        
        c=1;
        while(true){
            if(c*c >= p) break;
            c+=2;
            x++;
            y++;
        }

        k = c-1;
        cont = (c*c)-p;
        
        if(k <= cont){
            y-=k;
            cont-=k;
        }else{
            y-=cont;
            cont=0;
        }

        if(k <= cont){
            x-=k;
            cont-=k;
        }else{
            x-=cont;
            cont=0;
        }

        if(k <= cont){
            y+=k;
            cont-=k;
        }else{
            y+=cont;
            cont=0;
        }

        if(k <= cont){
            x+=k;
            cont-=k;
        }else{
            x+=cont;
            cont=0;
        }
        
        printf("Line = %lld, column = %lld.\n", y, x);
	
	}

	return 0;
}

