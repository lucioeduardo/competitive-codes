#include <bits/stdc++.h>
using namespace std;

int t, v[50];
int answer, best;

void solve(int ind, int sum, int mask = 0) {
    if(sum < 0) return;

    if(ind == t) {
        if(best <= sum)
            return ;
        answer = mask;
        best = sum;
        return ;
    }

    solve(ind + 1, sum - v[ind], mask | (1 << ind));
    solve(ind + 1, sum, mask);
}

int main() {
    int N;
    while(cin >> N) {
        cin >> t;

        for(int i=0; i<t; ++i)
            cin >> v[i];

        answer = 0, best = 1e8;
        solve(0, N);
        
        int sum = 0;
        for(int i=0; i<21; ++i)
            if(answer & (1<<i))
                cout << v[i] << " ";

        cout << "sum:" << N - best << endl;
    }
    return 0;
}