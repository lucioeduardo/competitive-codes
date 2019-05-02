#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, a, b, cont;

    while(true){
        scanf("%d", &n);

        if(n == 0) break;

        a=0, b=0, cont=1;
        for(int i = 0; i < (int)log2(n)+1; i++){
            if(n & (1 << i)){
                if(cont%2) a ^= (1 << i);
                else b ^= (1 << i);
                cont++;
            }
        }

        printf("%d %d\n", a, b);
    }

    return 0;
}
