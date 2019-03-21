#include <bits/stdc++.h>
using namespace std;

int n, m;

bitset<105> black;
bitset<105> seen;
bitset<105> color;
vector<int> graph[105];

void solve(int u) {

    if(u > n) {
        int sum = color.count();

        if(black.count() < sum)
            black = color;
        return ;
    }

    bool canBlack = true;

    for(auto &e: graph[u]) {
        if(color[e]) {
            canBlack = false;
            break;
        }
    }
    
    solve(u + 1);

    if(canBlack) {
        color[u] = 1;
        solve(u + 1);
        color[u] = 0;
    }
}

int main() {

    int t; cin >> t;
    int u, v;
    
    while(t--) {
        cin >> n >> m;

        for(int i=0; i<m; ++i) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        seen.reset();
        color.reset();
        black.reset();

        solve(1);
        int answer = black.count();
        
        printf("%d\n", answer);

        for(int i=1; i<=n; ++i) {
            if(black[i]) {
                if(--answer) printf("%d ", i);
                else printf("%d\n", i);
            }
        }

        for(int i=1; i<=n; ++i)
            graph[i].clear();
    }

    return 0;
}
