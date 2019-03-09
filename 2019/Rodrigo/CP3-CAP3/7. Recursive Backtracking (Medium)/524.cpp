#include <bits/stdc++.h>
using namespace std;

int n;
int current[20];
bitset<32> used;
vector<int> candidate[40];

bool isPrime(int x) {
    for(int i=2; i*i<=x; ++i)
        if(x%i == 0)
            return false;
    return true;
}

void precalc() {
    for(int i=1; i<=16; ++i) {
        for(int j=i + 1; j<=16; ++j)  {
            if((i&1) == (j&1) || !isPrime(i+j))
                continue;

            candidate[i].push_back(j);
            candidate[j].push_back(i);
        }
    }
}

void backtrack(int id) {

    if(id > n) {
        if(candidate[current[n]][0] ^ 1)
            return ;

        for(int i = 1; i < n; ++i)
            printf("%d ", current[i]);
        printf("%d\n", current[n]);
    }

    for(auto &e : candidate[current[id - 1]]) {
        if(!used[e] && e <= n) {
            used.set(e); current[id] = e;
            backtrack(id + 1);
            used.reset(e); current[id] = 0;
        }
    }
}

int main() {

    int caseTest = 0;
    precalc();
    current[1] = 1;

    while(scanf("%d", &n) != EOF) {
        used.reset();
        used.set(1);

        if(caseTest)
            printf("\n");
        printf("Case %d:\n", ++caseTest);

        backtrack(2);
    }
    return 0;
}