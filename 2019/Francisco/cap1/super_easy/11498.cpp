// UVA - 11498 - Division of Nlogonia
#include <bits/stdc++.h>

using namespace std;

int main(){

    int k, m, n, x, y;

    do{
        scanf("%d", &k);

        if(!k) break;

        scanf("%d %d", &n, &m);

        for(int i = 0; i < k; i++){
            scanf("%d %d", &x, &y);

            if(x == n || y == m) printf("divisa\n");
            else if(x < n && y > m) printf("NO\n");
            else if(x > n && y > m) printf("NE\n");
            else if(x > n && y < m) printf("SE\n");
            else if(x < n && y < m) printf("SO\n");
        }

    } while(k != 0);

    return 0;
}