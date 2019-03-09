#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    while(cin >> n) {
        char grid[n][n];
        int answer = 0;

        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                cin >> grid[i][j];


        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] != '1') continue;

                int current = 1e7;
                for(int u=0; u<n; ++u) {
                    for(int v=0; v<n; ++v) {
                        if(grid[u][v] == '3')
                            current = min(current, abs(u-i) + abs(v-j));
                    }
                }
                answer = max(answer, current);
            }
        }

        cout << answer << endl;
    }

    return 0;
}