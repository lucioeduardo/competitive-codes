#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    vector<int> v;

    while(scanf("%d", &x) != EOF)
        v.push_back(x);

    int n = v.size();
    int last, ans = 0;
    vector<int> lis[n];

    for(int i=0; i<n; ++i)
        lis[i].push_back(v[i]);

    for(int i=1; i<n; ++i) {

        for(int j=0; j<i; ++j) {
            if(v[j] < v[i] && lis[i].size() <= (lis[j].size() + 1)) {
                lis[i] = lis[j];
                lis[i].push_back(v[i]);
            }
        }

        int curr = lis[i].size();
        if(ans <= curr)
            ans = curr, last = i;
    }

    printf("%d\n-\n", ans);

    for(int i=0; i<lis[last].size(); ++i)
        printf("%d\n", lis[last][i]);

    return 0;
}