#include <bits/stdc++.h>
using namespace std;

int g[505][505];

int main() {

    int n, m;

    while(scanf("%d %d", &n, &m) && n|m) {
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                scanf("%d", &g[i][j]);
        
        int q;
        scanf("%d", &q);

        while(q--) {
            int l, u;
            scanf("%d %d", &l, &u);

            int answer = 0;
            for(int i=0; i<n; ++i) {
                int *pos = lower_bound(g[i], g[i] + m, l);

                int q0 = pos - g[i];

                for(int j=answer; (q0+j) < m && (i+j) < n && g[i+j][q0+j] <= u; ++j)
                    answer = j+1;
            }
            printf("%d\n", answer);
            
        }
        printf("-\n");
    }
}