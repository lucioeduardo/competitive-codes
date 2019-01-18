#include <bits/stdc++.h>
#define MAXN 10005

using namespace std;

int main(){

    int t, n;
    int cria[MAXN];

    scanf("%d", &t);

    int i = 1;
    while(i <= t){
        int res = 0;

        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            scanf("%d\n", &cria[i]);

            if(cria[i] > res)
                res = cria[i];
        }

        printf("Case %d: %d\n", i, res);
        i++;
    }

    return 0;
}