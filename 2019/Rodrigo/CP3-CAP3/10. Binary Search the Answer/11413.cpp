#include <bits/stdc++.h>
using namespace std;

int n, m;
int vessel[1010];

int binarySearch(int pos, int target) {
    int lo = pos;
    int hi = n;
    int mid, ans = 0;

    while(lo <= hi) {
        mid = (lo + hi) / 2;

        if(vessel[mid] < target)
            lo = mid + 1, ans = mid;
        else if(vessel[mid] > target)
            hi = mid - 1;
        else
            return mid;
    }

    return ans;
}

int main() {
    
    while(scanf("%d %d", &n, &m) != EOF) {

        for(int i=1; i<=n; ++i) {
            scanf("%d", vessel + i);
            vessel[i] += vessel[i - 1];
        }

        int mid, ans = 0;
        int lo = 1;
        int hi = vessel[n];

        while(lo <= hi) {
            mid = (lo + hi) / 2;
            
            int i, pos = 0;

            for(i=0; i<m; ++i) {
                int target = mid + vessel[pos];
                pos = binarySearch(1, target);
            }

            if(pos < n)
                lo = mid + 1;
            else
                hi = mid - 1, ans = mid;
        }
        printf("%d\n", ans);
    }


    return 0;
}