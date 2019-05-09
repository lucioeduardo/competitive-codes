#include <bits/stdc++.h>
using namespace std;

int test, n, m, k;
int strip[105][105], temp[105];

typedef struct data {
    int area, sum;
    data() { sum = area = 0; }
} data;

data kadane(int l, int r) {

    data ans;
    int sum = 0;
    int up = 0;

    for(int i=0; i<n; ++i)
    {
        sum += temp[i];
        while(sum > k)
            sum -= temp[up++];

        int area = (r - l + 1) * (i - up + 1);

        if(ans.area < area)
            ans.sum = sum, ans.area = area;
        if(ans.area == area && ans.sum > sum)
            ans.sum = sum, ans.area = area;
    }

    return ans;
}

data kadane2d() {

    data ans;

    for(int l=0; l<m; ++l) {
        memset(temp, 0, sizeof temp);

        for(int r=l; r<m; ++r) {
            for(int i=0; i<n; ++i)
                temp[i] += strip[i][r];

            data curr = kadane(l, r);
            if(ans.area < curr.area)
                ans = curr;
            if(ans.area == curr.area && ans.sum > curr.sum)
                ans = curr;
        }
    }

    return ans;
}

int main() {
    scanf("%d", &test);

    for(int t=1; t<=test; ++t) {
        scanf("%d %d %d", &n, &m, &k);

        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                scanf("%d", &strip[i][j]);
        
        data ans = kadane2d();
        printf("Case #%d: %d %d\n", t, ans.area, ans.sum);
    }
    return 0;
}