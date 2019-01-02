// 10264 - The Most Potent Corner

#include <bits/stdc++.h>
using namespace std;

int memo[1<<15], w[1<<15];

int main()
{
    int n;
    while(cin >> n) {

        memset(memo, 0, sizeof memo);

        for(int i=0; i<(1<<n); ++i)
            cin >> w[i];

        for(int i=0; i<(1<<n); ++i) {
            for(int j=0; j<n; ++j)
                memo[i] += w[i ^ (1 << j)];
        }

        int answer = 0;

        for(int i=0; i<(1<<n); ++i) {
            for(int j=0; j<n; ++j)
                answer = max(answer, memo[i] + memo[i ^ (1 << j)]);
        }

        cout << answer << endl;
    }
}