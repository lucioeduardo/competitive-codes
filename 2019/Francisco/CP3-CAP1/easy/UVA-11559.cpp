#include <bits/stdc++.h>
#define INF 999999

using namespace std;

int main(){

    int n, b, h, w;

    while(scanf("%d %d %d %d", &n, &b, &h, &w) != EOF){
        int price, week, res=INF;
        
        for(int i = 0; i < h; i++){
            
            scanf("%d", &price);
            
            for(int j = 0; j < w; j++){
                
                scanf("%d", &week);
                
                if(week >= n && n*price<=b){
                    if(n*price < res){
                        res = n*price;
                    }
                
                }
            
            }
        }

        if(res != INF){
            printf("%d\n", res);
        } else{
            printf("stay home\n");
        }
    }

    return 0;
}