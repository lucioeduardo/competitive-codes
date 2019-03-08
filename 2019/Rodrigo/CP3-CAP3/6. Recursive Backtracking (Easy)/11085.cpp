#include <bits/stdc++.h>
using namespace std;

int v[10], row[10];
int indexSolution;
int solution[100][10];

void backtracking(int c, int pd, int sd) {

    if(c == 9) {
        for(int i=1; i<=8; ++i)
            solution[indexSolution][i] = row[i];

        ++indexSolution;
        return;
    }

    for(int i=1; i<=8; ++i) {
        if(!row[i] && !(pd & (1 << ((i - c) + 8))) && !(sd & (1 << (i + c)))) {
            row[i] = c;
            backtracking(c + 1, pd | (1 << ((i - c) + 8)), sd | (1 << (i + c)));
            row[i] = 0;
        }
    }
}

int main() {

    int caseTest = 0;
    backtracking(1, 0, 0);

    while(cin >> v[1]) {
        memset(row, 0, sizeof row);

        for(int i=2; i<=8; ++i)
            cin >> v[i];
        
        int answer = 8;
        for(int i=0; i<indexSolution; ++i) {
            int current = 0;

            for(int j=1; j<=8; ++j)
                if(solution[i][j] ^ v[j])
                    ++current;

            answer = min(answer, current);
        }

        printf("Case %d: %d\n", ++caseTest, answer);
    }

    return 0;
}