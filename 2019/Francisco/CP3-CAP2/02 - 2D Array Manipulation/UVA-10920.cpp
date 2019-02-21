#include <bits/stdc++.h>
#define MAXN 10000

using namespace std;

long long s, p, x, y, cont, r, c;

int main(){
	
	while(true){
	
		scanf("%lld %lld", &s, &p);

		if(s == 0 && p == 0) break;

        x=y=(s/2)+1;
        cont = 0, r=1, c=1;
        for(long long k=1; k<=s*s; k++){

            if(k == p){
                printf("Line = %lld, column = %lld.\n", x, y);
                break;
            }

            if(cont%4 == 0) x+=1;
            else if(cont%4 == 1) y-=1;
            else if(cont%4 == 2) x-=1;
            else if(cont%4 == 3) y+=1;

            if((k%r) == 0){
                cont++;
                c++;
            }

            if(c==2){
                r++;
                c=0;
            }
		
        }
	
	}

	return 0;
}

