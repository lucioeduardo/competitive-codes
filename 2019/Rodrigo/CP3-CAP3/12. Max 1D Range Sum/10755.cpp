#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll grid[22][22][22];

int main() {
    int test;
    scanf("%d", &test);

    while(test--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        for(int i=0; i<a; ++i) {
            for(int j=0; j<b; ++j) {
                for(int k=0; k<c; ++k) {
                    ll x;
                    scanf("%Ld", &x);

                    if(i) x += grid[i-1][j][k];
                    if(j) x += grid[i][j-1][k];
                    if(k) x += grid[i][j][k-1];

                    if(i && j) x -= grid[i-1][j-1][k];
                    if(i && k) x -= grid[i-1][j][k-1];
                    if(j && k) x -= grid[i][j-1][k-1];
                    if(i && j && k) x += grid[i-1][j-1][k-1];

                    grid[i][j][k] = x;
                }
            }
        }

        ll answer = INT_MIN;

        for(int i=0; i<a; ++i) {
            for(int j=0; j<b; ++j) {
                for(int k=0; k<c; ++k) {

                    for(int it=i; it<a; ++it) {
                        for(int jt=j; jt<b; ++jt) {
                            for(int kt=k; kt<c; ++kt) {
                                ll curr = grid[it][jt][kt];

                                if(i) curr -= grid[i-1][jt][kt];
                                if(j) curr -= grid[it][j-1][kt];
                                if(k) curr -= grid[it][jt][k-1];

                                if(i && j) curr += grid[i-1][j-1][kt];
                                if(i && k) curr += grid[i-1][jt][k-1];
                                if(j && k) curr += grid[it][j-1][k-1];
                                if(i && j && k) curr -= grid[i-1][j-1][k-1];

                                answer = max(answer, curr);
                            }
                        }
                    }
                }
            }
        }
        printf("%Ld%s", answer, test ? "\n\n" : "\n");
    }
    return 0;
}