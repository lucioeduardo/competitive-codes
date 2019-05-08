#include <bits/stdc++.h>
using namespace std;

int g[105][105];
int n, temp[105];

int kadane() {

    int ans = temp[0];
    int curr= 0;

    for(int i=1; i<n; ++i) {
        curr += temp[i];
        ans = max(curr, ans);
        curr = max(curr, 0);
    }

    return ans;
}

int kadane2d() {

    int ans = INT_MIN;

    for(int l=0; l<n; ++l) {
        memset(temp, 0, sizeof temp);

        for(int c=l; c<n; ++c) {
            for(int i=0; i<n; ++i)
                temp[i] += g[i][c];

           ans = max(ans, kadane());
        }

    }

    return ans;
}

int main() {

    while(scanf("%d",&n) != EOF) {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j)
                scanf("%d", &g[i][j]);
        }

        printf("%d\n", kadane2d());
    }

    return 0;
}