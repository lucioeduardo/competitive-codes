#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n, m, x, v[MAXN];

bool search(int target) {

    for(int i=0; i<n; ++i) {
        if(v[i] < target)
            continue;
        if(v[i] == target)
            --target;
        else
            return false;
    }
    return true;
}

int solve() {

    int mid, ans = 0;
    int lo = 0;
    int hi = 1e7;

    while(lo <= hi) {
        mid = (lo + hi) / 2;

        if(search(mid))
            hi = mid - 1, ans = mid;
        else
            lo = mid + 1;
    }

    return ans;

}

int main() {

    int test;
    scanf("%d", &test);

    for(int t=1; t<=test; ++t) {
        scanf("%d", &n);
        int last = 0;

        for(int i=0; i<n; ++i) {
            scanf("%d", &x);
            v[i] = fabs(last - x);
            last = x;
        }
        
        printf("Case %d: %d\n", t, solve());
    }
}