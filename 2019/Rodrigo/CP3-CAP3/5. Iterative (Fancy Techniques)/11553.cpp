#include <bits/stdc++.h>
using namespace std;

int main() {

    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        int grid[n][n];
        int columns[n];

        for(int i=0; i<n; ++i) {
            columns[i] = i;

            for(int j=0; j<n; ++j)
                cin >> grid[i][j];
        }

        int answer = 1e7;
        do {
            int current = 0;
            for(int row=0; row<n; ++row)
                current += grid[row][columns[row]];
            answer = min(answer, current);
        } while(next_permutation(columns, columns + n));

        cout << answer << endl;
        
    }
    return 0;
}