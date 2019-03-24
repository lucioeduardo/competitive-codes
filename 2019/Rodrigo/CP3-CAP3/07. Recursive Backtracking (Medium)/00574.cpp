#include <bits/stdc++.h>
using namespace std;

int t, n;
int v[20];
bool hasSolution;
map<vector<int>, bool> seen;

void backtrack(int id, int sum, int mask) {

    if(sum > t)
        return ;

    if(id == n) {
        if(sum != t)
            return ;
        
        int pos = -1;
        vector<int> path(__builtin_popcount(mask));

        for(int i=0; i<n; ++i)
            if(mask & (1<<i))
                path[++pos] = v[i];

        if(seen[path])
            return ;

        seen[path] = hasSolution = true;

        printf("%d",path[0]);
        for(int i=1; i<=pos; ++i)
            printf("+%d", path[i]);

        printf("\n");

        return ;
    }

    backtrack(id + 1, sum + v[id], mask | (1 << id));
    backtrack(id + 1, sum, mask);
}

int main() {
    
    while((cin >> t >> n) && n) {
        for(int i=0; i<n; ++i)
            scanf("%d", v + i);

        printf("Sums of %d:\n", t);
        hasSolution = false;
        backtrack(0, 0, 0);

        if(!hasSolution)
            printf("NONE\n");

        seen.clear();
    }
    return 0;
}