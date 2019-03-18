#include <bits/stdc++.h>
using namespace std;

char x[8][8], y[8][8];
char output[8];
int k, answer;

bool solve(int ind) {

    if(ind == 5) {
        output[5] = '\0';
        return ++answer == k;
    }

    for(int c='A'; c<='Z'; ++c) {
        bool f = false, s = false;

        for(int i=0; i<6; ++i) {
            if(x[i][ind] == c)
                f = true;
            if(y[i][ind] == c)
                s = true;
        }
        
        if(f && s ) {
            output[ind] = c;

            if(solve(ind + 1))
                return true;
        }
    }

    return false;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d ", &k);
        for(int i=0; i<6; ++i)
            scanf("%s", x[i]);

        for(int i=0; i<6; ++i)
            scanf("%s", y[i]);
        
        answer = 0;
        printf("%s\n", solve(0) ? output : "NO");
    }
    return 0;
}